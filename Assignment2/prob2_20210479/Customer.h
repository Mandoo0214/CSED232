#pragma once

#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;

class Customer
{
	private:
		float money = 1000;
		float paidMoney = 0;
		float time = 0;

	public:
		Customer();
		Customer(float money, float paidMoney, float time);
		Customer(const Customer& customer);
		~Customer();

		float reportMoney() const;
		float reportTime() const;
		void pay(float price, float time);

		friend ostream& operator<<(ostream& os, const Customer& x);
};
