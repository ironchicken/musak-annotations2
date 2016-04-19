#define BOOST_TEST_MODULE marks
#include <boost/test/unit_test.hpp>
#include "mark.hpp"

using namespace musak::annotations;

BOOST_AUTO_TEST_CASE(mark_create)
{
    auto m = mark("#000000", 3, 0, 0, 10, 10, "08:54:12.490");
    auto ts_value = hms_t(8, 54, 12, 490);
    BOOST_CHECK(m.time().get_hms() == ts_value);
}
