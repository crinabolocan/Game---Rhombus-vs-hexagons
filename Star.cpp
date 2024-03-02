#include "Star.h"

Star::Star()
{
}

Star::Star(float x, float y, float windowX, float windowY)
{
	this->x = x;
	this->y = y;
	this->windowX = windowX;
	this->windowY = windowY;
}

Star::~Star()
{
}

void Star::setX(float x)
{
	this->x = x;
}

float Star::getX()
{
	return x;
}

void Star::setY(float y)
{
	this->y = y;
}

float Star::getY()
{
	return y;
}

void Star::setAngle(float angle)
{
	this->angle = angle;
}

float Star::getAngle()
{
	return angle;
}

void Star::setMesh(Mesh* mesh)
{
	this->mesh = mesh;
}

Mesh* Star::getMesh()
{
	return mesh;
}

void Star::setColorStar(glm::vec3 newColor)
{
	this->color = newColor;
}

glm::vec3 Star::getColorStar()
{
	return color;
}

void Star::ClickOnStar(float x, float y, int nr, Star* star, glm::mat3 modelMatrix)
{
	nr++;
	std::cout << "Click on star" << std::endl;
	modelMatrix *= Scale(0.5f, 0.5f);

}

glm::mat3 Star::Scale(float scaleX, float scaleY)
{
	return glm::transpose(glm::mat3(scaleX, 0, 0,
		0, scaleY, 0,
		0, 0, 1));
}

glm::mat3 Star::translate(float translateX, float translateY)
{
	return glm::transpose(glm::mat3(1, 0, translateX,
		0, 1, translateY,
		0, 0, 1));
}

// Rotate matrix
glm::mat3 Star::rotate(float radians)
{
	// TODO(student): Implement the rotation matrix
	//return glm::mat3(1);
	return glm::mat3(cos(radians), -sin(radians), 0,
		sin(radians), cos(radians), 0,
		0, 0, 1);
}

void Star::setVisible(bool visible)
{
	this->visible = visible;
}

bool Star::getVisible()
{
	return visible;
}


int Star::getColor()
{
	return colorValueIndex;
}

void Star::setColor(int color)
{
	this->colorValueIndex = color;
}


