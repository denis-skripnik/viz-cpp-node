#pragma once

#include <golos/protocol/base.hpp>
#include <golos/protocol/block_header.hpp>
#include <golos/protocol/asset.hpp>

#include <fc/utf8.hpp>

namespace golos { namespace protocol {

        struct author_reward_operation : public virtual_operation {
            author_reward_operation() {
            }

            author_reward_operation(const account_name_type &a, const string &p, const asset &st, const asset &v)
                    : author(a), permlink(p), steem_payout(st),
                      vesting_payout(v) {
            }

            account_name_type author;
            string permlink;
            asset steem_payout;
            asset vesting_payout;
        };


        struct curation_reward_operation : public virtual_operation {
            curation_reward_operation() {
            }

            curation_reward_operation(const string &c, const asset &r, const string &a, const string &p)
                    : curator(c), reward(r), comment_author(a),
                      comment_permlink(p) {
            }

            account_name_type curator;
            asset reward;
            account_name_type comment_author;
            string comment_permlink;
        };


        struct comment_reward_operation : public virtual_operation {
            comment_reward_operation() {
            }

            comment_reward_operation(const account_name_type &a, const string &pl, const asset &p)
                    : author(a), permlink(pl), payout(p) {
            }

            account_name_type author;
            string permlink;
            asset payout;
        };


        struct fill_vesting_withdraw_operation : public virtual_operation {
            fill_vesting_withdraw_operation() {
            }

            fill_vesting_withdraw_operation(const string &f, const string &t, const asset &w, const asset &d)
                    : from_account(f), to_account(t), withdrawn(w),
                      deposited(d) {
            }

            account_name_type from_account;
            account_name_type to_account;
            asset withdrawn;
            asset deposited;
        };


        struct shutdown_witness_operation : public virtual_operation {
            shutdown_witness_operation() {
            }

            shutdown_witness_operation(const string &o) : owner(o) {
            }

            account_name_type owner;
        };


        struct hardfork_operation : public virtual_operation {
            hardfork_operation() {
            }

            hardfork_operation(uint32_t hf_id) : hardfork_id(hf_id) {
            }

            uint32_t hardfork_id = 0;
        };

        struct comment_payout_update_operation : public virtual_operation {
            comment_payout_update_operation() {
            }

            comment_payout_update_operation(const account_name_type &a, const string &p)
                    : author(a), permlink(p) {
            }

            account_name_type author;
            string permlink;
        };

        struct comment_benefactor_reward_operation : public virtual_operation {
            comment_benefactor_reward_operation() {
            }

            comment_benefactor_reward_operation(const account_name_type &b, const account_name_type &a, const string &p, const asset &r)
                    : benefactor(b), author(a), permlink(p), reward(r) {
            }

            account_name_type benefactor;
            account_name_type author;
            string permlink;
            asset reward;
        };

        struct return_vesting_delegation_operation: public virtual_operation {
            return_vesting_delegation_operation() {
            }
            return_vesting_delegation_operation(const account_name_type& a, const asset& v)
            :   account(a), vesting_shares(v) {
            }

            account_name_type account;
            asset vesting_shares;
        };

        struct committee_cancel_request_operation : public virtual_operation {
            committee_cancel_request_operation() {
            }

            committee_cancel_request_operation(const uint32_t &a)
                    : request_id(a) {
            }

            uint32_t request_id;
        };

        struct committee_approve_request_operation : public virtual_operation {
            committee_approve_request_operation() {
            }

            committee_approve_request_operation(const uint32_t &a)
                    : request_id(a) {
            }

            uint32_t request_id;
        };

        struct committee_payout_request_operation : public virtual_operation {
            committee_payout_request_operation() {
            }

            committee_payout_request_operation(const uint32_t &a)
                    : request_id(a) {
            }

            uint32_t request_id;
        };

        struct committee_pay_request_operation : public virtual_operation {
            committee_pay_request_operation() {
            }

            committee_pay_request_operation(const account_name_type& w, const uint32_t &a, const asset& t)
                    : worker(w), request_id(a), tokens(t) {
            }

            account_name_type worker;
            uint32_t request_id;
            asset tokens;
        };
} } //golos::protocol

FC_REFLECT((golos::protocol::author_reward_operation), (author)(permlink)(steem_payout)(vesting_payout))
FC_REFLECT((golos::protocol::curation_reward_operation), (curator)(reward)(comment_author)(comment_permlink))
FC_REFLECT((golos::protocol::comment_reward_operation), (author)(permlink)(payout))
FC_REFLECT((golos::protocol::fill_vesting_withdraw_operation), (from_account)(to_account)(withdrawn)(deposited))
FC_REFLECT((golos::protocol::shutdown_witness_operation), (owner))
FC_REFLECT((golos::protocol::hardfork_operation), (hardfork_id))
FC_REFLECT((golos::protocol::comment_payout_update_operation), (author)(permlink))
FC_REFLECT((golos::protocol::comment_benefactor_reward_operation), (benefactor)(author)(permlink)(reward))
FC_REFLECT((golos::protocol::return_vesting_delegation_operation), (account)(vesting_shares))
FC_REFLECT((golos::protocol::committee_cancel_request_operation), (request_id))
FC_REFLECT((golos::protocol::committee_approve_request_operation), (request_id))
FC_REFLECT((golos::protocol::committee_payout_request_operation), (request_id))
FC_REFLECT((golos::protocol::committee_pay_request_operation), (worker)(request_id)(tokens))
