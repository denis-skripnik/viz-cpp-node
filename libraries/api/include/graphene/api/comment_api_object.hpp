#ifndef CHAIN_COMMENT_API_OBJ_H
#define CHAIN_COMMENT_API_OBJ_H

#include <graphene/chain/comment_object.hpp>
#include <graphene/chain/database.hpp>
#include <vector>

namespace graphene { namespace api {

    using namespace graphene::chain;

    struct comment_api_object {
        comment_api_object(const comment_object &o, const database &db);
        comment_api_object();

        comment_object::id_type id;

        std::string title;
        std::string body;
        std::string json_metadata;

        account_name_type parent_author;
        std::string parent_permlink;
        account_name_type author;
        std::string permlink;

        time_point_sec last_update;
        time_point_sec created;
        time_point_sec active;
        time_point_sec last_payout;

        uint8_t depth;
        uint32_t children;

        uint128_t children_rshares2;

        share_type net_rshares;
        share_type abs_rshares;
        share_type vote_rshares;

        time_point_sec cashout_time;
        uint64_t total_vote_weight;
        int16_t curation_percent;
        int16_t consensus_curation_percent;

        protocol::asset payout_value;
        protocol::asset shares_payout_value;
        protocol::asset curator_payout_value;
        protocol::asset beneficiary_payout_value;

        share_type author_rewards;

        int32_t net_votes;

        comment_object::id_type root_comment;

        vector< protocol::beneficiary_route_type > beneficiaries;
    };

} } // graphene::api

FC_REFLECT(
    (graphene::api::comment_api_object),
    (id)(author)(permlink)(parent_author)(parent_permlink)(title)(body)(json_metadata)(last_update)
    (created)(active)(last_payout)(depth)(children)(children_rshares2)(net_rshares)(abs_rshares)
    (vote_rshares)(cashout_time)(total_vote_weight)(curation_percent)(consensus_curation_percent)
    (payout_value)(shares_payout_value)(curator_payout_value)(beneficiary_payout_value)(author_rewards)(net_votes)
    (root_comment)(beneficiaries))

#endif //CHAIN_COMMENT_API_OBJ_H
