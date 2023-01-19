/* 객체지향 프로그래밍 Assignment 3_20210479 이주현*/
#include "ashape.h"

using namespace std;

AShape::AShape() {} //AShape 생성자

AShape::~AShape() {} //AShape 소멸자

APoint::APoint() { } //변수 선언 시 초기화됨

APoint::APoint(int x_, int y_, char alphabet_)
{
	/* private 변수에 입력받은 값 대입 */
	alphabet = alphabet_;

	x = x_;
	y = y_;
}

APoint::~APoint() { } //소멸자

void APoint::draw(WhiteBoard* board) const
{
	board->fillPoint(x, y, alphabet);
}

void APoint::print() const
{
	/* pdf에 제시된 대로 출력 */
	cout << "APoint with [alphabet: " << alphabet << "] and [x: " << x << "] [y: " << y << "] [size: 1]";
	cout << endl;
}

int APoint::size() const
{
	return 1; //점의 사이즈는 1
}

AVerticalLine::AVerticalLine() { } //변수 선언 시 초기화됨

AVerticalLine::AVerticalLine(int x_, int y_start_, int y_end_, char alphabet_)
{
	/* private 변수에 입력받은 값 대입 */
	alphabet = alphabet_;

	x = x_;
	y_start = y_start_;
	y_end = y_end_;
}

AVerticalLine::~AVerticalLine() { } //소멸자

void AVerticalLine::draw(WhiteBoard* board) const
{
	for (int i = y_start; i <= y_end; i++) //line에 포함된 모든 좌표의 값을 넘겨 alphabet으로 변경
	{
		board->fillPoint(x, i, alphabet);
	}
}

void AVerticalLine::print() const
{
	/* pdf에 제시된 대로 출력 */
	cout << "AVerticalLine with [alphabet: " << alphabet << "] and [x: " << x << "] [y_start: " << y_start << "] [y_end: " << y_end << "] [size: " << this->size() << "]";
	cout << endl;
}

int AVerticalLine::size() const
{
	int size = y_end - y_start + 1; //size 측정할 변수

	return size;
}

AHorizontalLine::AHorizontalLine() { } //변수 선언 시 초기화됨

AHorizontalLine::AHorizontalLine(int y_, int x_start_, int x_end_, char alphabet_)
{
	/* private 변수에 입력받은 값 대입 */
	alphabet = alphabet_;

	y = y_;
	x_start = x_start_;
	x_end = x_end_;
}

AHorizontalLine::~AHorizontalLine() { } //소멸자

void AHorizontalLine::draw(WhiteBoard* board) const
{
	for (int i = x_start; i <= x_end; i++) //line에 포함된 모든 좌표의 값을 넘겨 alphabet으로 변경
	{
		board->fillPoint(i, y, alphabet);
	}
}

void AHorizontalLine::print() const
{
	/* pdf에 제시된 대로 출력 */
	cout << "AHorizontalLine with [alphabet: " << alphabet << "] and [y: " << y << "] [x_start: " << x_start << "] [x_end: " << x_end << "] [size: " << this->size() << "]";
	cout << endl;
}

int AHorizontalLine::size() const
{
	int size = x_end - x_start + 1; //size 측정할 변수

	return size;
}

ARectangle::ARectangle() { } //변수 선언 시 초기화됨

ARectangle::ARectangle(int x_start_, int x_end_, int y_start_, int y_end_, char alphabet_)
{
	/* private 변수에 입력받은 값 대입 */
	alphabet = alphabet_;

	x_start = x_start_;
	x_end = x_end_;
	y_start = y_start_;
	y_end = y_end_;
}

ARectangle::~ARectangle() { } //소멸자

void ARectangle::draw(WhiteBoard* board) const
{
	/* 사각형의 모든 좌표의 값을 넘겨 alphabet으로 변경 */
	for (int i = y_start; i <= y_end; i++)
	{
		for (int j = x_start; j <= x_end; j++)
		{
			board->fillPoint(j, i, alphabet);
		}
	}
}

void ARectangle::print() const
{
	/* pdf에 제시된 대로 출력 */
	cout << "ARectangle with [alphabet: " << alphabet << "] and [x_start: " << x_start << "] [x_end: " << x_end << "] [y_start: " << y_start << "] [y_end: " << y_end << "] [size: " << this->size() << "]";
	cout << endl;
}

int ARectangle::size() const
{
	int xSize = x_end - x_start + 1; //x축 길이
	int ySize = y_end - y_start + 1; //y축 길이
	int size = xSize * ySize; //사각형의 크기(넓이)를 구함

	return size;
}