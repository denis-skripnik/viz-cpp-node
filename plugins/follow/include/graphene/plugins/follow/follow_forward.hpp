#ifndef GOLOS_FOLLOW_FORWARD_HPP
#define GOLOS_FOLLOW_FORWARD_HPP

#include <fc/reflect/reflect.hpp>

namespace graphene {
    namespace plugins {
        namespace follow {

        enum follow_type {
            undefined,
            blog,
            ignore
        };

            }}}

FC_REFLECT_ENUM(graphene::plugins::follow::follow_type, (undefined)(blog)(ignore))

#endif //GOLOS_FORWARD_HPP
