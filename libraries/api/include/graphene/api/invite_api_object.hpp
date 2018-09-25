#ifndef CHAIN_INVITE_API_OBJ_H
#define CHAIN_INVITE_API_OBJ_H

#include <graphene/chain/invite_objects.hpp>
#include <graphene/chain/database.hpp>
#include <vector>

namespace graphene { namespace api {

    using namespace graphene::chain;
    using graphene::chain::invite_object;

    struct invite_api_object {
        invite_api_object(const invite_object &o);
        invite_api_object();

        invite_object::id_type id;

        account_name_type creator;
        account_name_type receiver;
        public_key_type invite_key;
        std::string invite_secret;

        protocol::asset balance;
        protocol::asset claimed_balance;

        time_point_sec create_time;
        time_point_sec claim_time;
        uint16_t status;
    };
} } // graphene::api

FC_REFLECT(
    (graphene::api::invite_api_object),
    (id)(creator)(receiver)(invite_key)(invite_secret)(balance)(claimed_balance)
    (create_time)(claim_time)(status))

#endif //CHAIN_INVITE_API_OBJ_H
