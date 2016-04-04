#define BOOST_TEST_MODULE timestamp_read
#include <boost/test/unit_test.hpp>
#include "timestamp.hpp"
#include <string>
#include <sstream>
#include <iostream>

using namespace musak::annotations;

BOOST_AUTO_TEST_CASE(timestamp_show)
{
    std::string ts1_str = "19:20:52.426";
    timestamp ts1 = timestamp(ts1_str);
    std::ostringstream ts1_repr;
    ts1_repr << ts1;
    std::cout << ts1_str << " == " << ts1_repr.str() << "?" << std::endl;
    BOOST_CHECK(ts1_str == ts1_repr.str());
}

std::ostream& operator<<(std::ostream& st, hms_t h) {
    return st << "(" << std::get<0>(h) << "," << std::get<1>(h) << "," << std::get<2>(h) << "," << std::get<3>(h) << ")";
}

BOOST_AUTO_TEST_CASE(timestamp_parse)
{
    std::string ts1_str = "19:20:52.426";
    timestamp ts1 = timestamp(ts1_str);
    hms_t ts1_value = hms_t(19, 20, 52, 426);
    std::cout << ts1.get_hms() << " == " << ts1_value << "?" << std::endl;
    BOOST_CHECK(ts1.get_hms() == ts1_value);
}
