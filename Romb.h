#pragma once
#include "lab_m1/lab3/object2D.h"

class Romb
{
public:
	Romb();
	Romb(int latura);
	~Romb();

	int getLatura();
	void setLatura(int latura);
	int getArie();
	int getPerimetru();
	bool isHit(int x, int y);
	bool isHit();
	void setHit(bool hit);
	void setCoordonate(int x, int y);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	bool isdelete();
	void setdelete(bool del);
	void startDrag(int x, int y);
	void updateDrag(int x, int y);
	void stopDrag();
	bool isDragged();
	void setDragged(bool drag);

	void setMesh(Mesh* mesh);
	Mesh* getMesh();

	void setColorIndex(int colorIndex);
	int getColorIndex();

	void setColorRomb(glm::vec3 newColor);
	glm::vec3 getColorRomb();


private:
	int latura;
	int arie;
	int perimetru;
	bool hit;
	int x;
	int y;
	bool del;
	bool drag;
	Mesh* mesh;
	int colorIndex;
	glm::vec3 color;

};

#pragma once
