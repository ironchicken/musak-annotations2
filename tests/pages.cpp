#define BOOST_TEST_MODULE pages
#include <boost/test/unit_test.hpp>
#include "page.hpp"
#include <boost/filesystem.hpp>

using namespace musak::annotations;

BOOST_AUTO_TEST_CASE(page_load_empty)
{
    auto rh_p1 = page(boost::filesystem::path("/path/to/empty.csv"));
    BOOST_CHECK(rh_p1.empty() == true);
}

BOOST_AUTO_TEST_CASE(page_load_nonempty)
{
    auto rh_p2 = page(boost::filesystem::path("/path/to/non-empty.csv"));
    BOOST_CHECK(rh_p2.empty() == false);
}
