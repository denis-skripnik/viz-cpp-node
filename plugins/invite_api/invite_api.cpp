#include <boost/program_options/options_description.hpp>
#include <graphene/plugins/invite_api/invite_api.hpp>
#include <graphene/chain/index.hpp>
#include <graphene/chain/chain_objects.hpp>
#include <graphene/chain/invite_objects.hpp>
#include <graphene/api/invite_api_object.hpp>

#define CHECK_ARG_SIZE(_S)                                 \
   FC_ASSERT(                                              \
       args.args->size() == _S,                            \
       "Expected #_S argument(s), was ${n}",               \
       ("n", args.args->size()) );

#define CHECK_ARG_MIN_SIZE(_S, _M)                         \
   FC_ASSERT(                                              \
       args.args->size() >= _S && args.args->size() <= _M, \
       "Expected #_S (maximum #_M) argument(s), was ${n}", \
       ("n", args.args->size()) );

#define GET_OPTIONAL_ARG(_I, _T, _D)   \
   (args.args->size() > _I) ?          \
   (args.args->at(_I).as<_T>()) :      \
   static_cast<_T>(_D)

#ifndef DEFAULT_VOTE_LIMIT
#  define DEFAULT_VOTE_LIMIT 10000
#endif

namespace graphene { namespace plugins { namespace invite_api {

    struct invite_api::impl final {
        impl(): database_(appbase::app().get_plugin<chain::plugin>().db()) {
        }

        ~impl() = default;

        graphene::chain::database& database() {
            return database_;
        }

        graphene::chain::database& database() const {
            return database_;
        }

    private:
        graphene::chain::database& database_;
    };

    void invite_api::plugin_startup() {
        wlog("invite_api plugin: plugin_startup()");
    }

    void invite_api::plugin_shutdown() {
        wlog("invite_api plugin: plugin_shutdown()");
    }

    const std::string& invite_api::name() {
        static const std::string name = "invite_api";
        return name;
    }

    invite_api::invite_api() = default;

    void invite_api::set_program_options(
        boost::program_options::options_description&,
        boost::program_options::options_description& config_file_options
    ) {
    }

    void invite_api::plugin_initialize(const boost::program_options::variables_map& options) {
        pimpl = std::make_unique<impl>();
        JSON_RPC_REGISTER_API(name());
    }

    invite_api::~invite_api() = default;

    DEFINE_API(invite_api, get_invites_list) {
        CHECK_ARG_MIN_SIZE(1, 1)
        auto status = args.args->at(0).as<uint16_t>();
        auto& db = pimpl->database();
        return db.with_weak_read_lock([&]() {
            const auto &idx = db.get_index<invite_index>().indices().get<by_status>();
            std::vector<int64_t> invites_list;
            auto itr = idx.lower_bound(status);
            while (itr != idx.end() &&
                   itr->status == status) {
                invites_list.emplace_back(itr->id._id);
                ++itr;
            }
            return invites_list;
        });
    }

    DEFINE_API(invite_api, get_invite_by_id) {
        CHECK_ARG_MIN_SIZE(1, 1)
        auto search_id = args.args->at(0).as<int64_t>();
        auto& db = pimpl->database();
        return db.with_weak_read_lock([&]() {
            const auto &idx = db.get_index<invite_index>().indices().get<by_id>();
            auto itr = idx.find(search_id);
            FC_ASSERT(itr != idx.end(), "Invite id not found.");
            invite_api_object result = invite_api_object(*itr);
            return result;
        });
    }

    DEFINE_API(invite_api, get_invite_by_key) {
        CHECK_ARG_MIN_SIZE(1, 1)
        auto search_key = args.args->at(0).as<public_key_type>();
        auto& db = pimpl->database();
        return db.with_weak_read_lock([&]() {
            const auto &idx = db.get_index<invite_index>().indices().get<by_invite_key>();
            auto itr = idx.find(search_key);
            FC_ASSERT(itr != idx.end(), "Invite key not found.");
            invite_api_object result = invite_api_object(*itr);
            return result;
        });
    }

} } } // graphene::plugins::invite_api
