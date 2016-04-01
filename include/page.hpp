#ifndef MUSAK_PAGE_H
#define MUSAK_PAGE_H

#include "musak.hpp"
#include "shape.hpp"
#include <vector>

namespace musak {

    namespace annotations {

        class page {
        public:
            page (const std::vector<mark>& marks, const std::string& sourceFile);
           ~page();
            bool empty();
            void load();

        private:
            std::vector<mark> marks;
            std::string sourceFile;
        }; // class page

    } // namespace annotations

} // namespace musak

#endif
