#include "page.hpp"
#include "timestamp.hpp"
#include "csv.h"
#include <string>
#include <boost/filesystem.hpp>

using namespace musak::annotations;
using namespace boost::filesystem;

const std::string::size_type page::minimumFileSize = std::string("#000000,2,0,0,0,0,00:00:0.0").length();

void page::load() {
    if (file_size(this->sourceFile) < minimumFileSize) { return; }

    io::CSVReader<7> in(this->sourceFile.string());

    std::string col; int pen; int startX; int startY; int endX; int endY; std::string tod;

    while (in.read_row(col, pen, startX, startY, endX, endY, tod)) {
        this->marks.push_back(mark(col, pen, startX, startY, endX, endY, tod));
    }
}

bool page::empty() const noexcept {
    return this->marks.empty();
}
