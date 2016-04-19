#include "musak.hpp"
#include "shape.hpp"

using namespace musak::annotations;

bool shape::empty() const noexcept {
    return this->marks.empty();
}

const bounds_t shape::bounds() const noexcept {
    if (this->empty()) { return zero_bounds; }

    auto left = 0; auto top = 0; auto right = 0; auto bottom = 0;
    for (auto& m : this->marks) {
        auto s = m.start();
        auto e = m.end();

        auto min_x = std::min(s.first, e.first);
        if (min_x < left) { left = min_x; }

        auto max_x = std::max(s.first, e.first);
        if (max_x > right) { right = max_x; }

        auto min_y = std::min(s.second, e.second);
        if (min_y < top) { top = min_y; }

        auto max_y = std::max(s.second, e.second);
        if (max_y > bottom) { bottom = max_y; }
    }

    return std::make_tuple(left, top, right, bottom);
}
