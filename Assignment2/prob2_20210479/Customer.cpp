#include "Customer.h"

Customer::Customer() { } //private ���� ���� �� �ʱ�ȭ

Customer::Customer(float money, float paidMoney, float time)
{
	(*this).money = money;
	(*this).paidMoney = paidMoney;
	(*this).time = time;
}

Customer::Customer(const Customer& customer)
{
	(*this).money = customer.money;
	(*this).paidMoney = customer.paidMoney;
	(*this).time = customer.time;
}

Customer::~Customer() { } //�Ҹ���

float Customer::reportMoney() const
{
	return paidMoney;
}

float Customer::reportTime() const
{
	return time;
}

void Customer::pay(float price, float time)
{
	money -= price;
	paidMoney += price;
	(*this).time += time;
}

ostream& operator<<(ostream& os, const Customer& x)
{
	os << "(money, paidMoney, time): (" << x.money << ", " << x.paidMoney << ", " << x.time << ")";

	return os;
}