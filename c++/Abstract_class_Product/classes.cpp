#include "classes.h"

void Computer::Input(istream& is)
{
	is >> price >> mark >> speed >> op;
}

void Computer::Print(ostream& os)
{
	os<< price << " " << mark << " " << speed << " " << op << " ";
}

void Printer::Input(istream& is)
{
	is >> price >> mark >> speed >> amountOfColors;
}

void Printer::Print(ostream& os)
{
	os <<"Printer: " << price << " " << mark << " " << speed << " " << amountOfColors << " ";
}

void Server::Input(istream& is)
{ 
	Computer::Input(is);
	is >> disk;
}

void Server::Print(ostream& os)
{
	os << "Server: ";
	Computer::Print(os);
	os << disk << " ";
}

void Laptop::Input(istream& is)
{
	Computer::Input(is);
	is >> d >> weight;
}

void Laptop::Print(ostream& os)
{
	os << "Laptop: ";
	Computer::Print(os);
	os << d << " " << weight << " ";
}
