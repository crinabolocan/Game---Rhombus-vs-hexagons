#include "Hexagon.h"
#include "lab_m1/lab3/object2D.h"

Hexagon::Hexagon()
{
	mesh = new Mesh("hexagon");

}

Hexagon::~Hexagon()
{
	delete mesh;
}

void::Hexagon::setMesh(Mesh* mesh)
{
	this->mesh = mesh;
}

Mesh* Hexagon::getMesh()
{
	return mesh;
}

void Hexagon::setX(float x)
{
	this->x = x;
}

float Hexagon::getX()
{
	return x;
}

void Hexagon::setY(float y)
{
	this->y = y;
}

float Hexagon::getY()
{
	return y;
}

void Hexagon::setAngle(float angle)
{
	this->angle = angle;
}

float Hexagon::getAngle()
{
	return angle;
}



float Hexagon::getRadius()
{
	return radius;
}

void Hexagon::setLives(int lives)
{
	this->lives = lives;
}

float Hexagon::getLives()
{
	return lives;
}


int Hexagon::getColor()
{
	return colorValueIndex;
}


void Hexagon::setColor(int color)
{
	this->colorValueIndex = color;
}

void Hexagon::setColorHex(glm::vec3 newColor)
{
	this->color = newColor;
}

glm::vec3 Hexagon::getColorHex()
{
	return color;
}

bool Hexagon::inCollision(Hexagon* hexagon)
{
	return false;
}

glm::mat3 Hexagon::translate(float translateX, float translateY)
{
	return glm::transpose(glm::mat3(1, 0, translateX,
		0, 1, translateY,
		0, 0, 1));
}

glm::mat3 Hexagon::scale(float scaleX, float scaleY)
{
	return glm::mat3(scaleX, 0, 0,
		0, scaleY, 0,
		0, 0, 1);
}