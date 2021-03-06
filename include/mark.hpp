#ifndef MUSAK_MARK_H
#define MUSAK_MARK_H

#include "musak.hpp"
#include "timestamp.hpp"
#include <tuple>
#include <memory>
#include <string>

namespace musak {

    namespace annotations {

        class mark {
        public:
            mark() { tod = nullptr; }
            mark(const mark& m);
            mark(const std::string& c, int p, int sx, int sy,
                 int ex, int ey, const std::string& t) : col(c), pen(p), startX(sx), startY(sy),
                                                         endX(ex), endY(ey),
                                                         tod(std::unique_ptr<timestamp>(new timestamp(t))) { this->length(); };

            mark& operator=(mark& m);

            const point_t start() const;
            const point_t end() const;
            const timestamp& time() const;
            void translateBy(const point_t& offset) noexcept;
            double length() const noexcept;

        private:
            std::string col;
            int pen;
            int startX;
            int startY;
            int endX;
            int endY;
            std::unique_ptr<timestamp> tod;
            mutable bool lenSet;
            mutable double len;

        }; // class mark

    } // namespace annotations

} // namespace musak

#endif
