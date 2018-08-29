#pragma once

#include <graphene/protocol/operations.hpp>
#include <graphene/chain/steem_object_types.hpp>
#include <graphene/plugins/operation_history/history_object.hpp>

namespace graphene { namespace plugins { namespace operation_history {

    struct applied_operation final {
        applied_operation();

        applied_operation(const operation_object&);

        graphene::protocol::transaction_id_type trx_id;
        uint32_t block = 0;
        uint32_t trx_in_block = 0;
        uint16_t op_in_trx = 0;
        uint64_t virtual_op = 0;
        fc::time_point_sec timestamp;
        graphene::protocol::operation op;
    };

} } } // graphene::plugins::operation_history

FC_REFLECT(
    (graphene::plugins::operation_history::applied_operation),
    (trx_id)(block)(trx_in_block)(op_in_trx)(virtual_op)(timestamp)(op))
