#include <iostream>
#include <conio.h>
using namespace std;

bool gameOver;
const int widthMap = 30;
const int heightMap = 15;
int snakeX, snakeY;
int fruitX, fruitY;
int gameAccount;
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
	// Отрисовка всех объектов на карте:
	system("cls");
	// Верхняя граница карты
	for (int i = 0; i < (widthMap + 1); i++) {
		cout << "#";
	}
	cout << endl;

	// Отрисовка высоты и пустого пространства, а также объектов указанных ниже. 
	for (int j = 0; j < heightMap; j++) {
		for (int i = 0; i < widthMap; i++) {
			if (i == 0 || i == (widthMap - 1)) {
				cout << "#";
			}
			if (snakeX == i && snakeY == j) {
				cout << "0"; //Отрисовка головы змейки
			}
			else if (fruitX == i && fruitY == j) {
				cout << "$"; // Отрисовка цели
			}
			else {
				cout << " "; // Отрисовка пустого пространства
			}
		}
		cout << endl;
	}

	// Нижняя граница карты 
	for (int i = 0; i < (widthMap + 1); i = i++) {
		cout << "#";
	}
	cout << endl;
	// Счет и описание клавиш:
	cout << "Score: " << gameAccount << "/15";
	for (int i = 0; i < 4; i++) {
		cout << ' ';
	}
	cout << "Movement: WASD";
	for (int i = 0; i < 4; i++) {
		cout << ' ';
	}
	cout << "To exit press: X";
}



void MovementInput() {

	// Клавиши по умолчанию:
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

	// Скорость персонажа: 
	switch (directionSnake)
	{
	case UP:
		snakeY--;
		break;
	case DOWN:
		snakeY++;
		break;
	case RIGHT:
		snakeX++;
		break;
	case LEFT:
		snakeX--;
		break;
	}

	// Телепортирующие границы карты:
	if (snakeX > widthMap) {
		snakeX = 0;
	}
	else if (snakeX < 0) {
		snakeX = widthMap;
	}
	else if (snakeY > heightMap) {
		snakeY = 0;
	}
	else if (snakeY < 0) {
		snakeY = heightMap;
	}

	// Спавн новых целей:
	if (snakeX == fruitX && snakeY == fruitY) {
		fruitX = rand() % (widthMap - 1);
		fruitY = rand() % (heightMap - 1);
		gameAccount++;
	}

	// Условия игры:
	if (gameAccount == 15) {
		char textWin[] = "Y O U  A R E  W I N ! ! !";
		gameOver = true;
		cout << endl << endl << endl;
		cout << textWin;
		cout << endl << endl << endl;
		system("pause");
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