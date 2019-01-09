#pragma once

#include <appbase/application.hpp>
#include <graphene/plugins/chain/plugin.hpp>
#include <graphene/api/committee_api_object.hpp>

namespace graphene { namespace plugins { namespace committee_api {
    using plugins::json_rpc::msg_pack;
    using graphene::api::committee_api_object;
    using graphene::api::committee_vote_state;
    using namespace graphene::chain;

    DEFINE_API_ARGS(get_committee_request,      msg_pack, committee_api_object)
    DEFINE_API_ARGS(get_committee_request_votes,msg_pack, std::vector<committee_vote_state>)
    DEFINE_API_ARGS(get_committee_requests_list,msg_pack, std::vector<uint16_t>)

    class committee_api final: public appbase::plugin<committee_api> {
    public:
        APPBASE_PLUGIN_REQUIRES (
            (chain::plugin)
            (json_rpc::plugin)
        )

        DECLARE_API(
            (get_committee_request)
            (get_committee_request_votes)
            (get_committee_requests_list)
        )

        committee_api();
        ~committee_api();

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
} } } // graphene::plugins::committee_api