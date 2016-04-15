#ifndef MUSAK_H
#define MUSAK_H
#include <tuple>

namespace musak {

    namespace annotations {
        using bounds_t = std::tuple<int, int, int, int>;
        using point_t = std::pair<int, int>;

        constexpr bounds_t zero_bounds(std::make_tuple(0,0,0,0));
        constexpr point_t origin(std::make_pair(0,0));

    } // namespace annotations

} // namespace musak

#endif
