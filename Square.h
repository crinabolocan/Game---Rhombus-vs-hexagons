#pragma once

#include "lab_m1/lab3/object2D.h"

class Square 
{
	public:
	Square();
	Square(int latura);
	~Square();

	int getX();
	int getY();
	void setX(int x);
	void setY(int y);

	void setMesh(Mesh* mesh);
	Mesh* getMesh();

	glm::mat3 translate(float translateX, float translateY);

private:
	int x;
	int y;
	Mesh* mesh;
	int latura;
};