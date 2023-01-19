/* 객체지향 프로그래밍 Assignment 3_20210479 이주현*/
#pragma once

#include "ashapelist.h"

class Menu
{
	private:
		bool is_running = true;
		AShapeList* shape_list;
		WhiteBoard* board;

	public:
		Menu(WhiteBoard* board, AShapeList* shape_list);
		~Menu();
		void display() const;
		bool getRunning() const;
		void getUserInput();
		void addAShape() const;
		void deleteAShape() const;
};