#include <graphene/plugins/database_api/api_objects/proposal_api_object.hpp>

namespace graphene { namespace plugins { namespace database_api {

    proposal_api_object::proposal_api_object(const graphene::chain::proposal_object& p)
        : author(p.author),
          title(graphene::chain::to_string(p.title)),
          memo(graphene::chain::to_string(p.memo)),
          expiration_time(p.expiration_time),
          review_period_time(p.review_period_time),
          proposed_operations(p.operations()),
          required_active_approvals(p.required_active_approvals.begin(), p.required_active_approvals.end()),
          available_active_approvals(p.available_active_approvals.begin(), p.available_active_approvals.end()),
          required_master_approvals(p.required_master_approvals.begin(), p.required_master_approvals.end()),
          available_master_approvals(p.available_master_approvals.begin(), p.available_master_approvals.end()),
          required_regular_approvals(p.required_regular_approvals.begin(), p.required_regular_approvals.end()),
          available_regular_approvals(p.available_regular_approvals.begin(), p.available_regular_approvals.end()),
          available_key_approvals(p.available_key_approvals.begin(), p.available_key_approvals.end()) {
    }

}}} // graphene::plugins::database_api