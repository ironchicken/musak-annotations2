#include "musak.hpp"
#include "mark.hpp"

using namespace musak::annotations;

const point_t mark::start() const {
    return point_t(this->startX, this->startY);
}

const point_t mark::end() const {
    return point_t(this->endX, this->endY);
}

const timestamp& mark::time() const {
    return *(this->tod);
}
