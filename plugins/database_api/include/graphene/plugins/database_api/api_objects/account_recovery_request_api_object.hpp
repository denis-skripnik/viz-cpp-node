#ifndef CHAIN_ACCOUNT_RECOVERY_REQUEST_API_OBJ_HPP
#define CHAIN_ACCOUNT_RECOVERY_REQUEST_API_OBJ_HPP

#include <graphene/chain/account_object.hpp>

namespace graphene {
    namespace plugins {
        namespace database_api {
            using  graphene::chain::account_recovery_request_object;

            struct account_recovery_request_api_object {
                account_recovery_request_api_object(const graphene::chain::account_recovery_request_object &o) : id(o.id),
                        account_to_recover(o.account_to_recover), new_owner_authority(authority(o.new_owner_authority)),
                        expires(o.expires) {
                }

                account_recovery_request_api_object() {
                }

                account_recovery_request_object::id_type id;
                account_name_type account_to_recover;
                authority new_owner_authority;
                time_point_sec expires;
            };
        }
    }
}


FC_REFLECT((graphene::plugins::database_api::account_recovery_request_api_object),
           (id)(account_to_recover)(new_owner_authority)(expires))


#endif //CHAIN_ACCOUNT_RECOVERY_REQUEST_API_OBJ_HPP
