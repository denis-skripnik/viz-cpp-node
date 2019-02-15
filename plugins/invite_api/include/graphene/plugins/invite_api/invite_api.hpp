#pragma once

#include <appbase/application.hpp>
#include <graphene/plugins/chain/plugin.hpp>
#include <graphene/api/invite_api_object.hpp>

namespace graphene { namespace plugins { namespace invite_api {
    using plugins::json_rpc::msg_pack;
    using graphene::api::invite_api_object;
    using namespace graphene::chain;

    DEFINE_API_ARGS(get_invites_list,           msg_pack, std::vector<int64_t>)
    DEFINE_API_ARGS(get_invite_by_id,           msg_pack, invite_api_object)
    DEFINE_API_ARGS(get_invite_by_key,          msg_pack, invite_api_object)

    class invite_api final: public appbase::plugin<invite_api> {
    public:
        APPBASE_PLUGIN_REQUIRES (
            (chain::plugin)
            (json_rpc::plugin)
        )

        DECLARE_API(
            (get_invites_list)
            (get_invite_by_id)
            (get_invite_by_key)
        )

        invite_api();
        ~invite_api();

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
} } } // graphene::plugins::invite_api