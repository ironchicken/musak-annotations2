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
            mark(const mark&) { tod = nullptr; }
            mark(const std::string& c, int p, int sx, int sy,
                 int ex, int ey, const std::string& t) : col(c), pen(p), startX(sx), startY(sy),
                                                         endX(ex), endY(ey),
                                                         tod(std::unique_ptr<timestamp>(new timestamp(t))) { };

            const std::pair<int, int>& start() const;
            const std::pair<int, int>& end() const;

        private:
            std::string col;
            int pen;
            int startX;
            int startY;
            int endX;
            int endY;
            std::unique_ptr<timestamp> tod;

        }; // class mark

    } // namesace annotations

} // namespace musak

#endif
