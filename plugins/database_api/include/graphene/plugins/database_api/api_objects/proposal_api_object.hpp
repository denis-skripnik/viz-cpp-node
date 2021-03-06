#pragma once

#include <graphene/chain/proposal_object.hpp>

#include <graphene/protocol/types.hpp>

#include <graphene/chain/chain_object_types.hpp>

namespace graphene { namespace plugins { namespace database_api {

    struct proposal_api_object final {
        proposal_api_object() = default;

        proposal_api_object(const graphene::chain::proposal_object& p);

        protocol::account_name_type author;
        std::string title;
        std::string memo;

        time_point_sec expiration_time;
        optional<time_point_sec> review_period_time;
        std::vector<protocol::operation> proposed_operations;
        flat_set<protocol::account_name_type> required_active_approvals;
        flat_set<protocol::account_name_type> available_active_approvals;
        flat_set<protocol::account_name_type> required_master_approvals;
        flat_set<protocol::account_name_type> available_master_approvals;
        flat_set<protocol::account_name_type> required_regular_approvals;
        flat_set<protocol::account_name_type> available_regular_approvals;
        flat_set<protocol::public_key_type> available_key_approvals;
    };

}}} // graphene::plugins::database_api

FC_REFLECT(
    (graphene::plugins::database_api::proposal_api_object),
    (author)(title)(memo)(expiration_time)(review_period_time)(proposed_operations)
    (required_active_approvals)(available_active_approvals)
    (required_master_approvals)(available_master_approvals)
    (required_regular_approvals)(available_regular_approvals)
    (available_key_approvals))