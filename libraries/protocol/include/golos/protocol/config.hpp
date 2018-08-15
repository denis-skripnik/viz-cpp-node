/*
 * Copyright (c) 2016 Golos, Inc., and contributors.
 */
#pragma once

#define BLOCKCHAIN_VERSION              (version(1, 0, 0))
#define BLOCKCHAIN_HARDFORK_VERSION     (hardfork_version(BLOCKCHAIN_VERSION))

#define BLOCKCHAIN_NAME                         "VIZ"
#define STEEMIT_CHAIN_ID                        (fc::sha256::hash(BLOCKCHAIN_NAME))
#define STEEMIT_ADDRESS_PREFIX                  "VIZ"

#define VESTS_SYMBOL  (uint64_t(6) | (uint64_t('S') << 8) | (uint64_t('H') << 16) | (uint64_t('A') << 24) | (uint64_t('R') << 32) | (uint64_t('E') << 40) | (uint64_t('S') << 48)) ///< GESTS with 6 digits of precision
#define STEEM_SYMBOL  (uint64_t(3) | (uint64_t('V') << 8) | (uint64_t('I') << 16) | (uint64_t('Z') << 24)) ///< GOLOS with 3 digits of precision

#define STEEMIT_INIT_PUBLIC_KEY_STR             "VIZ6MyX5QiXAXRZk7SYCiqpi6Mtm8UbHWDFSV8HPpt7FJyahCnc2T"

#define STEEMIT_GENESIS_TIME                    (fc::time_point_sec(1476788400))
#define STEEMIT_CASHOUT_WINDOW_SECONDS          (60*60*24)  // 1 day

#define STEEMIT_MAX_PROPOSAL_LIFETIME_SEC       (60*60*24*7*4) /// 4 weeks
#define STEEMIT_MAX_PROPOSAL_DEPTH              (2)

#define STEEMIT_MIN_ACCOUNT_CREATION_FEE        1000

#define STEEMIT_OWNER_AUTH_RECOVERY_PERIOD                  fc::days(30)
#define STEEMIT_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::days(1)
#define STEEMIT_OWNER_UPDATE_LIMIT                          fc::minutes(60)

#define STEEMIT_BLOCK_INTERVAL                  3
#define STEEMIT_BLOCKS_PER_YEAR                 (365*24*60*60/STEEMIT_BLOCK_INTERVAL)
#define STEEMIT_BLOCKS_PER_DAY                  (24*60*60/STEEMIT_BLOCK_INTERVAL)
#define STEEMIT_MAX_WITNESS_MISSED_BLOCKS       200

#define STEEMIT_INITIATOR_NAME                 "viz"
#define STEEMIT_NUM_INITIATORS                 1
#define STEEMIT_MAX_TOP_WITNESSES             10
#define STEEMIT_MAX_SUPPORT_WITNESSES            11
#define STEEMIT_MAX_WITNESSES                   (STEEMIT_MAX_TOP_WITNESSES+STEEMIT_MAX_SUPPORT_WITNESSES) /// 21 is more than enough
#define STEEMIT_HARDFORK_REQUIRED_WITNESSES     17 // 17 of the 20 dpos witnesses (19 elected and 1 virtual time) required for hardfork. This guarantees 75% participation on all subsequent rounds.
#define STEEMIT_MAX_TIME_UNTIL_EXPIRATION       (60*60) // seconds,  aka: 1 hour
#define STEEMIT_MAX_MEMO_SIZE                   2048
#define STEEMIT_MAX_PROXY_RECURSION_DEPTH       4
#define STEEMIT_VESTING_WITHDRAW_INTERVALS      28
#define STEEMIT_VESTING_WITHDRAW_INTERVAL_SECONDS (60*60*24) // 1 day per interval
#define STEEMIT_MAX_WITHDRAW_ROUTES             10
#define STEEMIT_VOTE_REGENERATION_SECONDS       (5*60*60*24) // 5 days
#define STEEMIT_MAX_VOTE_CHANGES                5
#define STEEMIT_UPVOTE_LOCKOUT                  (fc::minutes(1))
#define STEEMIT_REVERSE_AUCTION_WINDOW_SECONDS  (60*30) /// 30 minutes
#define STEEMIT_MIN_VOTE_INTERVAL_SEC           1
#define STEEMIT_MAX_COMMENT_BENEFICIARIES       64
#define STEEMIT_VOTE_POWER_RATE					1

#define STEEMIT_MIN_ROOT_COMMENT_INTERVAL       (fc::seconds(1))
#define STEEMIT_MIN_REPLY_INTERVAL              (fc::seconds(1))

#define STEEMIT_MAX_ACCOUNT_WITNESS_VOTES       2

#define STEEMIT_100_PERCENT                     10000
#define STEEMIT_1_PERCENT                       (STEEMIT_100_PERCENT/100)
#define STEEMIT_1_TENTH_PERCENT                 (STEEMIT_100_PERCENT/1000)

#define STEEMIT_FIXED_INFLATION					(1000) //10%
#define STEEMIT_CONTENT_REWARD_PERCENT          (30*STEEMIT_1_PERCENT) //30% of inflation
#define STEEMIT_REWARD_FUND_CURATOR_PERCENT     (5*100/30*STEEMIT_1_PERCENT) //5% of inflation from reward fund
#define STEEMIT_VESTING_FUND_PERCENT            (40*STEEMIT_1_PERCENT) //40% of inflation
#define STEEMIT_COMMITTEE_FUND_PERCENT          (15*STEEMIT_1_PERCENT) //15% of inflation

#define STEEMIT_BANDWIDTH_AVERAGE_WINDOW_SECONDS (60*60*24*7) ///< 1 week
#define STEEMIT_BANDWIDTH_PRECISION             1000000ll ///< 1 million
#define STEEMIT_MAX_COMMENT_DEPTH               0xfff0 // 64k - 16

#define STEEMIT_MAX_RESERVE_RATIO   (20000)

#define GOLOS_CREATE_ACCOUNT_DELEGATION_RATIO       10
#define GOLOS_CREATE_ACCOUNT_DELEGATION_TIME        (fc::days(30))
#define GOLOS_MIN_DELEGATION                        1

#define STEEMIT_EQUIHASH_N                      140
#define STEEMIT_EQUIHASH_K                      6

#define STEEMIT_MIN_ACCOUNT_NAME_LENGTH          2
#define STEEMIT_CREATE_MIN_ACCOUNT_NAME_LENGTH   3
#define STEEMIT_MAX_ACCOUNT_NAME_LENGTH         25

#define STEEMIT_MIN_PERMLINK_LENGTH             0
#define STEEMIT_MAX_PERMLINK_LENGTH             256
#define STEEMIT_MAX_WITNESS_URL_LENGTH          2048

#define STEEMIT_INIT_SUPPLY                     int64_t(50000000000)
#define STEEMIT_MAX_SHARE_SUPPLY                int64_t(1000000000000000ll)
#define STEEMIT_MAX_SIG_CHECK_DEPTH             2

#define STEEMIT_SECONDS_PER_YEAR                (uint64_t(60*60*24*365ll))

#define STEEMIT_MAX_TRANSACTION_SIZE            (1024*64)
#define STEEMIT_MIN_BLOCK_SIZE_LIMIT            (STEEMIT_MAX_TRANSACTION_SIZE)
#define STEEMIT_MAX_BLOCK_SIZE                  (STEEMIT_MAX_TRANSACTION_SIZE*STEEMIT_BLOCK_INTERVAL*2000)

#define STEEMIT_MAX_UNDO_HISTORY                10000

#define STEEMIT_IRREVERSIBLE_THRESHOLD          (75 * STEEMIT_1_PERCENT)

/**
 *  Reserved Account IDs with special meaning
 */
///@{
/// Represents the canonical account with NO authority (nobody can access funds in null account)
#define STEEMIT_NULL_ACCOUNT                    "null"
/// Represents the canonical account with NO authority (nobody can access funds in committee account, all income transfers going to committee fund)
#define STEEMIT_COMMITTEE_ACCOUNT               "committee"
/// Represents the canonical account with WILDCARD authority (anybody can access funds in temp account)
#define STEEMIT_TEMP_ACCOUNT                    "temp"
/// Represents the canonical account with NO authority (nobody can access funds in committee account, all income transfers going to new anonymous sub-account)
#define STEEMIT_ANONYMOUS_ACCOUNT                    "anonymous"
/// Represents the canonical account for specifying you will vote for directly (as opposed to a proxy)
#define STEEMIT_PROXY_TO_SELF_ACCOUNT           ""
/// Represents the canonical root post parent account
#define STEEMIT_ROOT_POST_PARENT                (account_name_type())
///@}
