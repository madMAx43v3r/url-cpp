#ifndef URL_CPP_H
#define URL_CPP_H

#include <stdexcept>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace Url
{

    struct UrlParseException : public std::logic_error
    {
        UrlParseException(const std::string& message) : std::logic_error(message) {}
    };

    struct Url
    {
        /* Character classes */
        const static std::string GEN_DELIMS;
        const static std::string SUB_DELIMS;
        const static std::string ALPHA;
        const static std::string DIGIT;
        const static std::string UNRESERVED;
        const static std::string RESERVED;
        const static std::string PCHAR;
        const static std::string PATH;
        const static std::string QUERY;
        const static std::string FRAGMENT;
        const static std::string USERINFO;
        const static std::string HEX;
        const static std::string SCHEME;

        explicit Url(const std::string& url);

        Url(const Url& other)
            : scheme_(other.scheme_)
            , host_(other.host_)
            , port_(other.port_)
            , path_(other.path_)
            , params_(other.params_)
            , query_(other.query_)
            , fragment_(other.fragment_)
            , userinfo_(other.userinfo_) { }

        /**************************
         * Component-wise access. *
         **************************/
        const std::string& scheme() const { return scheme_; }

        const std::string& host() const { return host_; }

        const int port() const { return port_; }

        const std::string& path() const { return path_; }

        const std::string& params() const { return params_; }

        const std::string& query() const { return query_; }

        const std::string& fragment() const { return fragment_; }

        const std::string& userinfo() const { return userinfo_; }

    private:
        // Private, unimplemented to prevent use.
        Url();

        std::string scheme_;
        std::string host_;
        int port_;
        std::string path_;
        std::string params_;
        std::string query_;
        std::string fragment_;
        std::string userinfo_;
    };

}

#endif