#include "Rider.h"

Rider::Rider() { } //private ���� ����� �ʱ�ȭ

Rider::Rider(float money, float earnMoney, float time)
{
	(*this).money = money;
	(*this).earnMoney = earnMoney;
	(*this).time = time;
}

Rider::Rider(const Rider& rider)
{
	(*this).money = rider.money;
	(*this).earnMoney = rider.earnMoney;
	(*this).time = rider.time;
}

Rider::~Rider() { } //�Ҹ���

float Rider::reportMoney() const
{
	return earnMoney;
}

float Rider::reportTime() const
{
	return time;
}

void Rider::deliver(float price, float time)
{
	(*this).money += price; //���� ���� �� �� ���ϱ�
	(*this).earnMoney += price; //�� ���Կ� �� �� ���ϱ�
	(*this).time += time; //��� �ð� ���ϱ�
}

ostream& operator<<(ostream& os, const Rider& x)
{
	os << "(money, earnMoney, time): (" << x.money << ", " << x.earnMoney << ", " << x.time << ")";

	return os;
}