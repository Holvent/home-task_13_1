#include <iostream>
#include <iomanip>
#include <algorithm>
#include <conio.h>


using namespace std;
//ход конём
/*const int DS = 8;
int desk[DS][DS];
int step[8][2] = { {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2} };
int n;
void showDesk() {
	for (int i = 0; i < DS; i++) {
		for (int j = 0; j < DS; j++) {
			cout << setw(2) << desk[i][j] << " ";
		}
		cout << endl;
	}
}
bool sethorse(int x,int y) {
	//проверка
	if ((x<0)||(x>=DS)|| (y < 0) || (y >= DS))
		return false;
	if (desk[x][y] != 0)
		return false;
	//след. ход
	n++;
	desk[x][y] = n;
	//стоп игра
	if (n == DS * DS)
		return true;

	for (int i = 0; i < 8; i++){
		if (sethorse(x + step[i][0], y + step[i][1]))
			return true;
	}
	n--;
	desk[x][y] = 0;
	return false;
}

int main() 
{
	n = 0;
	for (int i = 0; i < DS; i++) {
		for (int j = 0; j < DS; j++) {
			desk[i][j] = 0;
		}
	}
	
	sethorse(0,0);
	showDesk();

}*/

//пятнашки
/*const int r = 4;
const int c = 4;
int arr2[r][c]{
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 14, 15,0 },
};
int arr[r][c]{
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 14, 15,0 },
};
char key;
int* p = &arr[0][0];

enum Direction { LEFT = 75, UP = 72, RIGHT = 77, DOWN = 80 };
void func(int arr[][4], int r, int c) {
	srand(time(NULL));
	random_shuffle(p, p + 16);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

bool funcwin() {
	bool game = false;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (arr[i][j] == arr2[i][j] && arr[3][3] == 0) continue;
			else game = true;
		}
	}
	return game;
}
void funcup(int arr[][4], int r, int c) {
	int temp = 0;
	int t = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == temp && temp != arr[3][j]) {
				t = i;
				if (t == 0) {
					temp = arr[t + 1][j];
					arr[t + 1][j] = arr[t][j];
					arr[t][j] = temp;
				}
				else if (t == 1) {
					temp = arr[t + 1][j];
					arr[t + 1][j] = arr[t][j];
					arr[t][j] = temp;
				}
				else if (t == 2) {
					arr[t][j] = arr[t + 1][j];
					arr[t + 1][j] = temp;
				}
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
void funcdown(int arr[][4], int r, int c) {
	int temp = 0;
	int t = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == temp && temp != arr[0][j]) {
				t = i;
				if (t == 1) {
					temp = arr[t - 1][j];
					arr[t - 1][j] = arr[t][j];
					arr[t][j] = temp;
				}
				else if (t == 2) {
					arr[t][j] = arr[t - 1][j];
					arr[t - 1][j] = temp;
				}
				else if (t == 3) {
					temp = arr[t - 1][j];
					arr[t - 1][j] = arr[t][j];
					arr[t][j] = temp;
				}
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
void funcleft(int arr[][4], int r, int c) {
	int temp = 0;
	int t = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == temp && temp != arr[i][3]) {
				t = j;
				if (t == 0) {
					temp = arr[i][t + 1];
					arr[i][t + 1] = arr[i][t];
					arr[i][t] = temp;
				}
				else if (t == 1) {
					temp = arr[i][t + 1];
					arr[i][t + 1] = arr[i][t];
					arr[i][t] = temp;
				}
				else if (t == 2) {
					arr[i][t] = arr[i][t + 1];
					arr[i][t + 1] = temp;
				}
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
void funcright(int arr[][4], int r, int c) {
	int temp = 0;
	int t = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == temp && temp != arr[i][0]) {
				t = j;
				if (t == 1) {
					temp = arr[i][t - 1];
					arr[i][t - 1] = arr[i][t];
					arr[i][t] = temp;
				}
				else if (t == 2) {
					arr[i][t] = arr[i][t - 1];
					arr[i][t - 1] = temp;
				}
				else if (t == 3) {
					temp = arr[i][t - 1];
					arr[i][t - 1] = arr[i][t];
					arr[i][t] = temp;
				}
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "");
	func(arr, 4, 4);
	do
	{
		key = _getch();
		if (key == -32)key = _getch();
		system("cls");
		switch (key)
		{
		case UP:
			funcup(arr, 4, 4);
			break;
		case DOWN:
			funcdown(arr, 4, 4);
			break;
		case LEFT:
			funcleft(arr, 4, 4);
			break;
		case RIGHT:
			funcright(arr, 4, 4);
			break;
		default:
			break;
		}
	} while (funcwin());
	cout << "Вы победили";
}*/

//крестики нолики
/*
#define S(X) (X) ? 'X' : 'O' // макрос для назначения символа
const int SIZE_BOARD = 3; // размер доски
char board[SIZE_BOARD][SIZE_BOARD]{ '_','_','_','_','_','_',' ',' ',' ' };
int compStep[9]{ 00, 01, 02, 10, 11, 12, 20, 21, 22 }; // возможные ходы
void ShowBoard(); // отображение поля
int PlayerTurn(); //ход игрока
int ComputerTurn(); // ход компьютера
void LogicGame(); // логика игры
bool InicialBoard(int a, char c); // занесение в массив хода игроков
bool IsWin(char c); // проверка выйгрыша
int main(){
	setlocale(LC_ALL, "");
	srand(time(0));
	random_shuffle(begin(compStep), end(compStep)); // перемешивет значения местами в массиве
	LogicGame();

}
void ShowBoard() {
	for (int i = 0; i < SIZE_BOARD; i++) {
		for (int j = 0; j < SIZE_BOARD; j++) {
			if (j != 0) cout << '|';
			cout << board[i][j];
		}
		cout << endl;
	}
}
int PlayerTurn() {
	int pl;
	while (true)
	{
		cout << "Введите X и Y (слитно, без пробела) -> "; cin >> pl;
		if ((0 < pl / 10 && pl / 10 < 4) &&
			(0 < pl % 10 && pl % 10 < 4))
			return pl - 11;
		else
			cout << "Введено неверное значение, повторите попытку\n";
		//system("cls");
	}
}
int ComputerTurn() {
	for (static int i = 0; i < 9;) {
		return compStep[i++];
	}
}
bool InicialBoard(int a, char c) {
	int x = a / 10;
	int y = a % 10;
	if (board[x][y] == 'X' || board[x][y] == 'O') {
		cout << "Нельзя. Клетка уже задана\n";
		return false;
	}
	else
		board[x][y] = c;
	return true;
}
bool IsWin(char c) {
	for (int i = 0; i < 3; i++) { // проверка по строкам
		if (board[i][0] == c && board[i][1] == c && board[i][2] == c) return true;
	}
	for (int j = 0; j < 3; j++) { // проверка по столбцам
		if (board[0][j] == c && board[1][j] == c && board[2][j] == c) return true;
	}
	// проверка по диагонали
	if (board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
	if (board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;
	return false;
}
void LogicGame() {
	ShowBoard();
	srand(time(0));
	int step = rand() % 2;
	char player = S(step), comp = S(!step);
	int count = 0;
	while (count <= 9)
	{
		if (!InicialBoard((count % 2) ? PlayerTurn() : ComputerTurn(),
			(count % 2) ? player : comp)) continue;
		ShowBoard();
		if (IsWin((count % 2) ? player : comp)) {
			cout << "Победа!\n";
			break;
		}
		count++;
	}
	if (count > 9) cout << "Ничья!\n";
}
*/
