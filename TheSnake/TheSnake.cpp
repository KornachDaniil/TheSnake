#include <iostream>
#include <conio.h>
using namespace std;

bool gameOver;
const int widthMap = 20;
const int heightMap = 10;
float snakeX, snakeY;
float fruitX, fruitY;
float gameAccount;
enum eDirection { STOP = 0, UP, DOWN, RIGHT, LEFT };
eDirection directionSnake;

void Setup() {
	gameOver = false;
	directionSnake = STOP;
	snakeX = (widthMap / 2) - 1;
	snakeY = (heightMap / 2) - 1;
	fruitX = rand() % widthMap;
	fruitY = rand() % heightMap;
	gameAccount = 0;
}

void DrawMap() {
	system("cls");
	for (float i = 0; i < widthMap; i = i + 0.5) {
		cout << "#";
	}
	cout << endl;
	for (float j = 0; j < heightMap; j = j + 0.5) {
		for (float i = 0; i < widthMap; i = i + 0.5) {
			if (i == 0 || i == (widthMap - 1)) {
				cout << "#";
			}
			if (snakeX == i && snakeY == j) {
				cout << "0";
			}
			else if (fruitX == i && fruitY == j) {
				cout << "$";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}

	for (float i = 0; i < widthMap; i = i = i + 0.5) {
		cout << "#";
	}
	cout << endl;
	cout << "Score: " << gameAccount;
}



void MovementInput() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			directionSnake = LEFT;
			break;
		case 'd':
			directionSnake = RIGHT;
			break;
		case 'w':
			directionSnake = UP;
			break;
		case 's':
			directionSnake = DOWN;
			break;

		case 'x':
			gameOver = true;
			break;
		}
	}

}

void GameLogic() {
	switch (directionSnake)
	{
	case UP:
		snakeY -= 0.5;
		break;
	case DOWN:
		snakeY += 0.5;
		break;
	case RIGHT:
		snakeX += 0.5;
		break;
	case LEFT:
		snakeX -= 0.5;
		break;
	}
	if (snakeX > widthMap || snakeX < 0 || snakeY > heightMap || snakeY < 0) {
		gameOver = true;
	}
	if (snakeX == fruitX && snakeY == fruitY) {
		fruitX = rand() % (widthMap - 1);
		fruitY = rand() % (heightMap - 1);
		gameAccount++;
	}
}


int main() {
	Setup();
	while (!gameOver) {
		DrawMap();
		MovementInput();
		GameLogic();
	}

	return 0;
}