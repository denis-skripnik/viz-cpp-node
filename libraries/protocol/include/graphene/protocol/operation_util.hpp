#pragma once

#include <graphene/protocol/authority.hpp>

#include <fc/variant.hpp>

#include <boost/container/flat_set.hpp>

#include <string>
#include <vector>

//
// Place DECLARE_OPERATION_TYPE in a .hpp file to declare
// functions related to your operation type
//
#define DECLARE_OPERATION_TYPE(OperationType)           \
namespace fc {                                          \
                                                        \
void to_variant(const OperationType&, fc::variant&);    \
void from_variant(const fc::variant&, OperationType&);  \
                                                        \
} /* fc */                                              \
                                                        \
namespace graphene { namespace protocol {                  \
                                                        \
void operation_validate(const OperationType&);          \
void operation_get_required_authorities(                \
    const OperationType& op,                            \
    flat_set<account_name_type>& active,                \
    flat_set<account_name_type>& master,                 \
    flat_set<account_name_type>& regular,               \
    vector<authority>& other);                          \
                                                        \
} } /* graphene::protocol */
