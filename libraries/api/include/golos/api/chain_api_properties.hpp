#pragma once

#include <golos/chain/witness_objects.hpp>
#include <golos/chain/database.hpp>

namespace golos { namespace api {
    using golos::protocol::asset;
    using golos::chain::chain_properties;
    using golos::chain::database;

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
    };

} } // golos::api

FC_REFLECT(
    (golos::api::chain_api_properties),
    (account_creation_fee)(maximum_block_size)(maximum_block_size)
    (create_account_delegation_ratio)(create_account_delegation_time)(min_delegation)
    (min_curation_percent)(max_curation_percent)(bandwidth_reserve_percent)(bandwidth_reserve_below))