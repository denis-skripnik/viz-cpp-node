#include <graphene/api/comment_api_object.hpp>

namespace graphene { namespace api {

    using namespace graphene::chain;

    comment_api_object::comment_api_object(const graphene::chain::comment_object &o, const graphene::chain::database &db)
        : id(o.id),
          parent_author(o.parent_author),
          parent_permlink(to_string(o.parent_permlink)),
          author(o.author),
          permlink(to_string(o.permlink)),
          last_update(o.last_update),
          created(o.created),
          active(o.active),
          last_payout(o.last_payout),
          depth(o.depth),
          children(o.children),
          children_rshares2(o.children_rshares2),
          net_rshares(o.net_rshares),
          abs_rshares(o.abs_rshares),
          vote_rshares(o.vote_rshares),
          cashout_time(o.cashout_time),
          total_vote_weight(o.total_vote_weight),
          curation_percent(o.curation_percent),
          consensus_curation_percent(o.consensus_curation_percent),
          payout_value(o.payout_value),
          shares_payout_value(o.shares_payout_value),
          curator_payout_value(o.curator_payout_value),
          beneficiary_payout_value(o.beneficiary_payout_value),
          author_rewards(o.author_rewards),
          net_votes(o.net_votes),
          root_content(o.root_content) {

        for (auto& route : o.beneficiaries) {
            beneficiaries.push_back(route);
        }
#ifndef IS_LOW_MEM
        auto& content = db.get_content_type(o.id);

        title = to_string(content.title);
        body = to_string(content.body);
        json_metadata = to_string(content.json_metadata);
#endif
    }

    comment_api_object::comment_api_object() = default;

} } // graphene::api