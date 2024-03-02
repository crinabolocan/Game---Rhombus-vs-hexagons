#pragma once
#include <random>
#include <ctime>
#include <iostream>
#include <Core/Engine.h>
#include <vector>
#include <math.h>
#include "lab_m1/lab3/object2D.h"

class Star
{
public:
	Star();
	Star(float x, float y, float windowX, float windowY);
	~Star();

	void setX(float x);
	float getX();
	void setY(float y);
	float getY();
	float getAngle();
	void setAngle(float angle);
	void setMesh(Mesh* mesh);
	Mesh* getMesh();
	void setColorStar(glm::vec3 newColor);
	glm::vec3 getColorStar();
	void ClickOnStar(float x, float y, int nr, Star* star, glm::mat3 modelMatrix);
	glm::mat3 Scale(float scaleX, float scaleY);
	glm::mat3 translate(float translateX, float translateY);
	glm::mat3 rotate(float radians);
	void setVisible(bool visible);
	bool getVisible();

	int getColor();
	void setColor(int color);


private:
	int random;
	float x;
	float y;
	Mesh* mesh;
	float angle;
	float windowX;
	float windowY;
	int nr;
	float scaleX;
	float scaleY;
	glm::mat3 modelMatrix;
	float translateX;
	float translateY;
	bool visible;
	int colorValueIndex;
	glm::vec3 color;



};