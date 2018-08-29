#pragma once

#include <graphene/protocol/block_header.hpp>
#include <graphene/protocol/transaction.hpp>

namespace graphene {
    namespace protocol {

        struct signed_block : public signed_block_header {
            checksum_type calculate_merkle_root() const;

            vector <signed_transaction> transactions;
        };

    }
} // graphene::protocol

FC_REFLECT_DERIVED((graphene::protocol::signed_block), ((graphene::protocol::signed_block_header)), (transactions))
