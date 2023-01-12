#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

#define SIZE 10
vector<vector< char>> board;
int player = 1;
bool isGameOver = false;
bool Draw = false;
// Hàm check xem có còn ' ' không, nếu còn trả về false
bool checkChar(vector<vector<char>> v, int size) {

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == ' ') {
				return false;
			}
		}

	}
}
void printboard()
{
	cout << "-----------------------------------------" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << "| " << board[i][j] << " ";
		}
		cout << "|" << endl;
		cout << "-----------------------------------------" << endl;
	}
}

void update()
{
	char mark;
	player = (player % 2) ? 1 : 2;
	mark = (player == 1) ? 'X' : 'O';

	int x, y;
	do
	{
		cout << "Player " << player << " turn: ";
		cin >> x >> y;
	} while (x > SIZE - 1 || y > SIZE - 1 || board[x][y] != ' ');

	if (board[x][y] == ' ')
		board[x][y] = mark;
	player++;
}

bool checkBoard()
{

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3]) {
				return true;
			}
			else if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j]) {
				return true;
			}
			else if (board[i][j] != ' ' && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3]) {
				return true;
			}
			// Tổng các phần tử trong board không còn ' ' nữa.
			else if (checkChar(board, SIZE)) {
				Draw = true;
				return true;
			}
			return false;

		}
	}
}

int main()
{   // Resize lại kích thước:Nếu không xảy ra lỗi ngoài phạm vi : Out of range
	board.resize(SIZE);
	for (int i = 0; i < SIZE; ++i)
		board.at(i).resize(10);
	// Tạo ô trống để điền XO
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			board[i][j] = ' ';
		}
	}

	cout << "\tGAME CARO C++ " << endl;
	cout << "PLAYER 1 - [X]  - PLAYER 2 = [O]" << endl;

	while (!isGameOver)
	{

		printboard();
		update();
		isGameOver = checkBoard();

		if (isGameOver)
		{
			if (Draw)
				cout << "-----GAME DRAW-----";
			else
				cout << "-----Player " << --player << " is winner-----" << endl;
		}
	}
	return 0;
}