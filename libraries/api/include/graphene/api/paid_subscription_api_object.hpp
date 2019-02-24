#ifndef CHAIN_PAID_SUBSCRIPTION_API_OBJ_H
#define CHAIN_PAID_SUBSCRIPTION_API_OBJ_H

#include <graphene/chain/paid_subscription_objects.hpp>
#include <graphene/chain/database.hpp>
#include <vector>

namespace graphene { namespace api {

    using namespace graphene::chain;
    using graphene::chain::paid_subscription_object;
    using graphene::chain::paid_subscribe_object;

    struct paid_subscribe_state {
        paid_subscribe_state(const paid_subscribe_object &o);
        paid_subscribe_state();

        paid_subscribe_object::id_type id;

        account_name_type subscriber;
        account_name_type creator;
        uint16_t level;
        share_type amount;
        uint16_t period;
        time_point_sec start_time;
        time_point_sec next_time;
        time_point_sec end_time;
        bool active = false;
        bool auto_renewal = false;
    };

    struct paid_subscription_state {
        paid_subscription_state(const paid_subscription_object &o, const database &db);
        paid_subscription_state();

        paid_subscription_object::id_type id;

        account_name_type creator;
        std::string url;
        uint16_t levels;
        share_type amount;
        uint16_t period;
        time_point_sec update_time;

        std::vector<account_name_type> active_subscribers;
        uint32_t active_subscribers_count = 0;
        share_type active_subscribers_summary_amount = 0;
        std::vector<account_name_type> active_subscribers_with_auto_renewal;
        uint32_t active_subscribers_with_auto_renewal_count = 0;
        share_type active_subscribers_with_auto_renewal_summary_amount = 0;
    };
} } // graphene::api

FC_REFLECT((graphene::api::paid_subscribe_state),(subscriber)(creator)(level)(amount)(period)(start_time)(next_time)(end_time)(active)(auto_renewal));

FC_REFLECT(
    (graphene::api::paid_subscription_state),
    (creator)(url)(levels)(amount)(period)(update_time)
    (active_subscribers)(active_subscribers_count)(active_subscribers_summary_amount)
    (active_subscribers_with_auto_renewal)(active_subscribers_with_auto_renewal_count)(active_subscribers_with_auto_renewal_summary_amount))

#endif //CHAIN_PAID_SUBSCRIPTION_API_OBJ_H
