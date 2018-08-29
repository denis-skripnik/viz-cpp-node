#pragma once
#include <graphene/protocol/types.hpp>
#include <fc/reflect/reflect.hpp>

namespace graphene { namespace api {
    using graphene::protocol::share_type;
    struct vote_state {
        string voter;
        uint64_t weight = 0;
        int64_t rshares = 0;
        int16_t percent = 0;
        time_point_sec time;
    };

} } // graphene::api


FC_REFLECT((graphene::api::vote_state), (voter)(weight)(rshares)(percent)(time));