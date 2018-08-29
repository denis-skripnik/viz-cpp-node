#ifndef GOLOS_OWNER_AUTHORITY_HISTORY_API_OBJ_HPP
#define GOLOS_OWNER_AUTHORITY_HISTORY_API_OBJ_HPP

#include <graphene/chain/account_object.hpp>

namespace graphene {
    namespace plugins {
        namespace database_api {

            using protocol::authority;
            using graphene::protocol::account_name_type;
            using graphene::chain::owner_authority_history_object;

            struct owner_authority_history_api_object {
                owner_authority_history_api_object(const graphene::chain::owner_authority_history_object &o) : id(o.id),
                        account(o.account), previous_owner_authority(authority(o.previous_owner_authority)),
                        last_valid_time(o.last_valid_time) {
                }

                owner_authority_history_api_object() {
                }

                owner_authority_history_object::id_type id;

                account_name_type account;
                authority previous_owner_authority;
                time_point_sec last_valid_time;
            };
        }
    }
}

FC_REFLECT((graphene::plugins::database_api::owner_authority_history_api_object),
           (id)(account)(previous_owner_authority)(last_valid_time))
#endif //GOLOS_OWNER_AUTHORITY_HISTORY_API_OBJ_HPP
