#ifndef MUSAK_SHAPE_H
#define MUSAK_SHAPE_H

#include "musak.hpp"
#include "mark.hpp"
#include <vector>
#include <tuple>

namespace musak {

    namespace annotations {

        typedef std::tuple<int, int, int, int> bounds_t;
        typedef std::pair<int, int> point_t;

        class shape {
        public:
            shape();
            shape(std::string& id, std::vector<mark>& marks);
           ~shape();

            bool            empty();
            const bounds_t& bounds();
            const point_t&  size();
            const point_t&  offset();
            void            translateTo(const point_t& offset);
            double          length();
            double          perimeter();

        private:
            std::string id;
            std::vector<mark> marks;

        }; // class shape

    } // namesace annotations

} // namespace musak

#endif
