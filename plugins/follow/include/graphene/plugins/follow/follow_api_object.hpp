#ifndef CHAIN_FOLLOW_API_OBJECT_HPP
#define CHAIN_FOLLOW_API_OBJECT_HPP

#include <graphene/api/content_api_object.hpp>
#include <graphene/plugins/follow/follow_objects.hpp>
#include "follow_forward.hpp"

namespace graphene {
    namespace plugins {
        namespace follow {
            using graphene::api::content_api_object;

            struct feed_entry {
                std::string author;
                std::string permlink;
                std::vector<std::string> reblog_by;
                time_point_sec reblog_on;
                uint32_t entry_id = 0;
            };

            struct content_feed_entry {
                content_api_object content;
                std::vector<std::string> reblog_by;
                time_point_sec reblog_on;
                uint32_t entry_id = 0;
            };

            struct blog_entry {
                std::string author;
                std::string permlink;
                std::string blog;
                time_point_sec reblog_on;
                uint32_t entry_id = 0;
            };

            struct content_blog_entry {
                content_api_object content;
                std::string blog;
                time_point_sec reblog_on;
                uint32_t entry_id = 0;
            };

            struct follow_api_object {
                std::string follower;
                std::string following;
                std::vector<follow_type> what;
            };

            struct reblog_count {
                std::string author;
                uint32_t count;
            };
            struct follow_count_api_obj {
                follow_count_api_obj() {}
                follow_count_api_obj(const std::string& acc,
                    uint32_t followers,
                    uint32_t followings,
                    uint32_t lim)
                     : account(acc),
                     follower_count(followers),
                     following_count(followings),
                     limit(lim) {
                }

                follow_count_api_obj(const follow_count_api_obj &o) :
                        account(o.account),
                        follower_count(o.follower_count),
                        following_count(o.following_count),
                        limit(o.limit) {
                }
                string account;
                uint32_t follower_count = 0;
                uint32_t following_count = 0;
                uint32_t limit = 1000;
            };

            using blog_authors_r = std::vector<std::pair<std::string, uint32_t>>;
        }}}

FC_REFLECT((graphene::plugins::follow::feed_entry), (author)(permlink)(reblog_by)(reblog_on)(entry_id));

FC_REFLECT((graphene::plugins::follow::content_feed_entry), (content)(reblog_by)(reblog_on)(entry_id));

FC_REFLECT((graphene::plugins::follow::blog_entry), (author)(permlink)(blog)(reblog_on)(entry_id));

FC_REFLECT((graphene::plugins::follow::content_blog_entry), (content)(blog)(reblog_on)(entry_id));

FC_REFLECT((graphene::plugins::follow::follow_api_object), (follower)(following)(what));

FC_REFLECT((graphene::plugins::follow::reblog_count), (author)(count));

FC_REFLECT((graphene::plugins::follow::follow_count_api_obj), (account)(follower_count)(following_count)(limit));


#endif //CHAIN_FOLLOW_API_OBJECT_HPP
