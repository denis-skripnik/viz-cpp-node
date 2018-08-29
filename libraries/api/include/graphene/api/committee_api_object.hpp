#ifndef GOLOS_COMMITTEE_API_OBJ_H
#define GOLOS_COMMITTEE_API_OBJ_H

#include <graphene/chain/committee_objects.hpp>
#include <graphene/chain/database.hpp>
#include <vector>

namespace graphene { namespace api {

    using namespace graphene::chain;
    using graphene::chain::committee_request_object;
    using graphene::chain::committee_vote_object;

    struct committee_vote_state {
        committee_vote_state(const committee_vote_object &o);
        committee_vote_state();

        account_name_type voter;
        int16_t vote_percent = 0;
        time_point_sec last_update;
    };

    struct committee_api_object {
        committee_api_object(const committee_request_object &o/*, const database &db*/);
        committee_api_object();

        committee_request_object::id_type id;

        uint32_t request_id;

        std::string url;
        account_name_type creator;
        account_name_type worker;

        protocol::asset required_amount_min;
        protocol::asset required_amount_max;

        time_point_sec start_time;
        uint32_t duration;
        time_point_sec end_time;
        uint16_t status;
        uint32_t votes_count;
        time_point_sec conclusion_time;
        protocol::asset conclusion_payout_amount;
        protocol::asset payout_amount;
        protocol::asset remain_payout_amount;
        time_point_sec last_payout_time;
        time_point_sec payout_time;

        std::vector<committee_vote_state> votes;
    };
} } // graphene::api

FC_REFLECT((graphene::api::committee_vote_state),(voter)(vote_percent)(last_update));

FC_REFLECT(
    (graphene::api::committee_api_object),
    (id)(request_id)(url)(creator)(worker)(required_amount_min)(required_amount_max)
    (start_time)(duration)(end_time)(status)(votes_count)(conclusion_time)(conclusion_payout_amount)
    (payout_amount)(remain_payout_amount)(last_payout_time)(payout_time)(votes))

#endif //GOLOS_COMMITTEE_API_OBJ_H
