#ifndef MUSAK_SHAPE_H
#define MUSAK_SHAPE_H

#include "musak.hpp"
#include "mark.hpp"
#include <vector>

namespace musak {

    namespace annotations {

        class shape {
        public:
            shape() { };
            shape(const std::string& i, const std::vector<mark>& m) : id(i), marks(m) { };

            bool           empty() const noexcept;
            const bounds_t bounds() const noexcept;
            const point_t  size() const noexcept;
            const point_t  offset() const noexcept;
            void           translateTo(const point_t& offset) noexcept;
            double         perimeter() const noexcept;

        private:
            std::string id;
            std::vector<mark> marks;

        }; // class shape

    } // namespace annotations

} // namespace musak

#endif
