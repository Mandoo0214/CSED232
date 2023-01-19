#include "Pizza.h"

Pizza::Pizza()
{
	A = Vector_Customer(5); //문제 기본 설정대로 Vector_Customer 생성
	B = Vector_Customer(5); //문제 기본 설정대로 Vector_Customer 생성

	R = Vector_Rider(5); //문제 기본 설정대로 Vector_Rider 생성

	setPrice(); //나머지 private 변수 설정
}

Pizza::Pizza(float money)
{
	A = Vector_Customer(5); //문제 기본 설정대로 Vector_Customer 생성
	B = Vector_Customer(5); //문제 기본 설정대로 Vector_Customer 생성

	R = Vector_Rider(5); //문제 기본 설정대로 Vector_Rider 생성

	(*this).money = money; //입력받은 값으로 money 설정

	setPrice(); //나머지 private 변수 설정
}

Pizza::Pizza(const Pizza& pizza) //pizza의 내용을 복사하여 새로운 객체 생성
{
	money = pizza.money;
	priceA = pizza.priceA;
	priceB = pizza.priceB;
	feeA = pizza.feeA;
	feeB = pizza.feeB;
	timeA = pizza.timeA;
	timeA = pizza.timeA;
	A = pizza.A;
	B = pizza.B;
	R = pizza.R;
}

Pizza::~Pizza() { } //소멸자

void Pizza::setPrice() //문제 기본 설정대로 price 및 fee 설정
{
	priceA = 100 - 3 * A.size();
	priceB = 100 - 6 * B.size();
	feeA = 10 - A.size();
	feeB = 10 - B.size();
}

void Pizza::setPrice(float a, float b) //입력받은 수를 이용해 price 및 fee 재설정
{
	priceA = 100 - a * A.size();
	priceB = 100 - b * B.size();
	feeA = 10 - A.size();
	feeB = 10 - B.size();
}

void Pizza::hire(const Rider& rider)
{
	R.erase(R.begin());

	R.push_back(rider); //맨 뒤에 새로운 rider 정보 추가
}

void Pizza::hire(const Rider* riders, int size)
{
	for (int i = 0; i < size; i++) //맨 앞부터 size만큼의 rider 정보 삭제
	{
		R.erase(R.begin());
	}

	R.insert(R.end(), riders, riders + size); //맨 뒤에 새로운 rider 배열 추가
}

void Pizza::enroll(const Customer& customer, bool a)
{
	if (a == true) //A에 새로운 손님 추가
	{
		if (A.size() + B.size() == 10 && B.size() > 0) //10명이 꽉 차 있고 B에 손님이 있는 경우
		{
			B.erase(B.begin()); //B의 맨 앞에 있는 손님을 삭제
		}
		
		else if (A.size() + B.size() == 10 && B.size() <= 0) //10명이 꽉 찼으나 B에 손님이 없는 경우
		{
			A.erase(A.begin());
		}

		A.push_back(customer); //A의 맨 뒤에 새로운 손님 추가

		setPrice();
	}

	else //B에 새로운 손님 추가
	{
		if (A.size() + B.size() == 10 && A.size() > 0) //10명이 꽉 차 있고 A에 손님이 있는 경우
		{
			A.erase(A.begin()); //B의 맨 앞에 있는 손님을 삭제
		}

		else if (A.size() + B.size() == 10 && A.size() <= 0) //10명이 꽉 찼으나 A에 손님이 없는 경우
		{
			B.erase(B.begin());
		}

		B.push_back(customer); //B의 맨 뒤에 새로운 손님 추가

		setPrice();
	}
}

void Pizza::enroll(const Customer* customers, int size, bool a)
{
	if (a == true) //A에 새로운 손님 추가
	{
		if ((A.size() + size >= 10) && (B.size() > 0)) //A에 있는 원소부터 빼줘야 할 때 + B에 원소가 있을 때
		{
			int eraseA = A.size() + size - 10; //A에서 빼줘야 하는 원소 개수

			for (int i = 0; i < eraseA; i++) //앞에서부터 eraseA만큼의 원소 빼주기
			{
				A.erase(A.begin());
			}

			for (int i = 0; i < size; i++) //새로운 손님 배열 추가
			{
				A.push_back(*(customers + i));
			}

			for (int i = 0; i < B.size(); i++) //B.size()만큼의 원소 빼주기 (10명으로 맞추는 과정)
			{
				B.erase(B.begin());
			}
		}

		else if ((A.size() + size >= 10) && (B.size() <= 0)) //B에 원소가 없는 상태일 때
		{
			int eraseA = A.size() + size - 10; //A에서 빼줘야 하는 원소 개수

			for (int i = 0; i < eraseA; i++) //앞에서부터 eraseA만큼의 원소 빼주기 + 뒤에 새로운 원소 추가
			{
				A.erase(A.begin());
				A.push_back(*(customers + i));
			}
		}

		else if (A.size() + size < 10)
		{
			for (int i = 0; i < size; i++) //A에 새로운 손님 추가
			{
				A.push_back(*(customers + i));
			}

			for (int i = 0; i < size; i++) //B에서 size만큼의 원소 빼주기
			{
				B.erase(B.begin());
			}
		}
	}

	else  //B에 새로운 손님 추가
	{
		if ((B.size() + size >= 10) && (A.size() > 0)) //B에 있는 원소부터 빼줘야 할 때 + A에 원소가 있을 때
		{
			int eraseB = B.size() + size - 10; //B에서 빼줘야 하는 원소 개수

			for (int i = 0; i < eraseB; i++) //앞에서부터 eraseB만큼의 원소 빼주기
			{
				B.erase(B.begin());
			}

			for (int i = 0; i < size; i++) //새로운 손님 배열 추가
			{
				B.push_back(*(customers + i));
			}

			for (int i = 0; i < A.size(); i++) //A.size()만큼의 원소 빼주기 (10명으로 맞추는 과정)
			{
				A.erase(A.begin());
			}
		}

		else if ((B.size() + size >= 10) && (A.size() <= 0)) //A에 원소가 없는 상태일 때
		{
			int eraseB = B.size() + size - 10; //B에서 빼줘야 하는 원소 개수

			for (int i = 0; i < eraseB; i++) //앞에서부터 eraseB만큼의 원소 빼주기 + 뒤에 새로운 원소 추가
			{
				B.erase(B.begin());
				B.push_back(*(customers + i));
			}
		}

		else if (B.size() + size < 10)
		{
			for (int i = 0; i < size; i++) //B에 새로운 손님 추가
			{
				B.push_back(*(customers + i));
			}

			for (int i = 0; i < size; i++) //A에서 eraseA만큼의 원소 빼주기
			{
				A.erase(A.begin());
			}
		}
	}

	setPrice();
}

float Pizza::reportMoney() const
{
	return money;
}

int Pizza::numRiders() const
{
	return R.size();
}

int Pizza::numCustomers(bool a) const
{
	if (a == true) //A지역 고객 수 리턴
		return A.size();

	else //B지역 고객수 리턴
		return B.size();
}

float Pizza::meanFee() const
{
	float totalFee = 0;

	for (int i = 0; i < R.size(); i++) //모든 fee 더하여 총합 저장하기
	{
		totalFee += R[i].reportMoney();
	}

	return totalFee / (float)R.size(); //평균 내어 반환
}

float Pizza::meanTimeRiders() const
{
	float totalTime = 0;

	for (int i = 0; i < R.size(); i++) //모든 time 더하여 총합 저장하기
	{
		totalTime += R[i].reportTime();
	}

	return totalTime / (float)R.size(); //평균 내어 반환
}

float Pizza::meanMoneyCustomers() const
{
	float totalMoney = 0;

	for (int i = 0; i < A.size(); i++) //A구역 손님들의 paidmoney 더하여 총합 변수에 저장하기 (reportMoney로 private 변수값 반환받음)
	{
		totalMoney += A[i].reportMoney();
	}

	for (int i = 0; i < B.size(); i++) //B구역 손님들의 paidmoney 더하여 총합 변수에 저장하기 (reportMoney로 private 변수값 반환받음)
	{
		totalMoney += B[i].reportMoney();
	}

	return totalMoney / (float)10; //평균 내어 반환
}

float Pizza::meanTimeCustomers() const
{
	float totalTime = 0;

	for (int i = 0; i < A.size(); i++) //A구역 손님들의 time 더하여 총합 변수에 저장하기
	{
		totalTime += A[i].reportTime();
	}

	for (int i = 0; i < B.size(); i++) //B구역 손님들의 time 더하여 총합 변수에 저장하기
	{
		totalTime += B[i].reportTime();
	}

	return totalTime / (float)10; //평균 내어 반환
}

void Pizza::deliver()
{
	int riderInd = -10; //라이더 배열 인덱스 저장용 변수
	int loopCnt = 0; //라이더가 A구역에서 두 번 배달하는지 여부(즉, A.size() >= 5인지)를 표시

	for (int i = 0; i < A.size(); i++) //A 지역부터 배달
	{
		if (i >= 5)
		{
			loopCnt = 1;
			
			A[i].pay(priceA, timeA); //i번째 고객에게 피자 배달
			(*this).money += priceA; //가게 수입 증가

			riderInd = i - 5; //라이더 5명이 모두 배달한 상태이므로 1바퀴 돌아와서 R[0]부터 배달 재개
			R[riderInd].deliver(feeA, timeA); //R[riderInd] 라이더가 피자 배달
			(*this).money -= feeA; //가게가 수수료 지불			
		}

		else
		{
			A[i].pay(priceA, timeA); //i번째 고객에게 피자 배달
			(*this).money += priceA; //가게 수입 증가

			riderInd = i;
			R[i].deliver(feeA, timeA); //R[i] 라이더가 피자 배달
			(*this).money -= feeA; //가게가 수수료 지불
		}
	}

	riderInd++; //다음에 배달할 라이더를 가리키도록 업데이트

	if (riderInd >= 5)
	{
		loopCnt = 1;
		riderInd = 0;
	}

	for (int i = 0; i < B.size(); i++)
	{
		if (loopCnt > 0 && riderInd >= 0 && riderInd < 5) //A.size() >= 5이고, A구역 배달 종료 시 두 번 배달을 하지 않은 라이더가 있을 경우
		{
			B[i].pay(priceB, timeB); //i번째 고객에게 피자 배달
			(*this).money += priceB; //가게 수입 증가

			R[riderInd].deliver(feeB, timeB); //R[riderInd] 라이더가 피자 배달
			(*this).money -= feeB; //가게가 수수료 지불
			
			riderInd++; //인덱스 업데이트
		}

		else //A.size() < 5인 경우
		{
			if (riderInd >= 5) //rider가 두 번째 배달을 하게 될 경우 인덱스 업데이트
			{
				riderInd = i - 5 + A.size();
			}

			B[i].pay(priceB, timeB); //i번째 고객에게 피자 배달
			(*this).money += priceB; //가게 수입 증가

			R[riderInd].deliver(feeB, timeB); //R[riderInd] 라이더가 피자 배달
			(*this).money -= feeB; //가게가 수수료 지불

			riderInd++;
		}
	}
}

ostream& operator<<(ostream& os, const Pizza& x) //문제에 제시된 대로 출력할 수 있도록 함수 구현
{
	os << "1) Money : " << x.money << endl;
	os << "2) (Customers, Price, Fee)" << endl;
	os << "- A : (" << x.A.size() << ", " << x.priceA << ", " << x.feeA << ")" << endl;
	os << "- B: (" << x.B.size() << ", " << x.priceB << ", " << x.feeB << ")" << endl;
	os << "3) Riders: " << x.R.size() << endl;

	return os;
}