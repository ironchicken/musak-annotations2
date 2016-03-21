#ifndef MUSAK_MARK_H
#define MUSAK_MARK_H

#include "musak.hpp"
#include <tuple>
#include <memory>
#include <ctime>

namespace musak {

    namespace annotations {

        class mark {
        public:
            mark(const std::string &c, int pen, int startX, int startY, int endX, int endY, const std::string &t);
            ~mark();

            const std::pair<int, int> &start();
            const std::pair<int, int> &end();

        private:
            std::string col;
            int pen;
            int startX;
            int startY;
            int endX;
            int endY;
            std::unique_ptr<tm> tod;

        }; // class mark

    } // namesace annotations

} // namespace musak

#endif
