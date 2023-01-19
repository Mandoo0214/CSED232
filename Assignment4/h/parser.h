/* 객체지향 프로그래밍 Assignment 4_20210479 이주현 */
#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "geometry.h"

class parser
{
	public:
		parser();
		~parser();
		canvas2d parse_canvas(const std::string line);
		geometry* parse_geometry(const std::string& line);
};
