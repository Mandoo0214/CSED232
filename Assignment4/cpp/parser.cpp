/* ��ü���� ���α׷��� Assignment 4_20210479 ������ */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "geometry.h"
#include "parser.h"

using namespace std;

parser::parser() { } //defaule ������

parser::~parser() { } //default �Ҹ���

canvas2d parser::parse_canvas(const std::string line)
{
	/* string���κ��� ���� �б� ���� ���� ���� */
	stringstream ss(line);
	string temp = "";

	/* ���� ������ canvas2d�� �ѱ� ���� ���� */
	int width = 0, height = 0;
	char c_empty = 'a';

	int cnt = 0; //Ƚ�� ī��Ʈ�� �ӽ� ����

	/* string���κ��� canvas2d�� �� ���� �о�� */
	while (ss.good())
	{
		getline(ss, temp, ',');

		if (cnt == 0)
			width = stoi(temp);

		else if (cnt == 1)
			height = stoi(temp);

		else
			c_empty = temp[0];

		cnt++;
	}

	canvas2d c(width, height, c_empty);
	return c;	
}

geometry* parser::parse_geometry(const std::string& line)
{
	/* string���κ��� ���� �б� ���� ���� ���� */
	stringstream ss(line);
	string temp;

	getline(ss, temp, ',');

	/* string���κ��� �о���� ���� ���� �˸��� ���� ���� */
	if (temp == "point") //point ��ü�� ������ �ϴ� ���
	{
		getline(ss, temp, ',');
		if (temp == "int")
		{
			vector<int> vec1; //int ����� ���� ����

			/* string���� ���� �о���̱� */
			while (ss.good())
			{
				getline(ss, temp, ',');
				vec1.push_back(stoi(temp));
			}

			/* argument list ������ ���߱� ���� vecotr ���� ���� int �迭�� �����ϱ� */
			int size = vec1.size();
			int* arr = new int[size];

			for (int i = 0; i < size; i++)
				arr[i] = vec1[i];

			/* polymorphism�� �̿��� g �����Ҵ� �� ��ȯ */
			geometry* g;

			if (size == 2)
				g = new point<int, 2>(arr);

			else if (size == 3)
				g = new point<int, 3>(arr);

			else if (size == 4)
				g = new point<int, 4>(arr);

			else //size�� 5�� ��
				g = new point<int, 5>(arr);

			return g;
		}

		else if (temp == "float")
		{
			vector<float> vec2; //float ����� ���� ����

			/* string���� ���� �о���̱� */
			while (ss.good())
			{
				getline(ss, temp, ',');
				vec2.push_back(stof(temp));
			}

			/* argument list ������ ���߱� ���� vecotr ���� ���� float �迭�� �����ϱ� */
			int size = vec2.size();
			float* arr = new float[size];

			for (int i = 0; i < size; i++)
				arr[i] = vec2[i];

			/* polymorphism�� �̿��� g �����Ҵ� �� ��ȯ */
			geometry* g;

			if (size == 2)
				g = new point<float, 2>(arr);

			else if (size == 3)
				g = new point<float, 3>(arr);

			else if (size == 4)
				g = new point<float, 4>(arr);

			else //size�� 5�� ��
				g = new point<float, 5>(arr);

			return g;
		}
	}

	else if (temp == "rectangle") //rectangle ��ü�� ������ �ϴ� ���
	{
		getline(ss, temp, ',');
		if (temp == "int")
		{
			vector<int> vec3; //int ����� ���� ����

			/* string���� ���� �о���̱� */
			for (int i = 0; i < 4; i++)
			{
				getline(ss, temp, ',');
				vec3.push_back(stoi(temp));
			}

			/* polymorphism�� �̿��� g �����Ҵ� �� ��ȯ */
			geometry* g;
			g = new rectangle<int>(vec3[0], vec3[1], vec3[2], vec3[3]);

			return g;
		}

		else if (temp == "float")
		{
			vector<float> vec4; //float ����� ���� ����

			/* string���� ���� �о���̱� */
			for (int i = 0; i < 4; i++)
			{
				getline(ss, temp, ',');
				vec4.push_back(stof(temp));
			}

			/* polymorphism�� �̿��� g �����Ҵ� �� ��ȯ */
			geometry* g;
			g = new rectangle<float>(vec4[0], vec4[1], vec4[2], vec4[3]);

			return g;
		}
	}
}