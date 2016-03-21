#ifndef MUSAK_DESCRIPTOR_H
#define MUSAK_DESCRIPTOR_H

#include "musak.hpp"
#include "shape.hpp"

namespace musak {

    namespace annotations {

        class descriptor {
        public:
            descriptor(const shape &s);
            virtual ~descriptor();

            virtual double distance(const descriptor &d) = 0;
            virtual double distance(const shape &s) = 0;

        }; // class descriptor

    } // namesace annotations

} // namespace musak

#endif
