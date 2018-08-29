#include <graphene/protocol/operations.hpp>

#include <graphene/protocol/operation_util_impl.hpp>

namespace graphene {
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
} // graphene::protocol

DEFINE_OPERATION_TYPE(graphene::protocol::operation)
