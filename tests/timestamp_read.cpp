#define BOOST_TEST_MODULE timestamp_read
#include <boost/test/unit_test.hpp>
#include "timestamp.hpp"
#include <string>
#include <sstream>

using namespace musak::annotations;

BOOST_AUTO_TEST_CASE(timestamp_show)
{
    std::string ts1_str = "19:20:52.426";
    timestamp ts1 = timestamp(ts1_str);
    std::ostringstream ts1_repr;
    ts1_repr << ts1;
    BOOST_CHECK(ts1_str == ts1_repr.str());
}

BOOST_AUTO_TEST_CASE(timestamp_parse)
{
    std::string ts1_str = "19:20:52.426";
    timestamp ts1 = timestamp(ts1_str);
    hms_t ts1_value = hms_t(19, 20, 52, 426);
    BOOST_CHECK(ts1.get_hms() == ts1_value);
}
