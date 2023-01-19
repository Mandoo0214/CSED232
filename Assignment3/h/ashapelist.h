/* 객체지향 프로그래밍 Assignment 3_20210479 이주현*/
#pragma once

#include "Ashape.h"

struct AShapeNode
{
	AShape* shape;
	AShapeNode* next;
};

class AShapeList
{
	private:
		AShapeNode* head;
		AShapeNode* tail;
		int size = 0;

	public:
		AShapeList();
		~AShapeList();
		void addNewAShape(AShape* new_shape);
		AShapeNode* popNodeByIdx(int idx);
		const AShapeNode* getNodeByIdx(int idx) const;
		void displayAShapeList() const;
		void drawAll(WhiteBoard* board) const;
		int getSize() const;
};
