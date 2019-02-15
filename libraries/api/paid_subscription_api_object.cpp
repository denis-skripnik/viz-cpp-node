#include <graphene/api/paid_subscription_api_object.hpp>

namespace graphene { namespace api {

    using namespace graphene::chain;
    using graphene::chain::paid_subscription_object;
    using graphene::chain::paid_subscribe_object;

    paid_subscribe_state::paid_subscribe_state(const graphene::chain::paid_subscribe_object &o)
        :  subscriber(o.subscriber),
           creator(o.creator),
           level(o.level),
           amount(o.amount),
           period(o.period),
           start_time(o.start_time),
           next_time(o.next_time),
           end_time(o.end_time),
           active(o.active),
           auto_renewal(o.auto_renewal) {
        }

    paid_subscribe_state::paid_subscribe_state() = default;

    paid_subscription_state::paid_subscription_state(const graphene::chain::paid_subscription_object &o, const graphene::chain::database &db)
        : creator(o.creator),
          url(to_string(o.url)),
          levels(o.levels),
          amount(o.amount),
          period(o.period),
          update_time(o.update_time) {
            const auto &idx = db.get_index<paid_subscribe_index>().indices().get<by_creator>();
            for (auto itr = idx.lower_bound(creator);
                 itr != idx.end() && (itr->creator == creator);
                 ++itr) {
                if(itr->active){
                    active_subscribers.push_back(itr->subscriber);
                    active_subscribers_count++;
                    active_subscribers_summary_amount+=itr->amount * itr->level;
                    if(itr->auto_renewal){
                        active_subscribers_with_auto_renewal.push_back(itr->subscriber);
                        active_subscribers_with_auto_renewal_count++;
                        active_subscribers_with_auto_renewal_summary_amount+=itr->amount * itr->level;
                    }
                }
            }
        }

    paid_subscription_state::paid_subscription_state() = default;

} } // graphene::api