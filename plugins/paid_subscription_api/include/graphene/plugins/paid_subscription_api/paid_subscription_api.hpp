#pragma once

#include <appbase/application.hpp>
#include <graphene/plugins/chain/plugin.hpp>
#include <graphene/api/paid_subscription_api_object.hpp>
#include <graphene/protocol/types.hpp>
#include <graphene/chain/chain_objects.hpp>

namespace graphene { namespace plugins { namespace paid_subscription_api {
    using plugins::json_rpc::msg_pack;
    using graphene::chain::paid_subscription_object;
    using graphene::chain::paid_subscribe_object;
    using graphene::api::paid_subscription_state;
    using graphene::api::paid_subscribe_state;
    using namespace graphene::protocol;
    using namespace graphene::chain;

    DEFINE_API_ARGS(get_paid_subscriptions, msg_pack, std::vector<paid_subscription_object>)
    DEFINE_API_ARGS(get_paid_subscription_options, msg_pack, paid_subscription_state)
    DEFINE_API_ARGS(get_paid_subscription_status, msg_pack, paid_subscribe_state)
    DEFINE_API_ARGS(get_active_paid_subscriptions, msg_pack, std::vector<account_name_type>)
    DEFINE_API_ARGS(get_inactive_paid_subscriptions, msg_pack, std::vector<account_name_type>)

    class paid_subscription_api final: public appbase::plugin<paid_subscription_api> {
    public:
        APPBASE_PLUGIN_REQUIRES (
            (chain::plugin)
            (json_rpc::plugin)
        )

        DECLARE_API(
            (get_paid_subscriptions)
            (get_paid_subscription_options)
            (get_paid_subscription_status)
            (get_active_paid_subscriptions)
            (get_inactive_paid_subscriptions)
        )

        paid_subscription_api();
        ~paid_subscription_api();

        void set_program_options(
            boost::program_options::options_description&,
            boost::program_options::options_description& config_file_options
        ) override;

        static const std::string& name();

        void plugin_initialize(const boost::program_options::variables_map& options) override;

        void plugin_startup() override;
        void plugin_shutdown() override;

    private:
        struct impl;
        std::unique_ptr<impl> pimpl;
    };
} } } // graphene::plugins::paid_subscription_api