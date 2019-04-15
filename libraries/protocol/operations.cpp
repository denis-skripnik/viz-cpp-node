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

        struct is_dop_visitor {
            typedef bool result_type;

            template<typename T>
            bool operator()(const T &v) const {
                return false;
            }

            bool operator()(const custom_operation&) const {
                return true;
            }

            bool operator()(const account_create_operation&) const {
                return true;
            }

            bool operator()(const account_update_operation&) const {
                return true;
            }

            bool operator()(const account_metadata_operation&) const {
                return true;
            }

            bool operator()(const escrow_transfer_operation&) const {
                return true;
            }
        };

        bool is_data_operation(const operation &op) {
            return op.visit(is_dop_visitor());
        }

    }
} // graphene::protocol

DEFINE_OPERATION_TYPE(graphene::protocol::operation)
