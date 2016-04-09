#ifndef H_MUSAK_TIMESTAMP
#define H_MUSAK_TIMESTAMP

#include "musak.hpp"
#include <string>
#include <regex>
#include <tuple>
#include <ostream>

namespace musak {

    namespace annotations {

        typedef std::tuple<int,int,int,int> hms_t;

        class timestamp {
        public:
            timestamp(const std::string& ts) : timestamp(parse_ts(ts)) { };
            timestamp(hms_t t) :
                hours(std::get<0>(t)), minutes(std::get<1>(t)), seconds(std::get<2>(t)),
                milliseconds(std::get<3>(t)) { };
            timestamp(const int h, const int m, const int s, const int ms) :
                hours(h), minutes(m), seconds(s), milliseconds(ms) { };

            const hms_t get_hms() const;

            friend std::ostream& operator<<(std::ostream& st, timestamp& ts) { return st << ts.show(); }

        private:
            const static std::regex ts_regex;

            int hours;
            int minutes;
            int seconds;
            int milliseconds;

            static const hms_t parse_ts(const std::string& ts);
            const std::string show() const;

        }; // timestamp class

    } // namesace annotations

} // namespace musak

#endif
