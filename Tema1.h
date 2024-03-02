#pragma once

#include "components/simple_scene.h"
#include "lab_m1/Tema1/Patrat.h"
#include "lab_m1/Tema1/Hexagon.h"
#include "lab_m1/Tema1/Romb.h"
#include "lab_m1/Tema1/Star.h"


namespace m1
{
	class Tema1 : public gfxc::SimpleScene
	{
	public:
		Tema1();
		~Tema1();

		void Init() override;

	private:
		void FrameStart() override;

		void InitHexagons();
		void SpawnStarsOnScreen();
		void SpawnHexagon();
		void SpawnStar(int _color, glm::vec2 _position);
		void SpawnGrid();

		void IncreaseStarsAttackNumber(int color, float yPosition, int value);

		int GetStarsAttackNumber(int color, float yPosition);

		void Update(float deltaTimeSeconds) override;
		void FrameEnd() override;

		void OnInputUpdate(float deltaTime, int mods) override;
		void OnKeyPress(int key, int mods) override;
		void OnKeyRelease(int key, int mods) override;
		void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
		void checkClickOnStar(int mouseX, int mouseY);
		void checkClickOnDiamond(int mouseX, int mouseY);
		void checkClickOnDiamondInSquare(int mouseX, int mouseY);
		void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
		void OnWindowResize(int width, int height) override;
		//void DrawGrid(Mesh* square, Mesh* rectangle);
		void showtime();

	protected:
		glm::mat3 modelMatrix;
		float translateX, translateY;
		float windowResolutionX = 1280;
		float scaleX, scaleY;
		float mouseX, mouseY;
		float mouseBtnPressed;
		int lives;
		int hexagonsNumber;
		Hexagon* hexagon;
		Romb* romb;
		Patrat* patrat;
		std::vector<float> speed;
		float hextranslateX[100];
		float hextranslateY[100];
		int randomint;
		float timeSinceLastHexagonSpawn;
		float hexagonSpawnInterval;

		std::vector<Hexagon*> hexagons;
		std::vector<Star*> stars;
		std::vector<Star*> starsOnScreen;

		int i = 0;
		float timeSinceLastAppearance;
		std::uniform_real_distribution<float> intervalDistruibution;

		int currentHexagonIndex = -1;

		int hexagonSpeed = 100;
		int starSpeed = 150;

		float currentTime = 0;
		float nextSpawnTime = 0;

		float currentStarTime = 0;
		float nextStarSpawnTime = 0;

		int collectedStars = 0;

		int currentDiamondSelectedIndex = -1;
		Romb* currentDiamondSelected;

		glm::vector<int> squaresOcuppation = glm::vector<int>(10);

		float nextAttackStarTime = 0;


		glm::vec3 hexRedPostions = glm::vec3(0, 0, 0);
		glm::vec3 hexBluePostions = glm::vec3(0, 0, 0);
		glm::vec3 hexYellowPostions = glm::vec3(0, 0, 0);
		glm::vec3 hexGreenPostions = glm::vec3(0, 0, 0);

		int collision = 0;


	};
}   // namespace m1
