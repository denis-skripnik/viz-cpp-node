#ifndef CHAIN_MASTER_AUTHORITY_HISTORY_API_OBJ_HPP
#define CHAIN_MASTER_AUTHORITY_HISTORY_API_OBJ_HPP

#include <graphene/chain/account_object.hpp>

namespace graphene {
    namespace plugins {
        namespace database_api {

            using protocol::authority;
            using graphene::protocol::account_name_type;
            using graphene::chain::master_authority_history_object;

            struct master_authority_history_api_object {
                master_authority_history_api_object(const graphene::chain::master_authority_history_object &o) : id(o.id),
                        account(o.account), previous_master_authority(authority(o.previous_master_authority)),
                        last_valid_time(o.last_valid_time) {
                }

                master_authority_history_api_object() {
                }

                master_authority_history_object::id_type id;

                account_name_type account;
                authority previous_master_authority;
                time_point_sec last_valid_time;
            };
        }
    }
}

FC_REFLECT((graphene::plugins::database_api::master_authority_history_api_object),
           (id)(account)(previous_master_authority)(last_valid_time))
#endif //CHAIN_MASTER_AUTHORITY_HISTORY_API_OBJ_HPP
