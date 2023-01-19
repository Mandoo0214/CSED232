#pragma once

#include "Vector_Customer.h"
#include "Vector_Rider.h"

class Pizza
{
	private:
		float money = 10000;
		float priceA;
		float priceB;
		float feeA;
		float feeB;
		float timeA = 10;
		float timeB = 20;
		Vector_Customer A;
		Vector_Customer B;
		Vector_Rider R;

	public:
		Pizza();
		Pizza(float money);
		Pizza(const Pizza& pizza);
		~Pizza();

		void setPrice();
		void setPrice(float a, float b);
		void hire(const Rider& rider);
		void hire(const Rider* riders, int size);
		void enroll(const Customer& customer, bool a);
		void enroll(const Customer* customers, int size, bool a);
		float reportMoney() const;
		int numRiders() const;
		int numCustomers(bool a) const;
		float meanFee() const;
		float meanTimeRiders() const;
		float meanMoneyCustomers() const;
		float meanTimeCustomers() const;
		void deliver();

		friend ostream& operator<<(ostream& os, const Pizza& x);
};