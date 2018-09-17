#include <graphene/api/chain_api_properties.hpp>

namespace graphene { namespace api {

    chain_api_properties::chain_api_properties(
        const chain_properties& src,
        const database& db
    ) : account_creation_fee(src.account_creation_fee),
        maximum_block_size(src.maximum_block_size),
        create_account_delegation_ratio(src.create_account_delegation_ratio),
        create_account_delegation_time(src.create_account_delegation_time),
        min_delegation(src.min_delegation),
        min_curation_percent(src.min_curation_percent),
        max_curation_percent(src.max_curation_percent),
        bandwidth_reserve_percent(src.bandwidth_reserve_percent),
        bandwidth_reserve_below(src.bandwidth_reserve_below),
        flag_energy_additional_cost(src.flag_energy_additional_cost)
    {
        create_account_delegation_ratio = src.create_account_delegation_ratio;
        create_account_delegation_time = src.create_account_delegation_time;
        min_delegation = src.min_delegation;
        min_curation_percent = src.min_curation_percent;
        max_curation_percent = src.max_curation_percent;
    }

} } // graphene::api
