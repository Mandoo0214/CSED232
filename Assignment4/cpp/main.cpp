/* 객체지향 프로그래밍 Assignment 4_20210479 이주현 */
#include <iostream>
#include <sstream>
#include <string>
#include "geometry.h"
#include "parser.h"


template<typename T>
void print_relation(rectangle<T> r1, rectangle<T> r2)
{
	bool a1 = r1.is_equal(r2);
	bool a2 = r1.is_intersect(r2);
	bool a3 = r1.is_line_overlap(r2);
	bool a4 = r1.is_point_match(r2);
	bool a5 = r1.is_disjoint(r2);
	std::cout
		<< a1 << ","
		<< a2 << ","
		<< a3 << ","
		<< a4 << ","
		<< a5 << std::endl;
}
int main()
{
	std::string p_type;
	std::cin >> p_type;
	// Solve problem 1
	if (p_type == "problem1")
	{
		std::string line;
		parser parser;
		std::cin >> line;
		canvas2d canvas = parser.parse_canvas(line);
		while (std::cin >> line) {
			geometry* geo = parser.parse_geometry(line);
			canvas.push_back(geo);
		}
		canvas.draw2stdout();
	}
	// Solve problem 2
	else if (p_type == "problem2")
	{
		std::string line;
		while (std::cin >> line)
		{
			std::stringstream ss(line);
			std::string type;
			std::getline(ss, type, ',');
			if (type == "int")
			{
				std::vector<int> vals;
				while (ss.good())
				{
					getline(ss, type, ',');
					vals.push_back(std::stoi(type));
				}
				rectangle<int> rec1(vals[0], vals[1], vals[2], vals[3]);
				rectangle<int> rec2(vals[4], vals[5], vals[6], vals[7]);
				print_relation<int>(rec1, rec2);
			}
			else if (type == "float")
			{
				std::vector<float> vals;
				while (ss.good())
				{
					getline(ss, type, ',');
					vals.push_back(std::stof(type));
				}
				rectangle<float> rec1(vals[0], vals[1], vals[2], vals[3]);
				rectangle<float> rec2(vals[4], vals[5], vals[6], vals[7]);
				print_relation<float>(rec1, rec2);
			}
			else throw;
		}
	}
	else throw;
	return 0;
}