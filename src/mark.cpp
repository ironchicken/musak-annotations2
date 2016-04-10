#include "mark.hpp"

using namespace musak::annotations;

const std::pair<const int&, const int&> mark::start() const {
    return std::pair<const int&, const int&>(this->startX, this->startY);
}

const std::pair<const int&, const int&> mark::end() const {
    return std::pair<const int&, const int&>(this->endX, this->endY);
}
