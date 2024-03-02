#pragma once
#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"

class Patrat
{
public:
	Patrat();
	Patrat(int latura);
	~Patrat();

	//create square 
	Mesh* CreateSquare(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
	int getLatura();
	void setLatura(int latura);
	int getArie();
	int getPerimetru();
	bool isOcupat();
	void setOcupat(bool ocupat);
	void setCoordonate(int x, int y);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);


private:
	int latura;
	int arie;
	int perimetru;
	bool ocupat;
	int x;
	int y;

};

#pragma once
