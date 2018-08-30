#pragma once

#include <graphene/api/vote_state.hpp>
#include <graphene/api/comment_api_object.hpp>


namespace graphene { namespace api {

    struct discussion : public comment_api_object {
        discussion(const comment_object& o, const graphene::chain::database &db)
                : comment_api_object(o, db) {
        }

        discussion() {
        }

        string url; /// /@rootauthor/root_permlink#author/permlink
        string root_title;
        asset pending_payout_value = asset(0, TOKEN_SYMBOL);
        asset total_pending_payout_value = asset(0, TOKEN_SYMBOL); /// including replies
        std::vector<vote_state> active_votes;
        uint32_t active_votes_count = 0;
        std::vector<string> replies; ///< author/slug mapping
        double hot = 0;
        double trending = 0;
        std::vector<account_name_type> reblogged_by;
        optional <account_name_type> first_reblogged_by;
        optional <time_point_sec> first_reblogged_on;
    };

} } // graphene::api

FC_REFLECT_DERIVED( (graphene::api::discussion), ((graphene::api::comment_api_object)),
        (url)(root_title)(pending_payout_value)(total_pending_payout_value)(active_votes)(active_votes_count)(replies)
        (reblogged_by)(first_reblogged_by)(first_reblogged_on))
