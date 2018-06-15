#include <golos/protocol/operations.hpp>

#include <golos/protocol/operation_util_impl.hpp>

namespace golos {
    namespace protocol {

        struct is_vop_visitor {
            typedef bool result_type;

            template<typename T>
            bool operator()(const T &v) const {
                return v.is_virtual();
            }
        };

        bool is_virtual_operation(const operation &op) {
            return op.visit(is_vop_visitor());
        }

    }
} // golos::protocol

DEFINE_OPERATION_TYPE(golos::protocol::operation)
