#include "Patrat.h"

Patrat::Patrat()
{
	this->latura = 0;
	this->arie = 0;
	this->perimetru = 0;
	this->ocupat = false;
	this->x = 0;
	this->y = 0;
}

Patrat::~Patrat()
{
}

Patrat::Patrat(int latura)
{
	this->latura = latura;
	this->arie = latura * latura;
	this->perimetru = 4 * latura;
	this->ocupat = false;
	this->x = 0;
	this->y = 0;
}

int Patrat::getLatura()
{
	return this->latura;
}

void Patrat::setLatura(int latura)
{
	this->latura = latura;
}

int Patrat::getArie()
{
	return this->arie;
}

int Patrat::getPerimetru()
{
	return this->perimetru;
}

bool Patrat::isOcupat()
{
	return this->ocupat;
}

void Patrat::setOcupat(bool ocupat)
{
	this->ocupat = ocupat;
}

void Patrat::setCoordonate(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Patrat::getX()
{
	return this->x;
}

int Patrat::getY()
{
	return this->y;
}

void Patrat::setX(int x)
{
	this->x = x;
}

void Patrat::setY(int y)
{
	this->y = y;
}


