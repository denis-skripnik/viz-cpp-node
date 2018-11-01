#include <graphene/api/invite_api_object.hpp>

namespace graphene { namespace api {

    using namespace graphene::chain;
    using graphene::chain::invite_object;

    invite_api_object::invite_api_object(const graphene::chain::invite_object &o)
        : id(o.id),
          creator(o.creator),
          receiver(o.receiver),
          invite_key(o.invite_key),
          invite_secret(to_string(o.invite_secret)),
          balance(o.balance),
          claimed_balance(o.claimed_balance),
          create_time(o.create_time),
          claim_time(o.claim_time),
          status(o.status) {
        }

    invite_api_object::invite_api_object() = default;

} } // graphene::api