#define BOOST_TEST_MODULE shapes
#include <boost/test/unit_test.hpp>
#define private public // kludge to allow testing of private members
#include "shape.hpp"
#include "mark.hpp"
#define private private
#include <vector>
#include <tuple>
#include <algorithm>

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

BOOST_AUTO_TEST_CASE(shape_bounds_offset_square)
{
    std::vector<mark> ms { mark("#000000", 2,  5,  5,  5, 10, "00:00:00.0"),
            mark("#000000", 2,  5, 10, 10, 10, "00:00:00.0"),
            mark("#000000", 2, 10, 10,  5, 10, "00:00:00.0"),
            mark("#000000", 2,  5, 10,  5,  5, "00:00:00.0") };
    auto s = shape("s", ms);
    bounds_t s_bounds = std::make_tuple(5,5,10,10);

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

BOOST_AUTO_TEST_CASE(shape_offset)
{
    std::vector<mark> ms { mark("#000000", 2,  5,  5,  5, 10, "00:00:00.0"),
            mark("#000000", 2,  5, 10, 10, 10, "00:00:00.0"),
            mark("#000000", 2, 10, 10,  5, 10, "00:00:00.0"),
            mark("#000000", 2,  5, 10,  5,  5, "00:00:00.0") };
    auto s = shape("s", ms);
    point_t s_offset = std::make_pair(5, 5);

    BOOST_CHECK(s.offset() == s_offset);
}

BOOST_AUTO_TEST_CASE(shape_translate)
{
    std::vector<mark> ms { mark("#000000", 2, 0, 0, 10, 10, "00:00:00.0") };
    auto s = shape("s", ms);
    point_t s_translation = std::make_pair(5, 5);
    s.translateBy(s_translation);
    point_t s_newOffs = std::make_pair(5, 5);

    BOOST_CHECK(s.offset() == s_newOffs);
}

BOOST_AUTO_TEST_CASE(shape_translate_square)
{
    std::vector<mark> ms { mark("#000000", 2,  5,  5,  5, 10, "00:00:00.0"),
            mark("#000000", 2,  5, 10, 10, 10, "00:00:00.0"),
            mark("#000000", 2, 10, 10,  5, 10, "00:00:00.0"),
            mark("#000000", 2,  5, 10,  5,  5, "00:00:00.0") };
    auto s = shape("s", ms);
    point_t s_translation = std::make_pair(-5, -5);
    s.translateBy(s_translation);
    point_t s_newOffs = std::make_pair(0, 0);

    BOOST_CHECK(s.offset() == s_newOffs);
}

BOOST_AUTO_TEST_CASE(shape_perimeter_zero)
{
    auto s = shape("s", {});

    BOOST_CHECK(s.perimeter() == 0.0);
}

BOOST_AUTO_TEST_CASE(shape_perimeter_line)
{
    std::vector<mark> ms { mark("#000000", 2, 0, 0, 10, 0, "00:00:00.0") };
    auto s = shape("s", ms);

    BOOST_CHECK(s.perimeter() == 10.0);
}

BOOST_AUTO_TEST_CASE(shape_perimeter_square)
{
    std::vector<mark> ms { mark("#000000", 2,  5,  5,  5, 10, "00:00:00.0"),
            mark("#000000", 2,  5, 10, 10, 10, "00:00:00.0"),
            mark("#000000", 2, 10, 10,  5, 10, "00:00:00.0"),
            mark("#000000", 2,  5, 10,  5,  5, "00:00:00.0") };
    auto s = shape("s", ms);

    BOOST_CHECK(s.perimeter() == 20.0);
}

BOOST_AUTO_TEST_CASE(shape_scaled_edges_zero)
{
    auto s = shape("s", {});
    s.setScaledEdges();

    BOOST_CHECK(s.scaledEdges.empty() == true);
}

BOOST_AUTO_TEST_CASE(shape_scaled_edges_line)
{
    std::vector<mark> ms { mark("#000000", 2, 0, 0, 10, 0, "00:00:00.0") };
    auto s = shape("s", ms);
    s.setScaledEdges();
    std::vector<double> scaledEdges { 1.0 };

    BOOST_CHECK(std::equal(s.scaledEdges.begin(), s.scaledEdges.end(), scaledEdges.begin()));
}

BOOST_AUTO_TEST_CASE(shape_scaled_edges_square)
{
    std::vector<mark> ms { mark("#000000", 2,  5,  5,  5, 10, "00:00:00.0"),
            mark("#000000", 2,  5, 10, 10, 10, "00:00:00.0"),
            mark("#000000", 2, 10, 10,  5, 10, "00:00:00.0"),
            mark("#000000", 2,  5, 10,  5,  5, "00:00:00.0") };
    auto s = shape("s", ms);
    s.setScaledEdges();
    std::vector<double> scaledEdges { 0.25, 0.25, 0.25, 0.25 };

    BOOST_CHECK(std::equal(s.scaledEdges.begin(), s.scaledEdges.end(), scaledEdges.begin()));
}
