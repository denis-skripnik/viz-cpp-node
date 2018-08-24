#ifndef GOLOS_ACCOUNT_API_OBJ_HPP
#define GOLOS_ACCOUNT_API_OBJ_HPP

#include <golos/chain/account_object.hpp>
#include <golos/chain/database.hpp>
#include <golos/protocol/types.hpp>
#include <golos/chain/steem_object_types.hpp>

namespace golos { namespace api {

using golos::chain::account_object;
using protocol::asset;
using protocol::share_type;
using protocol::authority;
using protocol::account_name_type;
using protocol::public_key_type;


struct account_api_object {
    account_api_object(const account_object&, const golos::chain::database&);
    account_api_object();

    account_object::id_type id;

    account_name_type name;
    authority owner;
    authority active;
    authority posting;
    public_key_type memo_key;
    std::string json_metadata;
    account_name_type proxy;
    account_name_type referrer;

    time_point_sec last_owner_update;
    time_point_sec last_account_update;

    time_point_sec created;
    account_name_type recovery_account;
    time_point_sec last_account_recovery;
    uint32_t comment_count;
    uint32_t vote_count;
    uint32_t post_count;
    uint64_t awarded_rshares;

    int16_t voting_power;
    time_point_sec last_vote_time;

    asset balance;

    protocol::share_type curation_rewards;
    share_type posting_rewards;

    asset vesting_shares;
    asset delegated_vesting_shares;
    asset received_vesting_shares;
    asset vesting_withdraw_rate;
    time_point_sec next_vesting_withdrawal;
    share_type withdrawn;
    share_type to_withdraw;
    uint16_t withdraw_routes;

    std::vector<share_type> proxied_vsf_votes;

    uint16_t witnesses_voted_for;

    time_point_sec last_root_post;
    time_point_sec last_post;
    share_type average_bandwidth;
    share_type lifetime_bandwidth;
    time_point_sec last_bandwidth_update;

    set<string> witness_votes;
};

} } // golos::api


FC_REFLECT((golos::api::account_api_object),
    (id)(name)(owner)(active)(posting)(memo_key)(json_metadata)(proxy)(referrer)(last_owner_update)(last_account_update)
    (created)
    (recovery_account)(last_account_recovery)(comment_count)(vote_count)
    (post_count)(awarded_rshares)(voting_power)(last_vote_time)(balance)
    (vesting_shares)(delegated_vesting_shares)(received_vesting_shares)
    (vesting_withdraw_rate)(next_vesting_withdrawal)(withdrawn)(to_withdraw)(withdraw_routes)
    (curation_rewards)(posting_rewards)(proxied_vsf_votes)(witnesses_voted_for)
    (last_post)(last_root_post)
    (average_bandwidth)(lifetime_bandwidth)(last_bandwidth_update)
    (witness_votes))

#endif //GOLOS_ACCOUNT_API_OBJ_HPP
