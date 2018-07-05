#include <golos/chain/steem_evaluator.hpp>
#include <golos/chain/database.hpp>
#include <golos/chain/steem_objects.hpp>

namespace golos { namespace chain {

    void witness_update_evaluator::do_apply(const witness_update_operation& o) {
        _db.get_account(o.owner); // verify owner exists

        const auto &idx = _db.get_index<witness_index>().indices().get<by_name>();
        auto itr = idx.find(o.owner);
        if (itr != idx.end()) {
            _db.modify(*itr, [&](witness_object& w) {
                from_string(w.url, o.url);
                w.signing_key = o.block_signing_key;
            });
        } else {
            _db.create<witness_object>([&](witness_object& w) {
                w.owner = o.owner;
                from_string(w.url, o.url);
                w.signing_key = o.block_signing_key;
                w.created = _db.head_block_time();
            });
        }
    }

    void chain_properties_update_evaluator::do_apply(const chain_properties_update_operation& o) {
        ASSERT_REQ_HF(STEEMIT_HARDFORK_0_18__673, "Chain properties"); // remove after hf
        _db.get_account(o.owner); // verify owner exists

        const auto &idx = _db.get_index<witness_index>().indices().get<by_name>();
        auto itr = idx.find(o.owner);
        if (itr != idx.end()) {
            _db.modify(*itr, [&](witness_object& w) {
                w.props = o.props;
            });
        } else {
            _db.create<witness_object>([&](witness_object& w) {
                w.owner = o.owner;
                w.created = _db.head_block_time();
                w.props = o.props;
            });
        }
    }

} } // golos::chain