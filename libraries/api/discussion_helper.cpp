#include <graphene/api/discussion_helper.hpp>
#include <graphene/chain/account_object.hpp>
// #include <graphene/plugins/follow/follow_objects.hpp>
#include <graphene/chain/chain_objects.hpp>
#include <fc/io/json.hpp>
#include <boost/algorithm/string.hpp>


namespace graphene { namespace api {

    comment_metadata get_metadata(const comment_api_object &c) {

        comment_metadata meta;

        if (!c.json_metadata.empty()) {
            try {
                meta = fc::json::from_string(c.json_metadata).as<comment_metadata>();
            } catch (const fc::exception& e) {
                // Do nothing on malformed json_metadata
            }
        }

        std::set<std::string> lower_tags;

        std::size_t tag_limit = 5;
        for (const auto& name : meta.tags) {
            if (lower_tags.size() > tag_limit) {
                break;
            }
            auto value = boost::trim_copy(name);
            if (value.empty()) {
                continue;
            }
            boost::to_lower(value);
            lower_tags.insert(value);
        }

        meta.tags.swap(lower_tags);

        boost::trim(meta.language);
        boost::to_lower(meta.language);

        return meta;
    }


    boost::multiprecision::uint256_t to256(const fc::uint128_t& t) {
        boost::multiprecision::uint256_t result(t.high_bits());
        result <<= 65;
        result += t.low_bits();
        return result;
    }

    struct discussion_helper::impl final {
    public:
        impl() = delete;
        impl(graphene::chain::database& db):database_(db){}
        ~impl() = default;

        discussion create_discussion(const comment_object& o) const ;

        void select_active_votes(
            std::vector<vote_state>& result, uint32_t& total_count,
            const std::string& author, const std::string& permlink, uint32_t limit
        ) const ;

        void set_pending_payout(discussion& d) const;

        void set_url(discussion& d) const;

        graphene::chain::database& database() {
            return database_;
        }

        graphene::chain::database& database() const {
            return database_;
        }

        discussion get_discussion(const comment_object& c, uint32_t vote_limit) const;

    private:
        graphene::chain::database& database_;
    };

// get_discussion
    discussion discussion_helper::impl::get_discussion(const comment_object& c, uint32_t vote_limit) const {
        discussion d = create_discussion(c);
        set_url(d);
        set_pending_payout(d);
        select_active_votes(d.active_votes, d.active_votes_count, d.author, d.permlink, vote_limit);
        return d;
    }

    discussion discussion_helper::get_discussion(const comment_object& c, uint32_t vote_limit) const {
        return pimpl->get_discussion(c, vote_limit);
    }
//

// select_active_votes
    void discussion_helper::impl::select_active_votes(
        std::vector<vote_state>& result, uint32_t& total_count,
        const std::string& author, const std::string& permlink, uint32_t limit
    ) const {
        const auto& comment = database().get_comment(author, permlink);
        const auto& idx = database().get_index<comment_vote_index>().indices().get<by_comment_voter>();
        comment_object::id_type cid(comment.id);
        total_count = 0;
        result.clear();
        for (auto itr = idx.lower_bound(cid); itr != idx.end() && itr->comment == cid; ++itr, ++total_count) {
            if (result.size() < limit) {
                const auto& vo = database().get(itr->voter);
                vote_state vstate;
                vstate.voter = vo.name;
                vstate.weight = itr->weight;
                vstate.rshares = itr->rshares;
                vstate.percent = itr->vote_percent;
                vstate.time = itr->last_update;
                result.emplace_back(vstate);
            }
        }
    }

    void discussion_helper::select_active_votes(
        std::vector<vote_state>& result, uint32_t& total_count,
        const std::string& author, const std::string& permlink, uint32_t limit
    ) const {
        pimpl->select_active_votes(result, total_count, author, permlink, limit);
    }
//
// set_pending_payout
    void discussion_helper::impl::set_pending_payout(discussion& d) const {
        auto& db = database();

        const auto& props = db.get_dynamic_global_properties();
        asset pot = props.total_reward_fund;

        u256 total_r2 = to256(props.total_reward_shares2);

        if (props.total_reward_shares2 > 0) {
            auto vshares = d.net_rshares.value > 0 ? d.net_rshares.value : 0;

            u256 r2 = to256(vshares); //to256(abs_net_rshares);
            r2 *= pot.amount.value;
            r2 /= total_r2;

            u256 tpp = to256(d.children_rshares2);
            tpp *= pot.amount.value;
            tpp /= total_r2;

            d.pending_payout_value = asset(static_cast<uint64_t>(r2), pot.symbol);
            d.total_pending_payout_value = asset(static_cast<uint64_t>(tpp), pot.symbol);
        }

        if (d.parent_author != STEEMIT_ROOT_POST_PARENT) {
            d.cashout_time = db.calculate_discussion_payout_time(db.get<comment_object>(d.id));
        }

        if (d.body.size() > 1024 * 128) {
            d.body = "body pruned due to size";
        }
        if (d.parent_author.size() > 0 && d.body.size() > 1024 * 16) {
            d.body = "comment pruned due to size";
        }

        set_url(d);
    }

    void discussion_helper::set_pending_payout(discussion& d) const {
        pimpl->set_pending_payout(d);
    }
//
// set_url
    void discussion_helper::impl::set_url(discussion& d) const {
        const comment_api_object root(database().get<comment_object, by_id>(d.root_comment), database());

        d.root_title = root.title;
        d.url = "/@" + root.author + "/" + root.permlink;

        if (root.id != d.id) {
            d.url += "#@" + d.author + "/" + d.permlink;
        }
    }

    void discussion_helper::set_url(discussion& d) const {
        pimpl->set_url(d);
    }
//
// create_discussion
    discussion discussion_helper::impl::create_discussion(const comment_object& o) const {
        return discussion(o, database_);
    }

    discussion discussion_helper::create_discussion(const comment_object& o) const {
        return pimpl->create_discussion(o);
    }

    discussion_helper::discussion_helper(
        graphene::chain::database& db
    ) {
        pimpl = std::make_unique<impl>(db);
    }

    discussion_helper::~discussion_helper() = default;

//
} } // graphene::api
