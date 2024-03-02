#include "Square.h"

Square::Square()
{
	mesh = new Mesh("square");
}

Square::Square(int latura)
{
	this->latura = latura;
}

Square::~Square()
{
	delete mesh;
}

int Square::getX()
{
	return this->x;
}

int Square::getY()
{
	return this->y;
}

void Square::setX(int x)
{
	this->x = x;
}

void Square::setY(int y)
{
	this->y = y;
}

void Square::setMesh(Mesh* mesh)
{
	this->mesh = mesh;
}

Mesh* Square::getMesh()
{
	return this->mesh;
}

glm::mat3 Square::translate(float translateX, float translateY)
{
	return glm::transpose(glm::mat3(1, 0, translateX,
		0, 1, translateY,
		0, 0, 1));
}
