#include "Romb.h"

Romb::Romb()
{
	//mesh
	mesh = new Mesh("romb");
}

Romb::~Romb()
{
	delete mesh;
}

Romb::Romb(int latura)
{
	this->latura = latura;
	//mesh
	mesh = new Mesh("romb");
}

int Romb::getLatura()
{
	return this->latura;
}

void Romb::setLatura(int latura)
{
	this->latura = latura;
}

int Romb::getArie()
{
	return this->arie;
}

int Romb::getPerimetru()
{
	return this->perimetru;
}

bool Romb::isHit(int x, int y)
{
	if (x >= this->x && x <= this->x + this->latura && y >= this->y && y <= this->y + this->latura)
	{
		return true;
	}
	return false;
}

bool Romb::isHit()
{
	return this->hit;
}

void Romb::setHit(bool hit)
{
	this->hit = hit;
}

void Romb::setCoordonate(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Romb::getX()
{
	return this->x;
}

int Romb::getY()
{
	return this->y;
}

void Romb::setX(int x)
{
	this->x = x;
}

void Romb::setY(int y)
{
	this->y = y;
}

bool Romb::isdelete()
{
	return this->del;
}

void Romb::setdelete(bool del)
{
	this->del = del;
}

void Romb::startDrag(int x, int y)
{
	drag = true;
	this->x = x;
	this->y = y;
}

void Romb::updateDrag(int x, int y)
{
	drag = true;
	this->x = x;
	this->y = y;
}

void Romb::stopDrag()
{
	drag = false;
}

bool Romb::isDragged()
{
	return drag;
}

void Romb::setDragged(bool drag)
{
	this->drag = drag;
}

void Romb::setMesh(Mesh* mesh)
{
	this->mesh = mesh;
}

Mesh* Romb::getMesh()
{
	return mesh;
}

void Romb::setColorIndex(int colorIndex)
{
	this->colorIndex = colorIndex;
}

int Romb::getColorIndex()
{
	return colorIndex;
}

void Romb::setColorRomb(glm::vec3 newColor)
{
	this->color = newColor;
}

glm::vec3 Romb::getColorRomb()
{
	return this->color;
}





