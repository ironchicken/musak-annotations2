#ifndef MUSAK_H
#define MUSAK_H
#include <tuple>
#include <ostream>

namespace musak {

    namespace annotations {
        using bounds_t = std::tuple<int, int, int, int>;
        using point_t = std::pair<int, int>;

        inline std::ostream& operator<<(std::ostream& st, const bounds_t& b) {
            st << "(" << std::get<0>(b) << "," << std::get<1>(b) << "," << std::get<2>(b) << "," << std::get<3>(b) << ")";
        }

        inline std::ostream& operator<<(std::ostream& st, const point_t& p) {
            st << "(" << p.first << "," << p.second << ")";
        }

        constexpr bounds_t zero_bounds(std::make_tuple(0,0,0,0));
        constexpr point_t origin(std::make_pair(0,0));

    } // namespace annotations

} // namespace musak

#endif
