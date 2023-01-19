#pragma once

#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;

class Rider
{
	private:
		float money = 0;
		float earnMoney = 0;
		float time = 0;

	public:
		Rider();
		Rider(float money, float earnMoney, float time);
		Rider(const Rider& rider);
		~Rider();

		float reportMoney() const;
		float reportTime() const;
		void deliver(float price, float time);

		friend ostream& operator<<(ostream& os, const Rider& x);
};
