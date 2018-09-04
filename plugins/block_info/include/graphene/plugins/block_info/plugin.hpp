#pragma once

#include <appbase/application.hpp>
#include <graphene/plugins/block_info/block_info.hpp>

#include <boost/program_options.hpp>
#include <string>
#include <vector>
#include <graphene/plugins/chain/plugin.hpp>
#include <graphene/plugins/json_rpc/utility.hpp>
#include <graphene/plugins/json_rpc/plugin.hpp>

namespace graphene {
namespace protocol {

struct signed_block;

} }


namespace graphene {
namespace plugins {
namespace block_info {

using graphene::plugins::json_rpc::msg_pack;

DEFINE_API_ARGS ( get_block_info,           msg_pack,       std::vector<block_info>)
DEFINE_API_ARGS ( get_blocks_with_info,     msg_pack,       std::vector<block_with_info>)


using boost::program_options::options_description;

class plugin final : public appbase::plugin<plugin> {
public:
    APPBASE_PLUGIN_REQUIRES((graphene::plugins::chain::plugin))

    constexpr const static char *plugin_name = "block_info";

    static const std::string &name() {
        static std::string name = plugin_name;
        return name;
    }

    plugin();

    ~plugin();

    void set_program_options(boost::program_options::options_description &cli, boost::program_options::options_description &cfg) override {
    }

    void plugin_initialize(const boost::program_options::variables_map &options) override;

    void plugin_startup() override;

    void plugin_shutdown() override;

    DECLARE_API(
            (get_block_info)
            (get_blocks_with_info)
    )
    void on_applied_block(const protocol::signed_block &b);

private:
    struct plugin_impl;

    std::unique_ptr<plugin_impl> my;
};

} } }


