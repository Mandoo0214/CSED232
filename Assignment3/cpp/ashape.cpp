/* ��ü���� ���α׷��� Assignment 3_20210479 ������*/
#include "ashape.h"

using namespace std;

AShape::AShape() {} //AShape ������

AShape::~AShape() {} //AShape �Ҹ���

APoint::APoint() { } //���� ���� �� �ʱ�ȭ��

APoint::APoint(int x_, int y_, char alphabet_)
{
	/* private ������ �Է¹��� �� ���� */
	alphabet = alphabet_;

	x = x_;
	y = y_;
}

APoint::~APoint() { } //�Ҹ���

void APoint::draw(WhiteBoard* board) const
{
	board->fillPoint(x, y, alphabet);
}

void APoint::print() const
{
	/* pdf�� ���õ� ��� ��� */
	cout << "APoint with [alphabet: " << alphabet << "] and [x: " << x << "] [y: " << y << "] [size: 1]";
	cout << endl;
}

int APoint::size() const
{
	return 1; //���� ������� 1
}

AVerticalLine::AVerticalLine() { } //���� ���� �� �ʱ�ȭ��

AVerticalLine::AVerticalLine(int x_, int y_start_, int y_end_, char alphabet_)
{
	/* private ������ �Է¹��� �� ���� */
	alphabet = alphabet_;

	x = x_;
	y_start = y_start_;
	y_end = y_end_;
}

AVerticalLine::~AVerticalLine() { } //�Ҹ���

void AVerticalLine::draw(WhiteBoard* board) const
{
	for (int i = y_start; i <= y_end; i++) //line�� ���Ե� ��� ��ǥ�� ���� �Ѱ� alphabet���� ����
	{
		board->fillPoint(x, i, alphabet);
	}
}

void AVerticalLine::print() const
{
	/* pdf�� ���õ� ��� ��� */
	cout << "AVerticalLine with [alphabet: " << alphabet << "] and [x: " << x << "] [y_start: " << y_start << "] [y_end: " << y_end << "] [size: " << this->size() << "]";
	cout << endl;
}

int AVerticalLine::size() const
{
	int size = y_end - y_start + 1; //size ������ ����

	return size;
}

AHorizontalLine::AHorizontalLine() { } //���� ���� �� �ʱ�ȭ��

AHorizontalLine::AHorizontalLine(int y_, int x_start_, int x_end_, char alphabet_)
{
	/* private ������ �Է¹��� �� ���� */
	alphabet = alphabet_;

	y = y_;
	x_start = x_start_;
	x_end = x_end_;
}

AHorizontalLine::~AHorizontalLine() { } //�Ҹ���

void AHorizontalLine::draw(WhiteBoard* board) const
{
	for (int i = x_start; i <= x_end; i++) //line�� ���Ե� ��� ��ǥ�� ���� �Ѱ� alphabet���� ����
	{
		board->fillPoint(i, y, alphabet);
	}
}

void AHorizontalLine::print() const
{
	/* pdf�� ���õ� ��� ��� */
	cout << "AHorizontalLine with [alphabet: " << alphabet << "] and [y: " << y << "] [x_start: " << x_start << "] [x_end: " << x_end << "] [size: " << this->size() << "]";
	cout << endl;
}

int AHorizontalLine::size() const
{
	int size = x_end - x_start + 1; //size ������ ����

	return size;
}

ARectangle::ARectangle() { } //���� ���� �� �ʱ�ȭ��

ARectangle::ARectangle(int x_start_, int x_end_, int y_start_, int y_end_, char alphabet_)
{
	/* private ������ �Է¹��� �� ���� */
	alphabet = alphabet_;

	x_start = x_start_;
	x_end = x_end_;
	y_start = y_start_;
	y_end = y_end_;
}

ARectangle::~ARectangle() { } //�Ҹ���

void ARectangle::draw(WhiteBoard* board) const
{
	/* �簢���� ��� ��ǥ�� ���� �Ѱ� alphabet���� ���� */
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
	/* pdf�� ���õ� ��� ��� */
	cout << "ARectangle with [alphabet: " << alphabet << "] and [x_start: " << x_start << "] [x_end: " << x_end << "] [y_start: " << y_start << "] [y_end: " << y_end << "] [size: " << this->size() << "]";
	cout << endl;
}

int ARectangle::size() const
{
	int xSize = x_end - x_start + 1; //x�� ����
	int ySize = y_end - y_start + 1; //y�� ����
	int size = xSize * ySize; //�簢���� ũ��(����)�� ����

	return size;
}