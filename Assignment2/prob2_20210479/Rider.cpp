#include "Rider.h"

Rider::Rider() { } //private 변수 선언시 초기화

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

Rider::~Rider() { } //소멸자

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
	(*this).money += price; //가진 돈에 번 돈 더하기
	(*this).earnMoney += price; //총 수입에 번 돈 더하기
	(*this).time += time; //배달 시간 더하기
}

ostream& operator<<(ostream& os, const Rider& x)
{
	os << "(money, earnMoney, time): (" << x.money << ", " << x.earnMoney << ", " << x.time << ")";

	return os;
}