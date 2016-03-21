#ifndef MUSAK_SHAPE_H
#define MUSAK_SHAPE_H

#include "musak.hpp"
#include "mark.hpp"
#include <vector>
#include <tuple>

namespace musak {

    namespace annotations {

        class shape {
        public:
            shape();
            shape(std::string &id, std::vector<mark> &marks);
            ~shape();

            bool                                 empty();
            const std::tuple<int, int, int, int> &bounds();
            const std::pair<int, int>            &size();
            const std::pair<int, int>            &offset();
            void                                 translateTo(const std::pair<int, int> &offset);
            double                               length();
            double                               perimeter();

        private:
            std::string id;
            std::vector<mark> marks;

        }; // class shape

    } // namesace annotations

} // namespace musak

#endif
