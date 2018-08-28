#include <golos/api/committee_api_object.hpp>

namespace golos { namespace api {

    using namespace golos::chain;
    using golos::chain::committee_request_object;
    using golos::chain::committee_vote_object;

    committee_vote_state::committee_vote_state(const golos::chain::committee_vote_object &o)
        :  voter(o.voter),
           vote_percent(o.vote_percent),
           last_update(o.last_update) {
    }

    committee_vote_state::committee_vote_state() = default;

    committee_api_object::committee_api_object(const golos::chain::committee_request_object &o/*, const golos::chain::database &db*/)
        : id(o.id),
          request_id(o.request_id),
          url(o.url),
          creator(o.creator),
          worker(o.worker),
          required_amount_min(o.required_amount_min),
          required_amount_max(o.required_amount_max),
          start_time(o.start_time),
          duration(o.duration),
          end_time(o.end_time),
          status(o.status),
          votes_count(o.votes_count),
          conclusion_time(o.conclusion_time),
          conclusion_payout_amount(o.conclusion_payout_amount),
          payout_amount(o.payout_amount),
          remain_payout_amount(o.remain_payout_amount),
          last_payout_time(o.last_payout_time),
          payout_time(o.payout_time) {
        }

    committee_api_object::committee_api_object() = default;

} } // golos::api