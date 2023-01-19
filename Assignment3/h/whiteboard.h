/* 객체지향 프로그래밍 Assignment 3_20210479 이주현*/
#pragma once

#include <iostream>

class WhiteBoard
{
	private:
		char board[15][15];

	public:
		WhiteBoard();
		~WhiteBoard();
		void fillPoint(int x, int y, char alphabet);
		void reset();
		void display() const;
};