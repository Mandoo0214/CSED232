/* ��ü���� ���α׷��� Assignment 3_20210479 ������*/
#include "whiteboard.h"

using namespace std;

WhiteBoard::WhiteBoard() { } //�⺻ ������

WhiteBoard::~WhiteBoard() { } //�Ҹ���

void WhiteBoard::fillPoint(int x, int y, char alphabet)
{
	board[y][x] = alphabet; //board���� �Է¹��� ��ǥ�� �ش��ϴ� �κ��� �Է¹��� alphabet���� �ٲٱ�
}

void WhiteBoard::reset()
{
	for (int i = 0; i < 15; i++) //�迭 ���� ��� ���Ҹ� '*'�� �缳��
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

	for (int i = 0; i < 15; i++) //board �迭 ���
	{
		for (int j = 0; j < 15; j++)
		{
			cout << board[i][j] << " ";
		}

		cout << endl;
	}

	cout << "===============" << endl;
}