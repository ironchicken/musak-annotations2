#define BOOST_TEST_MODULE shapes
#include <boost/test/unit_test.hpp>
#include "shape.hpp"
#include "mark.hpp"
#include <vector>
#include <tuple>

using namespace musak::annotations;

BOOST_AUTO_TEST_CASE(shape_create_empty)
{
    auto s = shape();
    BOOST_CHECK(s.empty() == true);
}

BOOST_AUTO_TEST_CASE(shape_create_nonempty)
{
    std::vector<mark> ms { mark("#000000", 2, 0, 0, 10, 10, "00:00:00.0") };
    auto s = shape("s", ms);

    BOOST_CHECK(s.empty() == false);
}

BOOST_AUTO_TEST_CASE(shape_bounds_zero)
{
    auto s = shape();
    BOOST_CHECK(s.bounds() == zero_bounds);
}

BOOST_AUTO_TEST_CASE(shape_bounds_line)
{
    std::vector<mark> ms { mark("#000000", 2, 0, 0, 10, 10, "00:00:00.0") };
    auto s = shape("s", ms);
    bounds_t s_bounds = std::make_tuple(0,0,10,10);

    BOOST_CHECK(s.bounds() == s_bounds);
}

BOOST_AUTO_TEST_CASE(shape_bounds_square)
{
    std::vector<mark> ms { mark("#000000", 2,  0,  0,  0, 10, "00:00:00.0"),
            mark("#000000", 2,  0, 10, 10, 10, "00:00:00.0"),
            mark("#000000", 2, 10, 10,  0, 10, "00:00:00.0"),
            mark("#000000", 2,  0, 10,  0,  0, "00:00:00.0") };
    auto s = shape("s", ms);
    bounds_t s_bounds = std::make_tuple(0,0,10,10);

    BOOST_CHECK(s.bounds() == s_bounds);
}

BOOST_AUTO_TEST_CASE(shape_size_diag)
{
    std::vector<mark> ms { mark("#000000", 2, 0, 0, 10, 10, "00:00:00.0") };
    auto s = shape("s", ms);
    point_t s_size = std::make_pair(10, 10);

    BOOST_CHECK(s.size() == s_size);
}

BOOST_AUTO_TEST_CASE(shape_size_vertical)
{
    std::vector<mark> ms { mark("#000000", 2, 0, 0, 0, 10, "00:00:00.0") };
    auto s = shape("s", ms);
    point_t s_size = std::make_pair(1, 10);

    BOOST_CHECK(s.size() == s_size);
}

BOOST_AUTO_TEST_CASE(shape_size_square)
{
    std::vector<mark> ms { mark("#000000", 2,  0,  0,  0, 10, "00:00:00.0"),
            mark("#000000", 2,  0, 10, 10, 10, "00:00:00.0"),
            mark("#000000", 2, 10, 10,  0, 10, "00:00:00.0"),
            mark("#000000", 2,  0, 10,  0,  0, "00:00:00.0") };
    auto s = shape("s", ms);
    point_t s_size = std::make_pair(10, 10);

    BOOST_CHECK(s.size() == s_size);
}
