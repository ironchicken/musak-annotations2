#define BOOST_TEST_MODULE shapes
#include <boost/test/unit_test.hpp>
#include "shape.hpp"
#include "mark.hpp"
#include <vector>
#include <tuple>

using namespace musak::annotations;

BOOST_AUTO_TEST_CASE(shape_create)
{
    auto s1 = shape();
    BOOST_CHECK(s1.empty() == true);

    std::vector<mark> ms { mark("#000000", 2, 0, 0, 10, 10, "00:00:00.0") };
    auto s2 = shape("s2", ms);

    BOOST_CHECK(s2.empty() == false);
}

BOOST_AUTO_TEST_CASE(shape_bounds)
{
    auto s1 = shape();
    BOOST_CHECK(s1.bounds() == zero_bounds);

    std::vector<mark> ms2 { mark("#000000", 2, 0, 0, 10, 10, "00:00:00.0") };
    auto s2 = shape("s2", ms2);
    bounds_t s2_bounds = std::make_tuple(0,0,10,10);

    BOOST_CHECK(s2.bounds() == s2_bounds);

    std::vector<mark> ms3 { mark("#000000", 2,  0,  0,  0, 10, "00:00:00.0"),
            mark("#000000", 2,  0, 10, 10, 10, "00:00:00.0"),
            mark("#000000", 2, 10, 10,  0, 10, "00:00:00.0"),
            mark("#000000", 2,  0, 10,  0,  0, "00:00:00.0") };
    auto s3 = shape("s3", ms3);
    bounds_t s3_bounds = std::make_tuple(0,0,10,10);

    BOOST_CHECK(s3.bounds() == s3_bounds);
}
