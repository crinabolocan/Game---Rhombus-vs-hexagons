#pragma once
#include "lab_m1/lab3/object2D.h"

class Hexagon
{
public:
	Hexagon();
	Hexagon(float x, float y, float windowX, float windowY);
	~Hexagon();

	void setMesh(Mesh* mesh);
	Mesh* getMesh();
	bool inCollision(Hexagon* hexagon);
	void setX(float x);
	void setY(float y);
	float getX();
	float getY();
	float getAngle();
	float getRadius();
	void setLives(int lives);
	float getLives();

	int getColor();
	void setColor(int color);

	void setColorHex(glm::vec3 newColor);

	glm::vec3 getColorHex();

	void setAngle(float angle);
	glm::mat3 translate(float translateX, float translateY);
	
	glm::mat3 scale(float scaleX, float scaleY);

private:
	Mesh* mesh;
	float x;
	float y;
	float windowX;
	float windowY;
	float angle;
	float spawnTimer; // Un timer pentru a controla când să apară hexagonul
	float spawnInterval;
	float translateX;
	float translateY;
	float hitY;
	float scaleX;
	float scaleY;
	float radius;
	int colorValueIndex;
	glm::vec3 color;
	int lives = 3;



};