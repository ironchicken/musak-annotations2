#ifndef MUSAK_H
#define MUSAK_H
#include <tuple>

namespace musak {

    namespace annotations {
        using bounds_t = std::tuple<const int&, const int&, const int&, const int&>;
        using point_t = std::pair<const int&, const int&>;

    } // namespace annotations

} // namespace musak

#endif
