#include "Pizza.h"

Pizza::Pizza()
{
	A = Vector_Customer(5); //���� �⺻ ������� Vector_Customer ����
	B = Vector_Customer(5); //���� �⺻ ������� Vector_Customer ����

	R = Vector_Rider(5); //���� �⺻ ������� Vector_Rider ����

	setPrice(); //������ private ���� ����
}

Pizza::Pizza(float money)
{
	A = Vector_Customer(5); //���� �⺻ ������� Vector_Customer ����
	B = Vector_Customer(5); //���� �⺻ ������� Vector_Customer ����

	R = Vector_Rider(5); //���� �⺻ ������� Vector_Rider ����

	(*this).money = money; //�Է¹��� ������ money ����

	setPrice(); //������ private ���� ����
}

Pizza::Pizza(const Pizza& pizza) //pizza�� ������ �����Ͽ� ���ο� ��ü ����
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

Pizza::~Pizza() { } //�Ҹ���

void Pizza::setPrice() //���� �⺻ ������� price �� fee ����
{
	priceA = 100 - 3 * A.size();
	priceB = 100 - 6 * B.size();
	feeA = 10 - A.size();
	feeB = 10 - B.size();
}

void Pizza::setPrice(float a, float b) //�Է¹��� ���� �̿��� price �� fee �缳��
{
	priceA = 100 - a * A.size();
	priceB = 100 - b * B.size();
	feeA = 10 - A.size();
	feeB = 10 - B.size();
}

void Pizza::hire(const Rider& rider)
{
	R.erase(R.begin());

	R.push_back(rider); //�� �ڿ� ���ο� rider ���� �߰�
}

void Pizza::hire(const Rider* riders, int size)
{
	for (int i = 0; i < size; i++) //�� �պ��� size��ŭ�� rider ���� ����
	{
		R.erase(R.begin());
	}

	R.insert(R.end(), riders, riders + size); //�� �ڿ� ���ο� rider �迭 �߰�
}

void Pizza::enroll(const Customer& customer, bool a)
{
	if (a == true) //A�� ���ο� �մ� �߰�
	{
		if (A.size() + B.size() == 10 && B.size() > 0) //10���� �� �� �ְ� B�� �մ��� �ִ� ���
		{
			B.erase(B.begin()); //B�� �� �տ� �ִ� �մ��� ����
		}
		
		else if (A.size() + B.size() == 10 && B.size() <= 0) //10���� �� á���� B�� �մ��� ���� ���
		{
			A.erase(A.begin());
		}

		A.push_back(customer); //A�� �� �ڿ� ���ο� �մ� �߰�

		setPrice();
	}

	else //B�� ���ο� �մ� �߰�
	{
		if (A.size() + B.size() == 10 && A.size() > 0) //10���� �� �� �ְ� A�� �մ��� �ִ� ���
		{
			A.erase(A.begin()); //B�� �� �տ� �ִ� �մ��� ����
		}

		else if (A.size() + B.size() == 10 && A.size() <= 0) //10���� �� á���� A�� �մ��� ���� ���
		{
			B.erase(B.begin());
		}

		B.push_back(customer); //B�� �� �ڿ� ���ο� �մ� �߰�

		setPrice();
	}
}

void Pizza::enroll(const Customer* customers, int size, bool a)
{
	if (a == true) //A�� ���ο� �մ� �߰�
	{
		if ((A.size() + size >= 10) && (B.size() > 0)) //A�� �ִ� ���Һ��� ����� �� �� + B�� ���Ұ� ���� ��
		{
			int eraseA = A.size() + size - 10; //A���� ����� �ϴ� ���� ����

			for (int i = 0; i < eraseA; i++) //�տ������� eraseA��ŭ�� ���� ���ֱ�
			{
				A.erase(A.begin());
			}

			for (int i = 0; i < size; i++) //���ο� �մ� �迭 �߰�
			{
				A.push_back(*(customers + i));
			}

			for (int i = 0; i < B.size(); i++) //B.size()��ŭ�� ���� ���ֱ� (10������ ���ߴ� ����)
			{
				B.erase(B.begin());
			}
		}

		else if ((A.size() + size >= 10) && (B.size() <= 0)) //B�� ���Ұ� ���� ������ ��
		{
			int eraseA = A.size() + size - 10; //A���� ����� �ϴ� ���� ����

			for (int i = 0; i < eraseA; i++) //�տ������� eraseA��ŭ�� ���� ���ֱ� + �ڿ� ���ο� ���� �߰�
			{
				A.erase(A.begin());
				A.push_back(*(customers + i));
			}
		}

		else if (A.size() + size < 10)
		{
			for (int i = 0; i < size; i++) //A�� ���ο� �մ� �߰�
			{
				A.push_back(*(customers + i));
			}

			for (int i = 0; i < size; i++) //B���� size��ŭ�� ���� ���ֱ�
			{
				B.erase(B.begin());
			}
		}
	}

	else  //B�� ���ο� �մ� �߰�
	{
		if ((B.size() + size >= 10) && (A.size() > 0)) //B�� �ִ� ���Һ��� ����� �� �� + A�� ���Ұ� ���� ��
		{
			int eraseB = B.size() + size - 10; //B���� ����� �ϴ� ���� ����

			for (int i = 0; i < eraseB; i++) //�տ������� eraseB��ŭ�� ���� ���ֱ�
			{
				B.erase(B.begin());
			}

			for (int i = 0; i < size; i++) //���ο� �մ� �迭 �߰�
			{
				B.push_back(*(customers + i));
			}

			for (int i = 0; i < A.size(); i++) //A.size()��ŭ�� ���� ���ֱ� (10������ ���ߴ� ����)
			{
				A.erase(A.begin());
			}
		}

		else if ((B.size() + size >= 10) && (A.size() <= 0)) //A�� ���Ұ� ���� ������ ��
		{
			int eraseB = B.size() + size - 10; //B���� ����� �ϴ� ���� ����

			for (int i = 0; i < eraseB; i++) //�տ������� eraseB��ŭ�� ���� ���ֱ� + �ڿ� ���ο� ���� �߰�
			{
				B.erase(B.begin());
				B.push_back(*(customers + i));
			}
		}

		else if (B.size() + size < 10)
		{
			for (int i = 0; i < size; i++) //B�� ���ο� �մ� �߰�
			{
				B.push_back(*(customers + i));
			}

			for (int i = 0; i < size; i++) //A���� eraseA��ŭ�� ���� ���ֱ�
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
	if (a == true) //A���� �� �� ����
		return A.size();

	else //B���� ���� ����
		return B.size();
}

float Pizza::meanFee() const
{
	float totalFee = 0;

	for (int i = 0; i < R.size(); i++) //��� fee ���Ͽ� ���� �����ϱ�
	{
		totalFee += R[i].reportMoney();
	}

	return totalFee / (float)R.size(); //��� ���� ��ȯ
}

float Pizza::meanTimeRiders() const
{
	float totalTime = 0;

	for (int i = 0; i < R.size(); i++) //��� time ���Ͽ� ���� �����ϱ�
	{
		totalTime += R[i].reportTime();
	}

	return totalTime / (float)R.size(); //��� ���� ��ȯ
}

float Pizza::meanMoneyCustomers() const
{
	float totalMoney = 0;

	for (int i = 0; i < A.size(); i++) //A���� �մԵ��� paidmoney ���Ͽ� ���� ������ �����ϱ� (reportMoney�� private ������ ��ȯ����)
	{
		totalMoney += A[i].reportMoney();
	}

	for (int i = 0; i < B.size(); i++) //B���� �մԵ��� paidmoney ���Ͽ� ���� ������ �����ϱ� (reportMoney�� private ������ ��ȯ����)
	{
		totalMoney += B[i].reportMoney();
	}

	return totalMoney / (float)10; //��� ���� ��ȯ
}

float Pizza::meanTimeCustomers() const
{
	float totalTime = 0;

	for (int i = 0; i < A.size(); i++) //A���� �մԵ��� time ���Ͽ� ���� ������ �����ϱ�
	{
		totalTime += A[i].reportTime();
	}

	for (int i = 0; i < B.size(); i++) //B���� �մԵ��� time ���Ͽ� ���� ������ �����ϱ�
	{
		totalTime += B[i].reportTime();
	}

	return totalTime / (float)10; //��� ���� ��ȯ
}

void Pizza::deliver()
{
	int riderInd = -10; //���̴� �迭 �ε��� ����� ����
	int loopCnt = 0; //���̴��� A�������� �� �� ����ϴ��� ����(��, A.size() >= 5����)�� ǥ��

	for (int i = 0; i < A.size(); i++) //A �������� ���
	{
		if (i >= 5)
		{
			loopCnt = 1;
			
			A[i].pay(priceA, timeA); //i��° ������ ���� ���
			(*this).money += priceA; //���� ���� ����

			riderInd = i - 5; //���̴� 5���� ��� ����� �����̹Ƿ� 1���� ���ƿͼ� R[0]���� ��� �簳
			R[riderInd].deliver(feeA, timeA); //R[riderInd] ���̴��� ���� ���
			(*this).money -= feeA; //���԰� ������ ����			
		}

		else
		{
			A[i].pay(priceA, timeA); //i��° ������ ���� ���
			(*this).money += priceA; //���� ���� ����

			riderInd = i;
			R[i].deliver(feeA, timeA); //R[i] ���̴��� ���� ���
			(*this).money -= feeA; //���԰� ������ ����
		}
	}

	riderInd++; //������ ����� ���̴��� ����Ű���� ������Ʈ

	if (riderInd >= 5)
	{
		loopCnt = 1;
		riderInd = 0;
	}

	for (int i = 0; i < B.size(); i++)
	{
		if (loopCnt > 0 && riderInd >= 0 && riderInd < 5) //A.size() >= 5�̰�, A���� ��� ���� �� �� �� ����� ���� ���� ���̴��� ���� ���
		{
			B[i].pay(priceB, timeB); //i��° ������ ���� ���
			(*this).money += priceB; //���� ���� ����

			R[riderInd].deliver(feeB, timeB); //R[riderInd] ���̴��� ���� ���
			(*this).money -= feeB; //���԰� ������ ����
			
			riderInd++; //�ε��� ������Ʈ
		}

		else //A.size() < 5�� ���
		{
			if (riderInd >= 5) //rider�� �� ��° ����� �ϰ� �� ��� �ε��� ������Ʈ
			{
				riderInd = i - 5 + A.size();
			}

			B[i].pay(priceB, timeB); //i��° ������ ���� ���
			(*this).money += priceB; //���� ���� ����

			R[riderInd].deliver(feeB, timeB); //R[riderInd] ���̴��� ���� ���
			(*this).money -= feeB; //���԰� ������ ����

			riderInd++;
		}
	}
}

ostream& operator<<(ostream& os, const Pizza& x) //������ ���õ� ��� ����� �� �ֵ��� �Լ� ����
{
	os << "1) Money : " << x.money << endl;
	os << "2) (Customers, Price, Fee)" << endl;
	os << "- A : (" << x.A.size() << ", " << x.priceA << ", " << x.feeA << ")" << endl;
	os << "- B: (" << x.B.size() << ", " << x.priceB << ", " << x.feeB << ")" << endl;
	os << "3) Riders: " << x.R.size() << endl;

	return os;
}