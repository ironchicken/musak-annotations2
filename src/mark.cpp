#include "musak.hpp"
#include "mark.hpp"
#include <utility>
#include <cmath>

using namespace musak::annotations;

mark::mark(const mark& m) {
    this->col = m.col; this->pen = m.pen; this->startX = m.startX; this->startY = m.startY;
    this->endX = m.endX; this->endY = m.endY;
    tod.reset(new timestamp(*m.tod));
}

mark& mark::operator=(mark& m) {
    this->col = m.col; this->pen = m.pen; this->startX = m.startX; this->startY = m.startY;
    this->endX = m.endX; this->endY = m.endY;
    tod = std::move(m.tod);
    return *this;
}

const point_t mark::start() const {
    return point_t(this->startX, this->startY);
}

const point_t mark::end() const {
    return point_t(this->endX, this->endY);
}

const timestamp& mark::time() const {
    return *(this->tod);
}

void mark::translateBy(const point_t& offset) noexcept {
    this->startX += offset.first;
    this->endX += offset.first;
    this->startY += offset.second;
    this->endY += offset.second;
}

double mark::length() const noexcept {
    return sqrt(pow(abs(this->endX - this->startX), 2) +
                pow(abs(this->endY - this->startY), 2));
}
