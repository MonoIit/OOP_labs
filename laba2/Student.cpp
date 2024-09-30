#include "Student.h"
#include "tools.h"


void SmirnovStudent::create()
{
    SmirnovHuman::create();
    std::cout << "Enter university" << std::endl;
    university = read_string();
    std::cout << "Enter pass" << std::endl;
    pass = input_value<int>(1, 999999);
}


template<class Archive>
void SmirnovStudent::serialize(Archive& ar, const unsigned int version)
{
    ar & boost::serialization::base_object<SmirnovHuman>(*this);

    ar & university;
    ar & pass;
}


void SmirnovStudent::print(std::ostream& out) const
{
    SmirnovHuman::print(out);
    out << "university: " << university << std::endl;
    out << "pass: " << pass << std::endl;
}

BOOST_CLASS_EXPORT(SmirnovStudent)