#pragma once

#include <golos/protocol/authority.hpp>
#include <golos/protocol/steem_operations.hpp>

#include <golos/chain/steem_object_types.hpp>

#include <boost/multi_index/composite_key.hpp>


namespace golos {
    namespace chain {
        class committee_request_object
                : public object<committee_request_object_type, committee_request_object> {
        public:
            template<typename Constructor, typename Allocator>
            committee_request_object(Constructor &&c, allocator <Allocator> a) {
                c(*this);
            }

            id_type id;

            shared_string url;
            account_name_type creator;
            account_name_type worker;

            asset required_amount_min = asset(0, STEEM_SYMBOL);
            asset required_amount_max = asset(0, STEEM_SYMBOL);

            time_point_sec start_time;
            uint32_t duration;
            time_point_sec end_time;
            uint16_t status;
            uint32_t votes_count;
            time_point_sec conclusion_time;
            asset conclusion_payout_amount = asset(0, STEEM_SYMBOL);
            asset payout_amount = asset(0, STEEM_SYMBOL);
            asset remain_payout_amount = asset(0, STEEM_SYMBOL);
            time_point_sec last_payout_time;
            time_point_sec payout_time;
        };


        class committee_vote_object
                : public object<committee_vote_object_type, committee_vote_object> {
        public:
            template<typename Constructor, typename Allocator>
            committee_vote_object(Constructor &&c, allocator <Allocator> a) {
                c(*this);
            }

            id_type id;
            committee_request_object_id_type request_id;

            account_name_type voter;
            int16_t vote_percent = 0;
            time_point_sec last_update;
        };

        struct by_request;
        typedef multi_index_container <
            committee_vote_object,
            indexed_by<
                ordered_unique <tag<by_voter_last_update>,
                    composite_key<committee_vote_object,
                        member <committee_vote_object, committee_request_object_id_type, &committee_vote_object::request_id>,
                        member <committee_vote_object, time_point_sec, &committee_vote_object::last_update>
                    >,
                composite_key_compare <std::less<committee_request_object_id_type>, std::greater<time_point_sec>>
            >
            >,
            allocator <committee_vote_object>
        >
        committee_vote_index;


        struct by_status;

        /**
         * @ingroup object_index
         */
        typedef multi_index_container <
            committee_request_object,
            indexed_by<
                ordered_unique <tag<by_id>,
                    member<committee_request_object, committee_request_object_id_type, &committee_request_object::id>
                >,
                ordered_unique <tag<by_status>,
                    composite_key<committee_request_object,
                        member <committee_request_object, uint16_t, &committee_request_object::status>,
                        member <committee_request_object, committee_request_object_id_type, &committee_request_object::id>
                    >
                >,
                composite_key_compare <std::less<uint16_t>, std::less<committee_request_object_id_type>>
            >
            >,
            allocator <committee_request_object>
        >
        committee_request_index;

    }
} // golos::chain

FC_REFLECT((golos::chain::committee_request_object),
        (id)(url)(creator)(worker)
            (required_amount_min)(required_amount_max)
            (start_time(duration)(end_time)
            (status)(votes_count)(conclusion_time)
            (conclusion_payout_amount)(payout_amount)(remain_payout_amount)
            (last_payout_time)(payout_time)

CHAINBASE_SET_INDEX_TYPE(golos::chain::committee_request_object, golos::chain::committee_request_index)

FC_REFLECT((golos::chain::committee_vote_object),
        (id)(request_id)(voter)(vote_percent)(last_update)

CHAINBASE_SET_INDEX_TYPE(golos::chain::committee_vote_object, golos::chain::comment_vote_index)
