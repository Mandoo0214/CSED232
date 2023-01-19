/* 객체지향 프로그래밍 Assignment 3_20210479 이주현*/
#pragma once

#include "whiteboard.h"

class AShape //abstract class
{
	protected:
		char alphabet = 'a';

	public:
		AShape();
		virtual ~AShape();
		virtual void draw(WhiteBoard* board) const = 0;
		virtual void print() const = 0;
		virtual int size() const = 0;
};

class APoint : public AShape
{
	private:
		int x = 0;
		int y = 0;

	public:
		APoint();
		APoint(int x_, int y_, char alphabet_);
		~APoint();
		void draw(WhiteBoard* board) const;
		void print() const;
		int size() const;
};

class AVerticalLine : public AShape
{
	private:
		int x = 0;
		int y_start = 0;
		int y_end = 0;

	public:
		AVerticalLine();
		AVerticalLine(int x_, int y_start_, int y_end_, char alphabet_);
		~AVerticalLine();
		void draw(WhiteBoard* board) const;
		void print() const;
		int size() const;
};

class AHorizontalLine : public AShape
{
	private:
		int y = 0;
		int x_start = 0;
		int x_end = 0;

	public:
		AHorizontalLine();
		AHorizontalLine(int y_, int x_start_, int x_end_, char alphabet_);
		~AHorizontalLine();
		void draw(WhiteBoard* board) const;
		void print() const;
		int size() const;
};

class ARectangle : public AShape
{
	private:
		int x_start = 0;
		int x_end = 0;
		int y_start = 0;
		int y_end = 0;

	public:
		ARectangle();
		ARectangle(int x_start_, int x_end_, int y_start_, int y_end_, char alphabet_);
		~ARectangle();
		void draw(WhiteBoard* board) const;
		void print() const;
		int size() const;
};