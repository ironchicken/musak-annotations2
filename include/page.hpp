#ifndef MUSAK_PAGE_H
#define MUSAK_PAGE_H

#include "musak.hpp"
#include "shape.hpp"
#include <vector>
#include <string>
#include <boost/filesystem.hpp>

namespace musak {

    namespace annotations {

        class page {
        public:
            explicit page(const boost::filesystem::path& f) : sourceFile(f) { this->load(); }
            bool empty() const noexcept;

        private:
            void load();

            std::vector<mark> marks;
            boost::filesystem::path sourceFile;
            static const std::string::size_type minimumFileSize;

        }; // class page

    } // namespace annotations

} // namespace musak

#endif
