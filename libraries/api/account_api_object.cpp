#include <graphene/api/account_api_object.hpp>

namespace graphene { namespace api {

using graphene::chain::by_account;
using graphene::chain::account_authority_object;
using graphene::chain::account_metadata_object;

account_api_object::account_api_object(const account_object& a, const graphene::chain::database& db)
    :   id(a.id), name(a.name), memo_key(a.memo_key), proxy(a.proxy), referrer(a.referrer),
        last_account_update(a.last_account_update), created(a.created),
        recovery_account(a.recovery_account), last_account_recovery(a.last_account_recovery),
        content_count(a.content_count), vote_count(a.vote_count), post_count(a.post_count),
        awarded_rshares(a.awarded_rshares), energy(a.energy), last_vote_time(a.last_vote_time),
        balance(a.balance), curation_rewards(a.curation_rewards), posting_rewards(a.posting_rewards),
        vesting_shares(a.vesting_shares),
        delegated_vesting_shares(a.delegated_vesting_shares), received_vesting_shares(a.received_vesting_shares),
        vesting_withdraw_rate(a.vesting_withdraw_rate), next_vesting_withdrawal(a.next_vesting_withdrawal),
        withdrawn(a.withdrawn), to_withdraw(a.to_withdraw), withdraw_routes(a.withdraw_routes),
        witnesses_voted_for(a.witnesses_voted_for), last_root_post(a.last_root_post), last_post(a.last_post),
        average_bandwidth(a.average_bandwidth), lifetime_bandwidth(a.lifetime_bandwidth), last_bandwidth_update(a.last_bandwidth_update) {
    size_t n = a.proxied_vsf_votes.size();
    proxied_vsf_votes.reserve(n);
    for (size_t i = 0; i < n; i++) {
        proxied_vsf_votes.push_back(a.proxied_vsf_votes[i]);
    }

    const auto& auth = db.get<account_authority_object, by_account>(name);
    owner = authority(auth.owner);
    active = authority(auth.active);
    posting = authority(auth.posting);
    last_owner_update = auth.last_owner_update;

#ifndef IS_LOW_MEM
    const auto& meta = db.get<account_metadata_object, by_account>(name);
    json_metadata = graphene::chain::to_string(meta.json_metadata);
#endif

}

account_api_object::account_api_object() {}

} } // graphene::api
