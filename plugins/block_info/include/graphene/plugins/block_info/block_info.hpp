#pragma once

#include <graphene/chain/chain_object_types.hpp>

namespace graphene {
namespace plugins {
namespace block_info {

struct block_info {
    graphene::chain::block_id_type block_id;
    uint32_t block_size = 0;
    uint32_t average_block_size = 0;
    uint64_t aslot = 0;
    uint32_t last_irreversible_block_num = 0;
};

struct block_with_info {
    graphene::chain::signed_block block;
    block_info info;
};

} } }


FC_REFLECT( (graphene::plugins::block_info::block_info),
    (block_id)
    (block_size)
    (average_block_size)
    (aslot)
    (last_irreversible_block_num)
)


FC_REFLECT( (graphene::plugins::block_info::block_with_info),
    (block)
    (info)
)
