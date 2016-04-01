#include "timestamp.hpp"
#include <regex>
#include <tuple>
#include <string>
#include <exception>
#include <sstream>
#include <boost/format.hpp>

const std::regex musak::annotations::timestamp::ts_regex = std::regex("([0-9]{2}):([0-9]{2}):([0-9]{2})\.([0-9]+)");

const std::tuple<int,int,int,int> musak::annotations::timestamp::parse_ts(const std::string& ts) {
    std::smatch m;
    bool found = std::regex_search(ts, m, ts_regex);
    if (found) {
        return std::make_tuple(std::stoi(m[0]), std::stoi(m[1]), std::stoi(m[2]), std::stoi(m[3]));
    } else {
        throw std::runtime_error(ts + " is not a valid time-stamp value");
    }
}

const std::string musak::annotations::timestamp::show() {
    std::ostringstream s;
    s << boost::format("%2d:%2d:%2d.%3d") % hours % minutes % seconds % milliseconds;
    return s.str();
}
