#include "musak.hpp"
#include "shape.hpp"
#include <tuple>

using namespace musak::annotations;

bool shape::empty() const noexcept {
    return this->marks.empty();
}

inline const int getLeft(bounds_t& bnds) { return std::get<0>(bnds); }
inline const int getTop(bounds_t& bnds) { return std::get<1>(bnds); }
inline const int getRight(bounds_t& bnds) { return std::get<2>(bnds); }
inline const int getBottom(bounds_t& bnds) { return std::get<3>(bnds); }

const bounds_t shape::bounds() const noexcept {
    if (this->empty()) { return zero_bounds; }

    auto m0 = this->marks[0];
    auto left = m0.start().first; auto top = m0.start().second;
    auto right = m0.end().first; auto bottom = m0.end().second;

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

const point_t shape::size() const noexcept {
    auto bnds = this->bounds();
    auto width = std::abs(getLeft(bnds) - getRight(bnds));
    auto height = std::abs(getTop(bnds) - getBottom(bnds));

    if (width < 1) width = 1;
    if (height < 1) height = 1;

    return std::make_pair(width, height);
}

const point_t shape::offset() const noexcept {
    auto bnds = this->bounds();

    return std::make_pair(getLeft(bnds), getTop(bnds));
}
