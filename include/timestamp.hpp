#ifndef H_MUSAK_TIMESTAMP
#define H_MUSAK_TIMESTAMP

#include "musak.hpp"
#include <string>
#include <regex>
#include <tuple>

namespace musak {

    namespace annotations {

        std::tuple<int,int,int,int> parse_ts(const std::string &ts);

        class timestamp {
        public:
            timestamp(const std::string &ts) : timestamp(parse_ts(ts)) { };
            timestamp(std::tuple<int,int,int,int> t) :
                hours(std::get<0>(t)), minutes(std::get<1>(t)), seconds(std::get<2>(t)),
                milliseconds(std::get<3>(t)) { };
            timestamp(const int h, const int m, const int s, const int ms) :
                hours(h), minutes(m), seconds(s), milliseconds(ms) { };
           ~timestamp();

            friend std::tuple<int,int,int,int> parse_ts(const std::string &ts);

        private:
            const static std::regex ts_regex;

            int hours;
            int minutes;
            int seconds;
            int milliseconds;

        }; // timestamp class

    } // namesace annotations

} // namespace musak

#endif
