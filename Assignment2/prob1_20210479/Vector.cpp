/* ��ü���� ���α׷��� Assignment 2 Prob1_20210479 ������*/

#include "Vector.h"
#include <cstdio>

using namespace std;

Vector::Vector() { } //class ������ ��� ���� ���� �� �ʱ�ȭ�Ͽ���

Vector::Vector(int size)
{
	arrCapacity = size; //�Ҵ�� �޸� ������ ������Ʈ, ���� ������ ������ 0���� ������
	arr = new float[size]{0, }; //size��ŭ �޸𸮸� ���� �Ҵ�, ��� ���� 0���� �ʱ�ȭ
}

Vector::Vector(int size, const float& init)
{
	arrCapacity = size; //�Ҵ�� �޸� ������ ������Ʈ
	realLength = size; //��� ���Ұ� init���� �ʱ�ȭ�ǹǷ� size == length

	arr = new float[size]; //size��ŭ �޸𸮸� ���� �Ҵ�

	for (int i = 0; i < size; i++) //�迭�� ��� ���� init���� �ʱ�ȭ
	{
		arr[i] = init;
	}
}

Vector::Vector(int size, const float* init)
{
	arrCapacity = size; //�Ҵ�� �޸� ������ ������Ʈ

	for (int i = 0; i < size; i++)
	{
		if (*(init + i) == '\0')
			break;

		realLength++;
	}

	arr = new float[size]; //size��ŭ �޸𸮸� ���� �Ҵ�
	
	for (int i = 0; i < size; i++)
	{
		if (i < realLength) //init �迭�� ���Ҹ� ��� �Է�
		{
			arr[i] = init[i];
		}

		else //���� size�� realLength���� Ŭ ��� ������ ���ҵ��� 0���� �ʱ�ȭ
		{
			arr[i] = 0;
		}
	}
}

Vector::Vector(const Vector& v)
{
	arrCapacity = v.arrCapacity; //�Ҵ�� �޸� ������ ����
	realLength = v.realLength; //���� ������ ���� ����

	arr = new float[arrCapacity]; //v�� �Ҵ�� �޸� ũ�⸸ŭ�� �޸𸮸� �Ҵ�
	
	for (int i = 0; i < arrCapacity; i++) //v�� ��� ���� ����
	{
		arr[i] = v.arr[i];
	}
}

Vector::~Vector()
{
	delete[] arr;
}

int Vector::capacity() const
{
	return arrCapacity; //�Ҵ�� �޸� ������ ��ȯ
}

int Vector::size() const
{
	return realLength; //���� ������ ���� ��ȯ
}

Vector::iterator Vector::begin()
{
	iterator firstAdd = &arr[0]; //������ �迭�� �� ó�� �ּ� ����

	return firstAdd;
}

Vector::const_iterator Vector::begin() const
{
	const_iterator firstAdd = &arr[0]; //������ �迭�� �� ó�� �ּ� ���� (const ver)

	return firstAdd;
}

Vector::iterator Vector::end()
{
	iterator lastAdd = &arr[realLength]; //������ �迭�� �� ������ �ּ� ���� ���� ����

	return lastAdd;
}

Vector::const_iterator Vector::end() const
{
	const_iterator lastAdd = &arr[realLength]; //������ �迭�� �� ������ �ּ� ���� ���� ���� (const ver)

	return lastAdd;
}

float& Vector::front()
{
	return arr[0]; //�� �� ������ ��ȯ
}

const float& Vector::front() const
{
	const float& front = arr[0]; //arr[0]�� ���� ������ const reference ���� ���� 

	return front;
}

float& Vector::back()
{
	return arr[realLength - 1];
}

const float& Vector::back() const
{
	const float& last = arr[realLength - 1]; //arr[realLength - 1]�� ���� ������ const reference ���� ����

	return last;
}

void Vector::allocate(int capacity)
{
	if (capacity <= realLength) //���� �Ҵ��� �� capacity�� ������ �������� �۰ų� ���� ��
	{
		if (realLength < 5) //���� ������ ������ 5�� �̸��� ��
		{
			arrCapacity = realLength; //���� ������ ������ŭ�� �޸𸮸� �Ҵ�
			float* newarr = new float[arrCapacity]; //������ ����� �迭 ����

			for (int i = 0; i < arrCapacity; i++) //���� �迭 ���� ������ ����
			{
				newarr[i] = arr[i];
			}
			
			delete[] arr; //���� �迭 ����
			arr = new float[arrCapacity]; //���� �迭�� ���� ������ ������ŭ ���� �޸𸮸� �Ҵ�
			
			for (int i = 0; i < arrCapacity; i++) //���� ���� �Ҵ��� �� �ٽ� ������ ����
			{
				arr[i] = newarr[i];
			}
		}

		else //���� ������ ������ 5�� �̻��� ��
		{
			float* newarr2 = new float[realLength]; //������ ����� �迭 ����

			for (int i = 0; i < realLength; i++) //���� �迭 ���� ������ ����
			{
				newarr2[i] = arr[i];
			}

			arrCapacity = 2 * realLength;

			delete[] arr; //���� �迭 ����
			arr = new float[arrCapacity]; //���� �迭�� ���� ������ ������ 2�踸ŭ ���� �޸𸮸� �Ҵ�

			for (int i = 0; i < arrCapacity; i++)
			{
				if (i < realLength) //������ ������ ������ ����
				{
					arr[i] = newarr2[i];
				}

				else //�����Ͱ� �������� �ʴ� ���� ������ 0���� �ʱ�ȭ
				{
					arr[i] = 0;
				}
			}
		}	
	}

	else //���� �Ҵ��� �� capacity�� �˳��� ��
	{
		float* newarr3 = new float[realLength]; //������ ����� �迭 ����

		for (int i = 0; i < realLength; i++) //���� �迭 ���� ������ ����
		{
			newarr3[i] = arr[i];
		}

		if (arrCapacity) //�迭�� ����ִ� ���Ұ� ���� ��
		{
			arrCapacity = capacity;

			delete[] arr; //���� �迭 ����
			arr = new float[arrCapacity]; //���� �迭�� capacity��ŭ ���� �޸𸮸� �Ҵ�
		}

		else //�迭�� ����ִ� ���Ұ� ���� ��
		{
			arrCapacity = capacity;
			arr = new float[arrCapacity]; //���� �迭�� capacity��ŭ ���� �޸𸮸� �Ҵ�
		}
		

		for (int i = 0; i < arrCapacity; i++)
		{
			if (i < realLength) //������ ������ ������ ����
			{
				arr[i] = newarr3[i];
			}

			else //�����Ͱ� �������� �ʴ� ���� ������ 0���� �ʱ�ȭ
			{
				arr[i] = 0;
			}
		}
	}
}

void Vector::resize(int size)
{
	if (size <= arrCapacity) //���� �Ҵ��Ϸ��� size�� �� �۰ų� ���� ���
	{
		float* newarr = new float[size]; //������ ����� �迭 ����

		for (int i = 0; i < size; i++) //���� �迭 ���� ������ �� size ������������ ����
		{
			newarr[i] = arr[i];
		}

		arrCapacity = size;

		delete[] arr; //���� �迭 ����
		arr = new float[size]; //���� �迭�� size��ŭ ���� �޸𸮸� �Ҵ�

		for (int i = 0; i < size; i++) //size������ ������ ������ ������ ����
		{
			arr[i] = newarr[i];
		}

		realLength = size; //���� ������ ���� ������Ʈ
	}
	
	else //���� �Ҵ��Ϸ��� �޸𸮰� �� Ŭ ��
	{
		float* newarr2 = new float[realLength]; //������ ����� �迭 ����

		for (int i = 0; i < realLength; i++) //���� �迭 ���� ������ ����
		{
			newarr2[i] = arr[i];
		}

		arrCapacity = size;

		delete[] arr;
		arr = new float[arrCapacity];

		for (int i = 0; i < size; i++)
		{
			if (i < realLength) //������ ���� ������ ����
			{
				arr[i] = newarr2[i];
			}

			else //���� ������ 0���� �ʱ�ȭ
			{
				arr[i] = 0;
			}
		}
	}
}

void Vector::push_back(const float& value)
{
	realLength++; //���� ������ ���� ������Ʈ

	if (realLength >= arrCapacity) //������ �߰� �� �Ҵ�� ������ ũ�⸦ �ʰ��ϴ� ���
	{
		if (realLength < 5) //���� ������ ������ 5 �̸��� ��
		{
			float* newarr = new float[realLength]; //������ ����� �迭 ����

			for (int i = 0; i < realLength; i++)
			{
				if (i == realLength - 1) //�� �������� ���ο� ���� �߰�
				{
					newarr[i] = value;
				}

				else //������ ������ ������ ���� ����
				{
					newarr[i] = arr[i];
				}
			}

			arrCapacity = realLength;

			delete[] arr; //���� �迭 ����
			arr = new float[arrCapacity]; //���� �迭�� ���� ������ ������ŭ�� �޸𸮸� ���� �Ҵ�

			for (int i = 0; i < arrCapacity; i++)
			{
				if (i < realLength) //������ ������ + ���ο� ���� 1�� ����
				{
					arr[i] = newarr[i];
				}

				else //������ ���� �������� 0�� ����
				{
					arr[i] = 0;
				}
			}
		}
		
		else //���� ������ ������ 5 �̻��� ��
		{
			float* newarr2 = new float[realLength]; //������ ����� �迭 ����

			for (int i = 0; i < realLength; i++)
			{
				if (i == realLength - 1) //�� �������� ���ο� ���� �߰�
				{
					newarr2[i] = value;
				}

				else //������ ������ ������ ���� ����
				{
					newarr2[i] = arr[i];
				}
			}

			arrCapacity = realLength * 2;

			delete[] arr; //���� �迭 ����
			arr = new float[arrCapacity]; //���� �迭�� realLength�� 2�踸ŭ�� �޸𸮸� ���� �Ҵ�

			for (int i = 0; i < arrCapacity; i++)
			{
				if (i < realLength) //������ ������ + ���ο� ���� 1�� ����
				{
					arr[i] = newarr2[i];
				}

				else //������ ���� �������� 0�� ����
				{
					arr[i] = 0;
				}
			}
		}
	}

	else //capacity�� ����� ��
	{
		arr[realLength - 1] = value; //�� �������� ���ο� ���� �߰�
	}
}

void Vector::pop_back()
{
	arr[realLength - 1] = NULL; //������ �����͸� ���� �� ���� ���� ����

	realLength--; //���� ������ ���� ������Ʈ
}

void Vector::insert(iterator position, const float& value)
{
	realLength++;

	if (realLength >= arrCapacity) //������ �߰� �� �Ҵ�� ������ ũ�⸦ �ʰ��ϴ� ���
	{
		if (realLength < 5) //���� ������ ������ 5 �̸��� ��
		{
			float* newarr = new float[realLength]; //������ ����� �迭 ����

			for (int i = 0; i < realLength; i++)
			{
				if (&arr[i] < position) //position �������� ���� ���� ����
				{
					newarr[i] = arr[i];
				}

				else if (&arr[i] == position) //position �ڸ��� ���ο� ���� ����
				{
					newarr[i] = value;
				}

				else //position ���� ���Ҹ� �ϳ��� �̷� ����
				{
					newarr[i] = arr[i - 1];
				}
			}

			arrCapacity = realLength;

			delete[] arr; //���� �迭 ����
			arr = new float[arrCapacity]; //���� �迭�� ���� ������ ������ŭ�� �޸𸮸� ���� �Ҵ�

			for (int i = 0; i < arrCapacity; i++)
			{
				if (i < realLength) //������ ������ + ���ο� ���� 1�� ����
				{
					arr[i] = newarr[i];
				}

				else //������ ���� �������� 0�� ����
				{
					arr[i] = 0;
				}
			}
		}

		else //���� ������ ������ 5 �̻��� ��
		{
			float* newarr2 = new float[realLength]; //������ ����� �迭 ����

			for (int i = 0; i <= realLength; i++)
			{
				if (&arr[i] < position) //position �������� ���� ���� ����
				{
					newarr2[i] = arr[i];
				}

				else if (&arr[i] == position) //position �ڸ��� ���ο� ���� ����
				{
					newarr2[i] = value;
				}

				else //position ���� ���Ҹ� �ϳ��� �̷� ����
				{
					newarr2[i] = arr[i - 1];
				}
			}

			arrCapacity = realLength * 2;

			delete[] arr; //���� �迭 ����
			arr = new float[arrCapacity]; //���� �迭�� ���� ������ ������ 2�踸ŭ�� �޸𸮸� ���� �Ҵ�

			for (int i = 0; i < arrCapacity; i++)
			{
				if (i < realLength) //������ ������ + ���ο� ���� 1�� ����
				{
					arr[i] = newarr2[i];
				}

				else //������ ���� �������� 0�� ����
				{
					arr[i] = 0;
				}
			}
		}
	}

	else //capacity�� ����� ��
	{
		float* newarr3 = new float[realLength]; //position ���� ���Ҹ� �������� �迭

		int ind = 0; //position�� index�� ������ ����

		for (int i = 0; i < realLength; i++)
		{
			if (&arr[i] < position)
				continue;

			else //postion ������ ���Ҹ� ����
			{
				if (&arr[i] == position) //positon�� index ����
				{
					ind = i;
				}

				newarr3[i] = arr[i];
			}
		}

		for (int i = 0; i < arrCapacity; i++)
		{
			if (i < ind) //poistion ������ ���Ҵ� �ǵ帮�� ����
				continue;

			else if (i == ind) //position�� ���ο� ���� ����
			{
				arr[i] = value;
			}

			else if (i > ind && i < realLength)//postion ���� ���Ҵ� �ϳ��� �̷� ����
			{
				arr[i] = newarr3[ind];
				ind++;
			}

			else //���� ������ 0���� �ʱ�ȭ
			{
				arr[i] = 0;
			}
		}
	}
}

void Vector::insert(iterator position, const float* first, const float* last)
{
	int arrSize = 0; //������ �迭�� ũ�� ����� ����
	int ind = 0; //�迭 �ε��� ǥ�ÿ� ����

	while (1) //������ �迭�� ũ�� �˾Ƴ���
	{
		if (first + ind == last)
			break;

		arrSize++; //������ �迭�� ũ�� ������Ʈ
		ind++; //�ε��� ������Ʈ
	}
	
	realLength += arrSize;
	ind = 0; //���� ��Ȱ���� ���� �ʱ�ȭ

	float* newarr = new float[realLength]; //������ ����� �迭 ����

	for (int i = 0; i < realLength; i++)
	{
		if (&arr[i] < position) //position �������� ���� ������ ����
		{
			newarr[i] = arr[i];
		}

		else if (&arr[i] >= position && &arr[i] < position + arrSize) //���ο� �迭 ����
		{
			newarr[i] = *(first + ind);
			ind++;
		}

		else
		{
			newarr[i] = arr[i - ind];
		}
	}

	if (realLength >= arrCapacity)//���� ������ ������ �Ҵ� �޸𸮺��� Ŭ ��
	{
		if (realLength < 5) //���� ������ ������ 5 �̸��� ��
		{
			arrCapacity = realLength;

			delete[] arr; //���� �迭 ����
			arr = new float[arrCapacity]; //�迭�� ���� ������ ������ŭ �޸𸮸� ���� �Ҵ�

			for (int i = 0; i < arrCapacity; i++) //���ο� ���Ҹ� ���� �����͸� ����
			{
				arr[i] = newarr[i];
			}
		}

		else //���� ������ ������ 5 �̻��� ��
		{
			arrCapacity = realLength * 2;

			delete[] arr; //���� �迭 ����
			arr = new float[arrCapacity]; //�迭�� ���� ������ ���� * 2��ŭ �޸𸮸� ���� �Ҵ�

			for (int i = 0; i < arrCapacity; i++) //���ο� ���Ҹ� ���� �����͸� ����
			{
				if (i < realLength) //�����Ͱ� ����ִ� �κ� ����
				{
					arr[i] = newarr[i];
				}

				else //���� ������ 0���� �ʱ�ȭ
				{
					arr[i] = 0;
				}
			}
		}
	}

	else //�޸𸮿� ������ ���� ��
	{
		for (int i = 0; i < arrCapacity; i++)
		{
			if (i < realLength) //�����Ͱ� ����ִ� �κ� ����
			{
				arr[i] = newarr[i];
			}

			else //���� ������ 0���� �ʱ�ȭ
			{
				arr[i] = 0;
			}
		}
	}
}

void Vector::erase(iterator position)
{
	for (int i = 0; i < arrCapacity; i++)
	{
		if (&arr[i] < position) //�����ؾ� �ϴ� ��ġ �������� skip
			continue;

		else if (&arr[i] >= position && i < realLength - 1) //position���� �� ���� ���ҵ��� �� �ڸ��� ��ܼ� ����
		{
			arr[i] = arr[i + 1];
		}

		else //���� ������ 0���� �ʱ�ȭ
		{
			arr[i] = 0;
		}
	}

	realLength--; //���� ������ ���� ������Ʈ
}

void Vector::clear()
{
	delete[] arr; //�迭 �Ҵ� �޸� ����
	arrCapacity = 0; //capacity ����
	realLength = 0; //������ ���� ����
}

float& Vector::operator[](int index)
{
	return arr[index];
}

const float& Vector::operator[](int index) const
{
	const float& i = arr[index]; //���� ���Ŀ� �´� ���� ����

	return i;
}

Vector& Vector::operator=(const Vector& v)
{
	arrCapacity = v.arrCapacity;
	realLength = v.realLength;

	arr = new float[arrCapacity]; //�迭 ���縦 ���� �ʿ��� �޸𸮸�ŭ ���� �Ҵ�

	for (int i = 0; i < arrCapacity; i++) //�迭 �� ������ ����
	{
		arr[i] = v.arr[i];
	}

	return *this;
}