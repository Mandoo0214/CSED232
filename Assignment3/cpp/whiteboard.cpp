/* 객체지향 프로그래밍 Assignment 3_20210479 이주현*/
#include "whiteboard.h"

using namespace std;

WhiteBoard::WhiteBoard() { } //기본 생성자

WhiteBoard::~WhiteBoard() { } //소멸자

void WhiteBoard::fillPoint(int x, int y, char alphabet)
{
	board[y][x] = alphabet; //board에서 입력받은 좌표에 해당하는 부분을 입력받은 alphabet으로 바꾸기
}

void WhiteBoard::reset()
{
	for (int i = 0; i < 15; i++) //배열 내의 모든 원소를 '*'로 재설정
	{
		for (int j = 0; j < 15; j++)
		{
			board[i][j] = '*';
		}
	}
}

void WhiteBoard::display() const
{
	cout << "[Whiteboard]" << endl << "===============" << endl;

	for (int i = 0; i < 15; i++) //board 배열 출력
	{
		for (int j = 0; j < 15; j++)
		{
			cout << board[i][j] << " ";
		}

		cout << endl;
	}

	cout << "===============" << endl;
}