#include "lab_m1/Tema1/Tema1.h"

#include <vector>
#include <iostream>

#include "lab_m1/lab3/object2D.h"
#include "lab_m1/lab3/transform2D.h"
#include "lab_m1/Tema1/Patrat.h"
#include "lab_m1/Tema1/Romb.h"
#include "lab_m1/Tema1/Hexagon.h"
#include "lab_m1/Tema1/Star.h"
#include "lab_m1/Tema1/Square.h"
#include <components/camera_input.h>
#include <random>
#include <ctime>
#include <windows.h>

std::default_random_engine generator;
std::uniform_real_distribution<float> distribution(100, 200); // Intervalul ales aleatoriu între mișcări


using namespace std;
using namespace m1;

string obiect;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */



Tema1::Tema1()
{

}


Tema1::~Tema1()
{
}


void Tema1::Init()
{
	glm::ivec2 resolution = window->GetResolution(true);

	auto camera = GetSceneCamera();
	resolution.x = 1280;
	resolution.y = 720;
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	translateX = 0;
	translateY = 0;

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> distribution(100, 500);

	std::default_random_engine generator;


	std::uniform_real_distribution<float> intervalDistribution(1.0f, 3.0f); // Interval aleatoriu între apariții în secunde
	float timeSinceLastAppearance = 0.0f; // Inițial, timpul scurs de la ultima apariție este 0

	glm::vec3 corner = glm::vec3(0, 0, 0);
	float squareSide = 125;
	float hexagonSide = 80;
	randomint = 0;
	timeSinceLastHexagonSpawn = 0.0f;
	hexagonSpawnInterval = 2.0f;
	srand(time(nullptr));
	hexagonsNumber = 10;
	speed.resize(hexagonsNumber);
	i = 0;

	for (int i = 0; i < squaresOcuppation.size(); i++)
	{
		squaresOcuppation[i] = -1;
	}

	Mesh* rectangle = object2D::CreateRectangle("Rectangle", glm::vec3(10, 10, 0), 70, 450, glm::vec3(1, 0, 0), true);
	AddMeshToList(rectangle);

	Mesh* square1 = object2D::CreateSquare("square1", glm::vec3(105, 10, 0), squareSide, glm::vec3(0, 0.51, 0), true);
	AddMeshToList(square1);

	Mesh* square2 = object2D::CreateSquare("square2", glm::vec3(105, 172.5, 0), squareSide, glm::vec3(0, 0.51, 0), true);
	AddMeshToList(square2);

	Mesh* square3 = object2D::CreateSquare("square3", glm::vec3(105, 335, 0), squareSide, glm::vec3(0, 0.51, 0), true);
	AddMeshToList(square3);

	Mesh* square4 = object2D::CreateSquare("square4", glm::vec3(267.5, 10, 0), squareSide, glm::vec3(0, 0.51, 0), true);
	AddMeshToList(square4);

	Mesh* square5 = object2D::CreateSquare("square5", glm::vec3(267.5, 172.5, 0), squareSide, glm::vec3(0, 0.51, 0), true);
	AddMeshToList(square5);

	Mesh* square6 = object2D::CreateSquare("square6", glm::vec3(267.5, 335, 0), squareSide, glm::vec3(0, 0.51, 0), true);
	AddMeshToList(square6);

	Mesh* square7 = object2D::CreateSquare("square7", glm::vec3(430, 10, 0), squareSide, glm::vec3(0, 0.51, 0), true);
	AddMeshToList(square7);

	Mesh* square8 = object2D::CreateSquare("square8", glm::vec3(430, 172.5, 0), squareSide, glm::vec3(0, 0.51, 0), true);
	AddMeshToList(square8);

	Mesh* square9 = object2D::CreateSquare("square9", glm::vec3(430, 335, 0), squareSide, glm::vec3(0, 0.51, 0), true);
	AddMeshToList(square9);

	glm::vec3 centerchenar = glm::vec3(70, 585, 0);
	glm::vec3 colorchenar = glm::vec3(1, 0, 0);
	Mesh* chenar = object2D::CreateSquare("chenar1", centerchenar, squareSide, colorchenar, false);
	AddMeshToList(chenar);

	centerchenar = glm::vec3(245, 585, 0);
	colorchenar = glm::vec3(1, 1, 0);
	chenar = object2D::CreateSquare("chenar2", centerchenar, squareSide, colorchenar, false);
	AddMeshToList(chenar);

	centerchenar = glm::vec3(420, 585, 0);
	colorchenar = glm::vec3(0, 0, 1);
	chenar = object2D::CreateSquare("chenar3", centerchenar, squareSide, colorchenar, false);
	AddMeshToList(chenar);

	centerchenar = glm::vec3(595, 585, 0);
	colorchenar = glm::vec3(0, 1, 0);
	chenar = object2D::CreateSquare("chenar4", centerchenar, squareSide, colorchenar, false);
	AddMeshToList(chenar);

	Mesh* rombdrept = object2D::CreateRombcudreptunghi("rombdrept1", glm::vec3(132.5, 647.5, 0), glm::vec3(600, 587.5, 0), 50, 50, glm::vec3(1, 0, 0), true);
	AddMeshToList(rombdrept);

	rombdrept = object2D::CreateRombcudreptunghi("rombdrept2", glm::vec3(307.5, 647.5, 0), glm::vec3(600, 587.5, 0), 50, 50, glm::vec3(1, 1, 0), true);
	AddMeshToList(rombdrept);

	rombdrept = object2D::CreateRombcudreptunghi("rombdrept3", glm::vec3(482.5, 647.5, 0), glm::vec3(600, 587.5, 0), 50, 50, glm::vec3(0, 0, 1), true);
	AddMeshToList(rombdrept);

	rombdrept = object2D::CreateRombcudreptunghi("rombdrept4", glm::vec3(657.5, 647.5, 0), glm::vec3(600, 587.5, 0), 50, 50, glm::vec3(0, 1, 0), true);
	AddMeshToList(rombdrept);

	Mesh* star = object2D::CreateStar("Star1", glm::vec3(75, 565, 0), 15, glm::vec3(1, 1, 0), true);
	AddMeshToList(star);

	star = object2D::CreateStar("Star2", glm::vec3(250, 565, 0), 15, glm::vec3(1, 1, 0), true);
	AddMeshToList(star);

	star = object2D::CreateStar("Star3", glm::vec3(290, 565, 0), 15, glm::vec3(1, 1, 0), true);
	AddMeshToList(star);

	star = object2D::CreateStar("Star4", glm::vec3(425, 565, 0), 15, glm::vec3(1, 1, 0), true);
	AddMeshToList(star);

	star = object2D::CreateStar("Star5", glm::vec3(465, 565, 0), 15, glm::vec3(1, 1, 0), true);
	AddMeshToList(star);

	star = object2D::CreateStar("Star6", glm::vec3(600, 565, 0), 15, glm::vec3(1, 1, 0), true);
	AddMeshToList(star);
	star = object2D::CreateStar("Star7", glm::vec3(640, 565, 0), 15, glm::vec3(1, 1, 0), true);
	AddMeshToList(star);
	star = object2D::CreateStar("Star8", glm::vec3(680, 565, 0), 15, glm::vec3(1, 1, 0), true);
	AddMeshToList(star);

	int columnindex = std::rand() % window->GetResolution().x;
	int lineindex = std::rand() % window->GetResolution().y;


	glm::vec3 center = glm::vec3(window->GetResolution().x, 72.5, 0);

	timeSinceLastAppearance = 0.0f; // Inițial, timpul scurs de la ultima apariție este 0
	float deltaTime = 2.0f;
	timeSinceLastAppearance += deltaTime;

}

void Tema1::FrameStart()
{
	// Clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// Sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}


void Tema1::SpawnStarsOnScreen() {
	Star* starrandom = new Star();

	glm::vec3 colorStar = glm::vec3(1, 1, 0);

	std::uniform_real_distribution<float> xDistribution(0, 1280); // random x generator
	float xPosition = xDistribution(generator);

	std::uniform_real_distribution<float> yDistribution(0, 720); // random y generator
	float yPosition = yDistribution(generator);

	starrandom->setX(xPosition);
	starrandom->setY(yPosition);
	starrandom->setMesh(object2D::CreateStar("star", glm::vec3(starrandom->getX(), starrandom->getY(), 1), 30, colorStar, true));
	starsOnScreen.push_back(starrandom);

}


void Tema1::SpawnHexagon() {
	Hexagon* hexagon = new Hexagon();

	//HWND hWnd = GetActiveWindow();

	/*RECT rect;
	if (GetWindowRect(hWnd, &rect))
	{
		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;
		windowResolutionX =  int(width);
	}*/

	//hexagon->setX(windowResolutionX); //#TODO  remove after test
	//hexagon->setX(window->GetResolution().x / 2); //#TODO  remove after test
	hexagon->setX(1280); //#TODO  remove after test


	glm::vec3 colorHex = glm::vec3(0, 0, 0);

	std::uniform_real_distribution<float> colorDistribution(0.0f, 4.0f); // random color generator
	int colorRandom = floor(colorDistribution(generator));

	switch (colorRandom)
	{
	case 0:
		colorHex = glm::vec3(1, 0, 0);
		hexagon->setColor(0);
		break;
	case 1:
		colorHex = glm::vec3(1, 1, 0);
		hexagon->setColor(1);
		break;
	case 2:
		colorHex = glm::vec3(0, 0, 1);
		hexagon->setColor(2);
		break;
	case 3:
		colorHex = glm::vec3(0, 1, 0);
		hexagon->setColor(3);
		break;
	default:
		colorHex = glm::vec3(0, 1, 0);
		hexagon->setColor(3);
		break;
	}

	std::uniform_real_distribution<float> lineDistribution(0.0f, 3.0f); // random line generator
	int lineRandom = floor(lineDistribution(generator));

	switch (lineRandom)
	{
	case 0:
		hexagon->setY(72);
		break;
	case 1:
		hexagon->setY(234);
		break;
	case 2:
		hexagon->setY(397);
		break;
	default:
		hexagon->setY(72);
		break;
	}

	//add the attack number of stars
	IncreaseStarsAttackNumber(hexagon->getColor(), floor(hexagon->getY()), 1);

	hexagon->setColorHex(colorHex);
	hexagon->setMesh(object2D::CreateHexagon("hexagonmic", glm::vec3(hexagon->getX(), hexagon->getY(), 1), 30, colorHex, glm::vec3(0.81, 0.81, 0.81), true));
	hexagons.push_back(hexagon);  // Adaugă hexagonul la container


}


void Tema1::SpawnStar(int _color, glm::vec2 _position) {
	Star* star = new Star();

	star->setX(_position.x);
	star->setY(_position.y);

	glm::vec3 colorStar = glm::vec3(0, 0, 0);

	switch (_color)
	{
	case 0:
		colorStar = glm::vec3(1, 0, 0);
		star->setColor(0);
		break;
	case 1:
		colorStar = glm::vec3(1, 1, 0);
		star->setColor(1);
		break;
	case 2:
		colorStar = glm::vec3(0, 0, 1);
		star->setColor(2);
		break;
	case 3:
		colorStar = glm::vec3(0, 1, 0);
		star->setColor(3);
		break;
	default:
		colorStar = glm::vec3(0, 1, 0);
		star->setColor(3);
		break;
	}

	star->setColorStar(colorStar);
	star->setMesh(object2D::CreateStar("star", glm::vec3(star->getX(), star->getY(), 1), 30, colorStar, true));
	stars.push_back(star);
}

void Tema1::SpawnGrid() {
	// Sets the screen area where to draw
	glm::ivec2 resolution = window->GetResolution();
	resolution.x = 1280;
	resolution.y = 720;
	glViewport(0, 0, resolution.x, resolution.y);


	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["currentDiamondSelected"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["Rectangle"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["square3"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["square4"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["square5"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["square6"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["square7"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["square8"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["square9"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["chenar1"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["chenar2"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["chenar3"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["chenar4"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["rombdrept1"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["rombdrept2"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["rombdrept3"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["rombdrept4"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["Star1"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["Star2"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["Star3"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["Star4"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["Star5"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["Star6"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["Star7"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["Star8"], shaders["VertexColor"], modelMatrix);


	//Render the diamonds in square
	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["diamondSquare1"], shaders["VertexColor"], modelMatrix);
	RenderMesh2D(meshes["diamondSquare2"], shaders["VertexColor"], modelMatrix);
	RenderMesh2D(meshes["diamondSquare3"], shaders["VertexColor"], modelMatrix);
	RenderMesh2D(meshes["diamondSquare4"], shaders["VertexColor"], modelMatrix);
	RenderMesh2D(meshes["diamondSquare5"], shaders["VertexColor"], modelMatrix);
	RenderMesh2D(meshes["diamondSquare6"], shaders["VertexColor"], modelMatrix);
	RenderMesh2D(meshes["diamondSquare7"], shaders["VertexColor"], modelMatrix);
	RenderMesh2D(meshes["diamondSquare8"], shaders["VertexColor"], modelMatrix);
	RenderMesh2D(meshes["diamondSquare9"], shaders["VertexColor"], modelMatrix);


}

glm::vec3 checkIfDiamondIsInSquare(int mouseX, int mouseY) {
	if (mouseX <= 105 + 125 && mouseX >= 105 && (720 - mouseY) <= 10 + 125 && (720 - mouseY) >= 10) {
		return glm::vec3(105, 10, 1);
	}

	if (mouseX <= 105 + 125 && mouseX >= 105 && (720 - mouseY) <= 172.5 + 125 && (720 - mouseY) >= 172.5) {
		return glm::vec3(105, 172.5, 2);
	}

	if (mouseX <= 105 + 125 && mouseX >= 105 && (720 - mouseY) <= 335 + 125 && (720 - mouseY) >= 335) {
		return glm::vec3(105, 335, 3);
	}

	if (mouseX <= 267.5 + 125 && mouseX >= 267.5 && (720 - mouseY) <= 10 + 125 && (720 - mouseY) >= 10) {
		return glm::vec3(267.5, 10, 4);
	}

	if (mouseX <= 267.5 + 125 && mouseX >= 267.5 && (720 - mouseY) <= 172.5 + 125 && (720 - mouseY) >= 172.5) {
		return glm::vec3(267.5, 172.5, 5);
	}

	if (mouseX <= 267.5 + 125 && mouseX >= 267.5 && (720 - mouseY) <= 335 + 125 && (720 - mouseY) >= 335) {
		return glm::vec3(267.5, 335, 6);
	}

	if (mouseX <= 430 + 125 && mouseX >= 430 && (720 - mouseY) <= 10 + 125 && (720 - mouseY) >= 10) {
		return glm::vec3(430, 10, 7);
	}

	if (mouseX <= 430 + 125 && mouseX >= 430 && (720 - mouseY) <= 172.5 + 125 && (720 - mouseY) >= 172.5) {
		return glm::vec3(430, 172.5, 8);
	}

	if (mouseX <= 430 + 125 && mouseX >= 430 && (720 - mouseY) <= 335 + 125 && (720 - mouseY) >= 335) {
		return glm::vec3(430, 335, 9);
	}

	return glm::vec3(-1, -1, -1);
}

glm::vec3 getSquarePosition(int index) {
	if (index == 1) {
		return glm::vec3(105 + 125 / 2, 10 + 125 / 2, 1);
	}

	if (index == 2) {
		return glm::vec3(105 + 125 / 2, 172.5 + 125 / 2, 2);
	}
	if (index == 3) {
		return glm::vec3(105 + 125 / 2, 335 + 125 / 2, 3);
	}

	if (index == 4) {
		return glm::vec3(267.5 + 125 / 2, 10 + 125 / 2, 4);
	}

	if (index == 5) {
		return glm::vec3(267.5 + 125 / 2, 172.5 + 125 / 2, 5);
	}

	if (index == 6) {
		return glm::vec3(267.5 + 125 / 2, 335 + 125 / 2, 6);
	}

	if (index == 7) {
		return glm::vec3(430 + 125 / 2, 10 + 125 / 2, 7);
	}

	if (index == 8) {
		return glm::vec3(430 + 125 / 2, 172.5 + 125 / 2, 8);
	}

	if (index == 9) {
		return glm::vec3(430 + 125 / 2, 335 + 125 / 2, 9);
	}

	return glm::vec3(-1, -1, -1);
}


void Tema1::IncreaseStarsAttackNumber(int color, float yPosition, int value) {
	if (color == 0) {
		if (yPosition == 72) {
			hexRedPostions.x += value;
		}
		if (yPosition == 234) {
			hexRedPostions.y += value;
		}
		if (yPosition == 397) {
			hexRedPostions.z += value;
		}
	}

	if (color == 1) {
		if (yPosition == 72) {
			hexYellowPostions.x += value;
		}
		if (yPosition == 234) {
			hexYellowPostions.y += value;
		}
		if (yPosition == 397) {
			hexYellowPostions.z += value;
		}
	}

	if (color == 2) {
		if (yPosition == 72) {
			hexBluePostions.x += value;
		}
		if (yPosition == 234) {
			hexBluePostions.y += value;
		}
		if (yPosition == 397) {
			hexBluePostions.z += value;
		}
	}

	if (color == 3) {
		if (yPosition == 72) {
			hexGreenPostions.x += value;
		}
		if (yPosition == 234) {
			hexGreenPostions.y += value;
		}
		if (yPosition == 397) {
			hexGreenPostions.z += value;
		}
	}

}

int Tema1::GetStarsAttackNumber(int color, float yPosition) {
	if (color == 0) {
		if (yPosition == 72) {
			return hexRedPostions.x;
		}
		if (yPosition == 234) {
			return hexRedPostions.y;
		}
		if (yPosition == 397) {
			return hexRedPostions.z;
		}
	}

	if (color == 1) {
		if (yPosition == 72) {
			return hexYellowPostions.x;
		}
		if (yPosition == 234) {
			return hexYellowPostions.y;
		}
		if (yPosition == 397) {
			return hexYellowPostions.z;
		}
	}

	if (color == 2) {
		if (yPosition == 72) {
			return hexBluePostions.x;
		}
		if (yPosition == 234) {
			return hexBluePostions.y;
		}
		if (yPosition == 397) {
			return hexBluePostions.z;
		}
	}

	if (color == 3) {
		if (yPosition == 72) {
			return hexGreenPostions.x;
		}
		if (yPosition == 234) {
			return hexGreenPostions.y;
		}
		if (yPosition == 397) {
			return hexGreenPostions.z;
		}
	}


}


void Tema1::Update(float deltaTimeSeconds)
{
	SpawnGrid();

	//afisez hexagons 

	modelMatrix = glm::mat3(1);
	timeSinceLastHexagonSpawn = 0.0f;
	hexagonSpawnInterval = 10.0f;
	randomint = rand() % 10;

	i = 0;

	std::uniform_real_distribution<float> starDistribution(10.0f, 20.0f); // random line generator
	currentStarTime += deltaTimeSeconds;

	if (floor(nextStarSpawnTime) <= floor(currentStarTime)) {
		//generate random time for next spawn
		nextStarSpawnTime = currentStarTime + starDistribution(generator);

		for (int i = 0; i < 3; i++) {
			SpawnStarsOnScreen();
		}
	}

	for (int i = 0; i < starsOnScreen.size(); i++) {
		Star* starScreen = starsOnScreen[i];

		glm::mat3 modelMatrix = glm::mat3(1);
		modelMatrix *= starScreen->translate(0, 0);
		RenderMesh2D(starScreen->getMesh(), shaders["VertexColor"], modelMatrix);
	}




	float timeSinceLastAppearance = 0.0f; // Inițial, timpul scurs de la ultima apariție este 0
	float deltaTime = 2.0f;
	timeSinceLastAppearance += deltaTime;
	std::uniform_real_distribution<float> intervalDistribution(3.0f, 5.0f); // Interval aleatoriu între apariții în secunde


	currentTime += deltaTimeSeconds;


	if (floor(nextAttackStarTime) <= floor(currentTime))
	{
		nextAttackStarTime += 1.0f;
		for (int l = 1; l <= 9; l++)
		{
			if (squaresOcuppation[l] != -1 && GetStarsAttackNumber(squaresOcuppation[l], floor(getSquarePosition(l).y)) > 0) {
				//check if we have attack start on the line

				SpawnStar(squaresOcuppation[l], glm::vec2(getSquarePosition(l).x, getSquarePosition(l).y));
				//delete the used star attack
			}
		}

	}


	if (floor(nextSpawnTime) <= floor(currentTime)) {
		//generate random time for next spawn
		nextSpawnTime = currentTime + intervalDistribution(generator);

		//spawn the hexagon
		SpawnHexagon();

		currentHexagonIndex++;
	}

	//move the spawned hexagons
	for (int i = 0; i <= currentHexagonIndex; i++)
	{
		Hexagon* hexagon = hexagons[i];

		hexagon->setX(hexagon->getX() - (deltaTimeSeconds * hexagonSpeed));
		hexagon->setMesh(object2D::CreateHexagon("hexagonmic", glm::vec3(hexagon->getX(), hexagon->getY(), 1), 30, hexagon->getColorHex(), glm::vec3(0.81, 0.81, 0.81), true));

		glm::mat3 modelMatrix = glm::mat3(1);


		if (floor(hexagon->getX()) <= 40) {
			modelMatrix *= hexagon->scale(0, 0);

			hexagons.erase(hexagons.begin() + i);
			currentHexagonIndex--;
			collision++;
		}

		//check if collision with star
		for (int j = 0; j < stars.size(); j++) {
			Star* star = stars[j];


			if (star->getColor() == hexagon->getColor() && abs(star->getY() - hexagon->getY()) <= 20 && ((hexagon->getX() - star->getX()) <= 30)) {

				star->setVisible(false); // Face steluta invizibilă
				// Eliminați steluta din lista și eliberați memoria
				stars.erase(stars.begin() + j);
				delete star;

				hexagon->setLives(hexagon->getLives() - 1);
				if (hexagon->getLives() == 0)
				{
					IncreaseStarsAttackNumber(hexagon->getColor(), floor(hexagon->getY()), -1);

					hexagons.erase(hexagons.begin() + i);

					currentHexagonIndex--;
					break; // Părăsiți bucla după ce ați găsit o stelută apăsată
				}

			}
		}

		//check if collision with diamond
		glm::vec3 hexPositionInSquare = checkIfDiamondIsInSquare(hexagon->getX(), 720 - hexagon->getY());

		if (hexPositionInSquare != glm::vec3(-1, -1, -1) && squaresOcuppation[hexPositionInSquare.z] != -1)
		{
			squaresOcuppation[hexPositionInSquare.z] = -1;
			Mesh* squareDiamond = object2D::CreateSquare("diamondSquare" + std::to_string((int)hexPositionInSquare.z), glm::vec3(-100, -100, 0), 125, glm::vec3(0, 0, 0), true);
			AddMeshToList(squareDiamond);
			RenderMesh2D(squareDiamond, shaders["VertexColor"], modelMatrix);
		}

		RenderMesh2D(hexagon->getMesh(), shaders["VertexColor"], modelMatrix);
	}

	//move the spawned stars
	for (int i = 0; i < stars.size(); i++)
	{
		Star* star = stars[i];

		star->setX(star->getX() + deltaTimeSeconds * starSpeed);
		star->setY(star->getY());
		star->setMesh(object2D::CreateStar("star", glm::vec3(star->getX(), star->getY(), 1), 30, star->getColorStar(), true));

		glm::mat3 modelMatrix = glm::mat3(1);

		RenderMesh2D(star->getMesh(), shaders["VertexColor"], modelMatrix);
	}


	Star* stars_life = new Star();
	stars_life->setX(780);
	stars_life->setY(565);
	stars_life->setMesh(object2D::CreateStar("Star", glm::vec3(stars_life->getX(), stars_life->getY(), 0), 15, glm::vec3(1, 1, 0), true));


	glm::mat3 modelMatrix = glm::mat3(1);

	for (int i = 0; i < 10 + collectedStars; i++) {
		RenderMesh2D(stars_life->getMesh(), shaders["VertexColor"], modelMatrix);
		modelMatrix *= stars_life->translate(40, 0);

	}

	Square* life1 = new Square();
	life1->setX(750);
	life1->setY(600);
	life1->setMesh(object2D::CreateSquare("life", glm::vec3(life1->getX(), life1->getY(), 0), 100, glm::vec3(1, 0, 0), true));
	modelMatrix = glm::mat3(1);
	for (int i = 0; i < 3 - collision; i++) {
		RenderMesh2D(life1->getMesh(), shaders["VertexColor"], modelMatrix);
		modelMatrix *= life1->translate(150, 0);
	}
	// check if life is 0 
	if (collision == 3) {
		exit(0);
	}

}


void Tema1::FrameEnd()
{
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */



void Tema1::OnInputUpdate(float deltaTime, int mods)
{
	// oninputupdate
}


void Tema1::OnKeyPress(int key, int mods)
{
	// Add key press event

}


void Tema1::OnKeyRelease(int key, int mods)
{
	// Add key release event
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// Add mouse move event
	if (currentDiamondSelectedIndex > -1) {

		glm::mat3 modelMatrix2 = glm::mat3(1);
		if (currentDiamondSelectedIndex == 0)
		{
			currentDiamondSelected->setMesh(object2D::CreateRombcudreptunghi("currentDiamondSelected", glm::vec3(mouseX, 720 - mouseY, 1), glm::vec3(600, 587.5, 1), 50, 50, glm::vec3(1, 0, 0), true));
			currentDiamondSelected->setColorRomb(glm::vec3(1, 0, 0));
		}
		if (currentDiamondSelectedIndex == 1) {
			currentDiamondSelected->setMesh(object2D::CreateRombcudreptunghi("currentDiamondSelected", glm::vec3(mouseX, 720 - mouseY, 1), glm::vec3(600, 587.5, 1), 50, 50, glm::vec3(1, 1, 0), true));
			currentDiamondSelected->setColorRomb(glm::vec3(1, 1, 0));
		}
		if (currentDiamondSelectedIndex == 2) {
			currentDiamondSelected->setMesh(object2D::CreateRombcudreptunghi("currentDiamondSelected", glm::vec3(mouseX, 720 - mouseY, 1), glm::vec3(600, 587.5, 1), 50, 50, glm::vec3(0, 0, 1), true));
			currentDiamondSelected->setColorRomb(glm::vec3(0, 0, 1));
		}
		if (currentDiamondSelectedIndex == 3) {
			currentDiamondSelected->setMesh(object2D::CreateRombcudreptunghi("currentDiamondSelected", glm::vec3(mouseX, 720 - mouseY, 1), glm::vec3(600, 587.5, 1), 50, 50, glm::vec3(0, 1, 0), true));
			currentDiamondSelected->setColorRomb(glm::vec3(0, 1, 0));
		}

		AddMeshToList(currentDiamondSelected->getMesh());

		RenderMesh2D(currentDiamondSelected->getMesh(), shaders["VertexColor"], modelMatrix2);
	}

}

void Tema1::checkClickOnStar(int mouseX, int mouseY)
{
	for (int i = 0; i < starsOnScreen.size(); i++)
	{
		//check if collision with star
		if (abs(starsOnScreen[i]->getX() - mouseX) <= 30
			&& abs(starsOnScreen[i]->getY() - (720 - mouseY)) <= 30) {
			Star* star = starsOnScreen[i];

			// Colectați steluta
			collectedStars++;
			star->setVisible(false); // Face steluta invizibilă
			// Eliminați steluta din lista și eliberați memoria
			starsOnScreen.erase(starsOnScreen.begin() + i);
			delete star;
		}
	}
}



void Tema1::checkClickOnDiamond(int mouseX, int mouseY) {
	if (mouseX < (125 + 70) && mouseX > 70 && (720 - mouseY) < (125 + 585) && (720 - mouseY) > 585)
	{
		//click on diamond 1
		cout << "click on diamond 0\n";
		currentDiamondSelectedIndex = 0;
		currentDiamondSelected = new Romb();
		currentDiamondSelected->setMesh(object2D::CreateRombcudreptunghi("currentDiamondSelected", glm::vec3(mouseX, (720 - mouseY), 1), glm::vec3(600, 587.5, 1), 50, 50, glm::vec3(1, 0, 0), true));
		currentDiamondSelected->setColorIndex(0);
		currentDiamondSelected->setColorRomb(glm::vec3(1, 0, 0));
	}
	if (mouseX < (125 + 245) && mouseX > 245 && (720 - mouseY) < (125 + 585) && (720 - mouseY) > 585)
	{
		//click on diamond 2
		cout << "click on diamond 1\n";
		currentDiamondSelectedIndex = 1;
		currentDiamondSelected = new Romb();
		currentDiamondSelected->setMesh(object2D::CreateRombcudreptunghi("currentDiamondSelected", glm::vec3(mouseX, (720 - mouseY), 1), glm::vec3(600, 587.5, 1), 50, 50, glm::vec3(1, 1, 0), true));
		currentDiamondSelected->setColorIndex(1);
		currentDiamondSelected->setColorRomb(glm::vec3(1, 1, 0));
	}
	if (mouseX < (125 + 420) && mouseX > 420 && (720 - mouseY) < (125 + 585) && (720 - mouseY) > 585)
	{
		//click on diamond 3
		cout << "click on diamond 2\n";
		currentDiamondSelectedIndex = 2;
		currentDiamondSelected = new Romb();
		currentDiamondSelected->setMesh(object2D::CreateRombcudreptunghi("currentDiamondSelected", glm::vec3(mouseX, (720 - mouseY), 1), glm::vec3(600, 587.5, 1), 50, 50, glm::vec3(0, 0, 1), true));
		currentDiamondSelected->setColorIndex(2);
		currentDiamondSelected->setColorRomb(glm::vec3(0, 0, 1));

	}
	if (mouseX < (125 + 595) && mouseX > 595 && (720 - mouseY) < (125 + 585) && (720 - mouseY) > 585)
	{
		//click on diamond 4
		cout << "click on diamond 3\n";
		currentDiamondSelectedIndex = 3;
		currentDiamondSelected = new Romb();
		currentDiamondSelected->setMesh(object2D::CreateRombcudreptunghi("currentDiamondSelected", glm::vec3(mouseX, (720 - mouseY), 1), glm::vec3(600, 587.5, 1), 50, 50, glm::vec3(0, 1, 0), true));
		currentDiamondSelected->setColorIndex(3);
		currentDiamondSelected->setColorRomb(glm::vec3(0, 1, 0));

	}

	if (currentDiamondSelectedIndex == -1) {
		return;
	}

	AddMeshToList(currentDiamondSelected->getMesh());

	RenderMesh2D(currentDiamondSelected->getMesh(), shaders["VertexColor"], modelMatrix);
}

void Tema1::checkClickOnDiamondInSquare(int mouseX, int mouseY)
{
	glm::vec3 diamondPosition = checkIfDiamondIsInSquare(mouseX, mouseY);
	if (diamondPosition != glm::vec3(-1, -1, -1) && squaresOcuppation[diamondPosition.z] != -1)
	{
		//delete the diamond
		squaresOcuppation[diamondPosition.z] = -1;
		Mesh* squareDiamond = object2D::CreateSquare("diamondSquare" + std::to_string((int)diamondPosition.z), glm::vec3(-100, -100, 0), 125, glm::vec3(0, 0, 0), true);
		AddMeshToList(squareDiamond);
		RenderMesh2D(squareDiamond, shaders["VertexColor"], modelMatrix);
	}
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	//checkClickOnStar 
	checkClickOnStar(mouseX, mouseY);

	//check click on diamond
	checkClickOnDiamond(mouseX, mouseY);

	//check click on diamond in square
	checkClickOnDiamondInSquare(mouseX, mouseY);



}



void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	if (currentDiamondSelectedIndex == -1) {
		return;
	}

	//if not into a square, reset the diamond
	glm::vec3 diamondPositionRelease = checkIfDiamondIsInSquare(mouseX, mouseY);
	if (diamondPositionRelease != glm::vec3(-1, -1, -1) && squaresOcuppation[diamondPositionRelease.z] == -1) {
		Mesh* mesh = object2D::CreateRombcudreptunghi("diamondSquare" + std::to_string((int)diamondPositionRelease.z), glm::vec3(diamondPositionRelease.x + 125 / 2, diamondPositionRelease.y + 125 / 2, 1), glm::vec3(600, 587.5, 1), 50, 50, currentDiamondSelected->getColorRomb(), true);
		AddMeshToList(mesh);
		RenderMesh2D(mesh, shaders["VertexColor"], modelMatrix);
		squaresOcuppation[diamondPositionRelease.z] = currentDiamondSelected->getColorIndex();
		if (currentDiamondSelectedIndex == 0) {
			collectedStars -= 1;
		}
		if (currentDiamondSelectedIndex == 1) {
			collectedStars -= 2;
		}
		if (currentDiamondSelectedIndex == 2) {
			collectedStars -= 2;
		}
		if (currentDiamondSelectedIndex == 3) {
			collectedStars -= 3;
		}
	}

	currentDiamondSelected->setMesh(object2D::CreateRombcudreptunghi("currentDiamondSelected", glm::vec3(-100, -100, 1), glm::vec3(600, 587.5, 1), 50, 50, glm::vec3(0, 0, 0), true));
	AddMeshToList(currentDiamondSelected->getMesh());
	RenderMesh2D(currentDiamondSelected->getMesh(), shaders["VertexColor"], modelMatrix);

	currentDiamondSelectedIndex = -1;
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema1::OnWindowResize(int width, int height)
{
}
