/* ��ü���� ���α׷��� Assignment 3_20210479 ������*/
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