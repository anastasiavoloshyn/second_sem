#include "Plasm.h"

std::istream& operator>>(std::istream& is, Plasm& p)
{
	is >>p.model>>p.d >> p.resolution >> p.angle;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Plasm& p)
{
	os << "Plasm: " << p.model << " " << p.d << " " << p.resolution << " " << p.angle;
	return os;
}

void Plasm::print(std::ostream& os)
{
	os << "Plasm: " << model<<" " << d<<" " << resolution<<" " << angle;
}

void Plasm::read(std::istream& is)
{
	is >> model >> d >> resolution >> angle;
}
