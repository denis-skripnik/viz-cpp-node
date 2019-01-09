#pragma once

#include <graphene/chain/witness_objects.hpp>
#include <graphene/chain/database.hpp>

namespace graphene { namespace api {
    using graphene::protocol::asset;
    using graphene::chain::chain_properties;
    using graphene::chain::database;

    struct chain_api_properties {
        chain_api_properties(const chain_properties&, const database&);
        chain_api_properties() = default;

        asset account_creation_fee;
        uint32_t maximum_block_size;

        uint32_t create_account_delegation_ratio;
        uint32_t create_account_delegation_time;
        asset min_delegation;
        int16_t min_curation_percent;
        int16_t max_curation_percent;
        int16_t bandwidth_reserve_percent;
        asset bandwidth_reserve_below;
        int16_t flag_energy_additional_cost;
        uint32_t vote_accounting_min_rshares;
        int16_t committee_request_approve_min_percent;

        fc::optional<int16_t> inflation_witness_percent;
        fc::optional<int16_t> inflation_ratio_committee_vs_reward_fund;
        fc::optional<uint32_t> inflation_recalc_period;
    };

} } // graphene::api

FC_REFLECT(
    (graphene::api::chain_api_properties),
    (account_creation_fee)(maximum_block_size)(maximum_block_size)
    (create_account_delegation_ratio)(create_account_delegation_time)(min_delegation)
    (min_curation_percent)(max_curation_percent)(bandwidth_reserve_percent)(bandwidth_reserve_below)
    (flag_energy_additional_cost)(vote_accounting_min_rshares)(committee_request_approve_min_percent)
    (inflation_witness_percent)(inflation_ratio_committee_vs_reward_fund)(inflation_recalc_period))