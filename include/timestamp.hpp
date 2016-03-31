#ifndef H_MUSAK_TIMESTAMP
#define H_MUSAK_TIMESTAMP

#include "musak.hpp"
#include <string>

namespace musak {

    namespace annotations {

        class timestamp {
        public:
            timestamp(const std::string &ts);
            timestamp(const int h, const int m, const int s, const int ms);
           ~timestamp();

        private:
            int hours;
            int minutes;
            int seconds;
            int milliseconds;

        }; // timestamp class

    } // namesace annotations

} // namespace musak

#endif
