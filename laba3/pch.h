// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#include <QString>
#include <vector>
#include <fstream>


// #define BOOST_SERIALIZATION_DYN_LINK

#include <boost/serialization/base_object.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/access.hpp>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/shared_ptr.hpp>

#include <boost/serialization/version.hpp>
#include <boost/serialization/split_member.hpp>

using namespace std;

namespace boost {
namespace serialization {

// Шаблонная функция сериализации для QString
template<class Archive>
void serialize(Archive &ar, QString &s, const unsigned int version) {
    std::string temp = s.toStdString();
    ar & temp;
    s = QString::fromStdString(temp);
}

}
}

#endif //PCH_H
