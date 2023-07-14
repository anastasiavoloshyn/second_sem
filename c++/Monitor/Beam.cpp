#include "Beam.h"

std::istream& operator>>(std::istream& is, Beam& b)
{
    is >>b.model>>b.d>> b.frequency >> b.radiation;
    return is;
}

std::ostream& operator<<(std::ostream& os, Beam& b)
{
    os << "Beam:" << " " << b.model << " " << b.d << " " << b.frequency << " " << b.radiation << " ";
    return os;
}

void Beam::print(std::ostream& os)
{
    os << "Beam:" << " " << model << " " << d << " " << frequency << " " << radiation << " ";
}

void Beam::read(std::istream& is)
{
    is >> model >> d >> frequency >> radiation;
}
