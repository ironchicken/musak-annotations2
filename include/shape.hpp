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
            void           translateBy(const point_t& offset) noexcept;
            double         perimeter() const noexcept;
            void           setScaledEdges() noexcept;

        private:
            std::string id;
            std::vector<mark> marks;
            mutable bool perimSet;
            mutable double perim;
            std::vector<double> scaledEdges;

        }; // class shape

    } // namespace annotations

} // namespace musak

#endif
