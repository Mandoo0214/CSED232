/* 객체지향 프로그래밍 Assignment 4_20210479 이주현 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "geometry.h"
#include "parser.h"

using namespace std;

parser::parser() { } //defaule 생성자

parser::~parser() { } //default 소멸자

canvas2d parser::parse_canvas(const std::string line)
{
	/* string으로부터 값을 읽기 위한 변수 선언 */
	stringstream ss(line);
	string temp = "";

	/* 값을 저장해 canvas2d로 넘길 변수 선언 */
	int width = 0, height = 0;
	char c_empty = 'a';

	int cnt = 0; //횟수 카운트용 임시 변수

	/* string으로부터 canvas2d에 들어갈 정보 읽어내기 */
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
	/* string으로부터 값을 읽기 위한 변수 선언 */
	stringstream ss(line);
	string temp;

	getline(ss, temp, ',');

	/* string으로부터 읽어들인 값에 따라 알맞은 동작 구현 */
	if (temp == "point") //point 객체를 만들어야 하는 경우
	{
		getline(ss, temp, ',');
		if (temp == "int")
		{
			vector<int> vec1; //int 저장용 벡터 선언

			/* string에서 정보 읽어들이기 */
			while (ss.good())
			{
				getline(ss, temp, ',');
				vec1.push_back(stoi(temp));
			}

			/* argument list 형식을 맞추기 위해 vecotr 내의 원소 int 배열로 복사하기 */
			int size = vec1.size();
			int* arr = new int[size];

			for (int i = 0; i < size; i++)
				arr[i] = vec1[i];

			/* polymorphism을 이용한 g 동적할당 및 반환 */
			geometry* g;

			if (size == 2)
				g = new point<int, 2>(arr);

			else if (size == 3)
				g = new point<int, 3>(arr);

			else if (size == 4)
				g = new point<int, 4>(arr);

			else //size가 5일 때
				g = new point<int, 5>(arr);

			return g;
		}

		else if (temp == "float")
		{
			vector<float> vec2; //float 저장용 벡터 선언

			/* string에서 정보 읽어들이기 */
			while (ss.good())
			{
				getline(ss, temp, ',');
				vec2.push_back(stof(temp));
			}

			/* argument list 형식을 맞추기 위해 vecotr 내의 원소 float 배열로 복사하기 */
			int size = vec2.size();
			float* arr = new float[size];

			for (int i = 0; i < size; i++)
				arr[i] = vec2[i];

			/* polymorphism을 이용한 g 동적할당 및 반환 */
			geometry* g;

			if (size == 2)
				g = new point<float, 2>(arr);

			else if (size == 3)
				g = new point<float, 3>(arr);

			else if (size == 4)
				g = new point<float, 4>(arr);

			else //size가 5일 때
				g = new point<float, 5>(arr);

			return g;
		}
	}

	else if (temp == "rectangle") //rectangle 객체를 만들어야 하는 경우
	{
		getline(ss, temp, ',');
		if (temp == "int")
		{
			vector<int> vec3; //int 저장용 벡터 선언

			/* string에서 정보 읽어들이기 */
			for (int i = 0; i < 4; i++)
			{
				getline(ss, temp, ',');
				vec3.push_back(stoi(temp));
			}

			/* polymorphism을 이용한 g 동적할당 및 반환 */
			geometry* g;
			g = new rectangle<int>(vec3[0], vec3[1], vec3[2], vec3[3]);

			return g;
		}

		else if (temp == "float")
		{
			vector<float> vec4; //float 저장용 벡터 선언

			/* string에서 정보 읽어들이기 */
			for (int i = 0; i < 4; i++)
			{
				getline(ss, temp, ',');
				vec4.push_back(stof(temp));
			}

			/* polymorphism을 이용한 g 동적할당 및 반환 */
			geometry* g;
			g = new rectangle<float>(vec4[0], vec4[1], vec4[2], vec4[3]);

			return g;
		}
	}
}