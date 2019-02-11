#include <boost/program_options/options_description.hpp>
#include <graphene/plugins/paid_subscription_api/paid_subscription_api.hpp>
#include <graphene/chain/index.hpp>
#include <graphene/chain/chain_objects.hpp>
#include <graphene/chain/paid_subscription_objects.hpp>
#include <graphene/api/paid_subscription_api_object.hpp>

#define CHECK_ARG_SIZE(_S)                                 \
   FC_ASSERT(                                              \
       args.args->size() == _S,                            \
       "Expected #_S argument(s), was ${n}",               \
       ("n", args.args->size()) );

#define CHECK_ARG_MIN_SIZE(_S, _M)                         \
   FC_ASSERT(                                              \
       args.args->size() >= _S && args.args->size() <= _M, \
       "Expected #_S (maximum #_M) argument(s), was ${n}", \
       ("n", args.args->size()) );

#define GET_OPTIONAL_ARG(_I, _T, _D)   \
   (args.args->size() > _I) ?          \
   (args.args->at(_I).as<_T>()) :      \
   static_cast<_T>(_D)

namespace graphene { namespace plugins { namespace paid_subscription_api {

    struct paid_subscription_api::impl final {
        impl(): database_(appbase::app().get_plugin<chain::plugin>().db()) {
        }

        ~impl() = default;

        graphene::chain::database& database() {
            return database_;
        }

        graphene::chain::database& database() const {
            return database_;
        }

    private:
        graphene::chain::database& database_;
    };

    void paid_subscription_api::plugin_startup() {
        wlog("paid_subscription_api plugin: plugin_startup()");
    }

    void paid_subscription_api::plugin_shutdown() {
        wlog("paid_subscription_api plugin: plugin_shutdown()");
    }

    const std::string& paid_subscription_api::name() {
        static const std::string name = "paid_subscription_api";
        return name;
    }

    paid_subscription_api::paid_subscription_api() = default;

    void paid_subscription_api::set_program_options(
        boost::program_options::options_description&,
        boost::program_options::options_description& config_file_options
    ) {
    }

    void paid_subscription_api::plugin_initialize(const boost::program_options::variables_map& options) {
        pimpl = std::make_unique<impl>();
        JSON_RPC_REGISTER_API(name());
    }

    paid_subscription_api::~paid_subscription_api() = default;

    DEFINE_API(paid_subscription_api, get_paid_subscription_options) {
        CHECK_ARG_MIN_SIZE(1, 1)
        auto account = args.args->at(0).as<account_name_type>();
        auto& db = pimpl->database();
        return db.with_weak_read_lock([&]() {
            const auto &idx = db.get_index<paid_subscription_index>().indices().get<by_creator>();
            auto itr = idx.find(account);
            FC_ASSERT(itr != idx.end(), "Paid subscription not found.");
            paid_subscription_state result = paid_subscription_state(*itr,db);
            return result;
        });
    }

    DEFINE_API(paid_subscription_api, get_paid_subscription_status) {
        CHECK_ARG_MIN_SIZE(1, 2)
        auto subscriber = args.args->at(0).as<account_name_type>();
        auto account = args.args->at(1).as<account_name_type>();
        auto& db = pimpl->database();
        return db.with_weak_read_lock([&]() {
            const auto &idx = db.get_index<paid_subscribe_index>().indices().get<by_subscribe>();
            auto itr = idx.find(boost::make_tuple(subscriber,account));
            FC_ASSERT(itr != idx.end(), "Paid subscribe not found.");
            paid_subscribe_state result = paid_subscribe_state(*itr);
            return result;
        });
    }

    DEFINE_API(paid_subscription_api, get_active_paid_subscriptions) {
        CHECK_ARG_MIN_SIZE(1, 1)
        auto subscriber = args.args->at(0).as<account_name_type>();
        auto& db = pimpl->database();
        return db.with_weak_read_lock([&]() {
            std::vector<account_name_type> result;
            const auto &idx = db.get_index<paid_subscribe_index>().indices().get<by_subscriber>();
            for (auto itr = idx.lower_bound(subscriber);
                 itr != idx.end() && (itr->subscriber == subscriber);
                 ++itr) {
                if(itr->active){
                    result.emplace_back(itr->creator);
                }
            }
            return result;
        });
    }

        DEFINE_API(paid_subscription_api, get_inactive_paid_subscriptions) {
            CHECK_ARG_MIN_SIZE(1, 1)
            auto subscriber = args.args->at(0).as<account_name_type>();
            auto& db = pimpl->database();
            return db.with_weak_read_lock([&]() {
                std::vector<account_name_type> result;
                const auto &idx = db.get_index<paid_subscribe_index>().indices().get<by_subscriber>();
                for (auto itr = idx.lower_bound(subscriber);
                     itr != idx.end() && (itr->subscriber == subscriber);
                     ++itr) {
                    if(!itr->active){
                        result.emplace_back(itr->creator);
                    }
                }
                return result;
            });
        }
} } } // graphene::plugins::paid_subscription_api
