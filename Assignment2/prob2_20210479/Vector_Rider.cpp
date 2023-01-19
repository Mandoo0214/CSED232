#include "Vector_Rider.h"

Vector_Rider::Vector_Rider() { } //private ���� ���� �� �ʱ�ȭ

Vector_Rider::Vector_Rider(int size)
{
	arrCapacity = size; //�Ҵ�� �޸� ������ ������Ʈ
	realLength = size; //���� ������ ������Ʈ

	arr = new Rider[size]; //size��ŭ �޸𸮸� ���� �Ҵ�
}

Vector_Rider::Vector_Rider(int size, const Rider& init)
{
	arrCapacity = size; //�Ҵ�� �޸� ������ ������Ʈ
	realLength = size; //��� ���Ұ� init���� �ʱ�ȭ�ǹǷ� size == length

	arr = new Rider[size]; //size��ŭ �޸𸮸� ���� �Ҵ�

	for (int i = 0; i < size; i++) //��� ���Ҹ� init���� �ʱ�ȭ
	{
		arr[i] = init;
	}
}

Vector_Rider::Vector_Rider(int size, const Rider* init)
{
	arrCapacity = size; //�Ҵ�� �޸� ������ ������Ʈ
	realLength = size; //���� ������ ���� ������Ʈ

	arr = new Rider[size]; //size��ŭ �޸𸮸� ���� �Ҵ�

	for (int i = 0; i < size; i++) //�迭�� ���� ����
	{
		arr[i] = init[i];
	}
}

Vector_Rider::Vector_Rider(const Vector_Rider& v)
{
	arrCapacity = v.arrCapacity; //�Ҵ�� �޸� ������ ����
	realLength = v.realLength; //���� ������ ���� ������Ʈ

	arr = new Rider[arrCapacity]; //size��ŭ �޸𸮸� ���� �Ҵ�

	for (int i = 0; i < arrCapacity; i++) //�迭�� ���� ����
	{
		arr[i] = v.arr[i];
	}
}

Vector_Rider::~Vector_Rider()
{
	delete[] arr;
}

int Vector_Rider::capacity() const
{
	return arrCapacity;
}

int Vector_Rider::size() const
{
	return realLength;
}

Vector_Rider::iterator Vector_Rider::begin()
{
	iterator firstAdd = &arr[0]; //������ �迭�� �� ó�� �ּ� ����

	return firstAdd;
}

Vector_Rider::const_iterator Vector_Rider::begin() const
{
	const_iterator firstAdd = &arr[0]; //������ �迭�� �� ó�� �ּ� ���� (const ver)

	return firstAdd;
}

Vector_Rider::iterator Vector_Rider::end()
{
	iterator lastAdd = &arr[realLength]; //������ �迭�� �� ������ �ּ� ���� ���� ����

	return lastAdd;
}

Vector_Rider::const_iterator Vector_Rider::end() const
{
	const_iterator lastAdd = &arr[realLength]; //������ �迭�� �� ������ �ּ� ���� ���� ���� (const ver)

	return lastAdd;
}

Rider& Vector_Rider::front()
{
	return arr[0]; //�� �� ������ ��ȯ
}

const Rider& Vector_Rider::front() const
{
	const Rider& front = arr[0]; //arr[0]�� ���� ������ const reference ���� ���� 

	return front;
}

Rider& Vector_Rider::back()
{
	return arr[realLength - 1];
}

const Rider& Vector_Rider::back() const
{
	const Rider& last = arr[realLength - 1]; //arr[realLength - 1]�� ���� ������ const reference ���� ����

	return last;
}

void Vector_Rider::allocate(int capacity)
{
	Rider* newarr = new Rider[realLength]; //������ ����� �迭 ����

	for (int i = 0; i < realLength; i++) //���� ������ ����
	{
		newarr[i] = arr[i];
	}

	if (capacity <= realLength) //���� �Ҵ��� �� capacity�� ������ �������� �۰ų� ���� ��
	{
		if (realLength < 5) //���� ������ ������ 5�� �̸��� ��
		{
			arrCapacity = realLength; //���� ������ ������ŭ�� �޸𸮸� �Ҵ�

			delete[] arr; //���� �迭 ����
			arr = new Rider[arrCapacity]; //���� �迭�� ���� ������ ������ŭ ���� �޸𸮸� �Ҵ�

			for (int i = 0; i < arrCapacity; i++) //���� ���� �Ҵ��� �� �ٽ� ������ ����
			{
				arr[i] = newarr[i];
			}
		}

		else //���� ������ ������ 5�� �̻��� ��
		{
			arrCapacity = 2 * realLength;

			delete[] arr; //���� �迭 ����
			arr = new Rider[arrCapacity]; //���� �迭�� ���� ������ ������ 2�踸ŭ ���� �޸𸮸� �Ҵ�

			for (int i = 0; i < realLength; i++) //���� �迭 ���� ������ ����
			{
				arr[i] = newarr[i];
			}
		}
	}

	else //���� �Ҵ��� �� capacity�� �˳��� ��
	{
		if (arrCapacity) //�迭�� ����ִ� ���Ұ� ���� ��
		{
			arrCapacity = capacity; //�Ҵ�� �޸� ũ�� ������Ʈ

			delete[] arr; //���� �迭 ����
			arr = new Rider[arrCapacity]; //���� �迭�� capacity��ŭ ���� �޸𸮸� �Ҵ�
		}

		else //�迭�� ����ִ� ���Ұ� ���� ��
		{
			arrCapacity = capacity; //�Ҵ�� �޸� ũ�� ������Ʈ

			arr = new Rider[arrCapacity]; //���� �迭�� capacity��ŭ ���� �޸𸮸� �Ҵ�
		}

		for (int i = 0; i < realLength; i++) //�޸� ���� (���� ������ ������ �����ϰ� ������)
		{
			arr[i] = newarr[i];
		}
	}
}

void Vector_Rider::resize(int size)
{
	Rider* newarr = new Rider[realLength]; //������ ����� �迭 ����

	for (int i = 0; i < realLength; i++) //���� �迭 ���� ������ ����
	{
		newarr[i] = arr[i];
	}

	if (size <= arrCapacity) //���� �Ҵ��Ϸ��� size�� �� �۰ų� ���� ���
	{
		if (realLength == 0) //�����Ͱ� �� ����־��� ���
		{
			arrCapacity = size; //�Ҵ�� �޸� ũ�� ������Ʈ

			arr = new Rider[size]; //���� �迭�� size��ŭ ���� �޸𸮸� �Ҵ�
		}

		else
		{
			arrCapacity = size; //�Ҵ�� �޸� ũ�� ������Ʈ

			delete[] arr; //���� �迭 ����
			arr = new Rider[size]; //���� �迭�� size��ŭ ���� �޸𸮸� �Ҵ�

			realLength = size; //���� ������ ���� ������Ʈ

			for (int i = 0; i < size; i++) //size������ ������ ������ ������ ����
			{
				arr[i] = newarr[i];
			}
		}
	}

	else //���� �Ҵ��Ϸ��� �޸𸮰� �� Ŭ ��
	{
		arrCapacity = size;

		if (arr != NULL)
		{
			delete[] arr;
		}

		arr = new Rider[size];

		for (int i = 0; i < realLength; i++)
		{
			arr[i] = newarr[i];
		}
	}
}

void Vector_Rider::push_back(const Rider& value)
{
	realLength++; //���� ������ ���� ������Ʈ

	if (realLength >= arrCapacity) //������ �߰� �� �Ҵ�� ������ ũ�⸦ �ʰ��ϴ� ���
	{
		Rider* newarr = new Rider[realLength]; //������ ����� �迭 ����

		for (int i = 0; i < realLength; i++) //�� �������� ���ο� ���� �߰�
		{
			if (i == realLength - 1)
			{
				newarr[i] = value;
			}

			else
			{
				newarr[i] = arr[i];
			}
		}

		if (realLength < 5) //���� ������ ������ 5 �̸��� ��
		{
			arrCapacity = realLength;

			delete[] arr; //���� �迭 ����
			arr = new Rider[arrCapacity]; //���� �迭�� ���� ������ ������ŭ�� �޸𸮸� ���� �Ҵ�

			for (int i = 0; i < arrCapacity; i++) //������ ����
			{
				arr[i] = newarr[i];
			}
		}

		else //���� ������ ������ 5 �̻��� ��
		{
			arrCapacity = realLength * 2;

			delete[] arr; //���� �迭 ����
			arr = new Rider[arrCapacity]; //���� �迭�� realLength�� 2�踸ŭ�� �޸𸮸� ���� �Ҵ�

			for (int i = 0; i < realLength; i++) //������ ����
			{
				arr[i] = newarr[i];
			}
		}
	}

	else //capacity�� ����� ��
	{
		arr[realLength - 1] = value; //�� �������� ���ο� ���� �߰�
	}
}

void Vector_Rider::pop_back()
{
	realLength--; //���� ������ ���� ������Ʈ (���߿� ���� �� ���� ������)
}

void Vector_Rider::insert(iterator position, const Rider& value)
{
	realLength++;

	if (realLength >= arrCapacity) //������ �߰� �� �Ҵ�� ������ ũ�⸦ �ʰ��ϴ� ���
	{
		Rider* newarr = new Rider[realLength]; //������ ����� �迭 ����

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

		if (realLength < 5) //���� ������ ������ 5 �̸��� ��
		{
			arrCapacity = realLength;

			if (arr != NULL)
			{
				delete[] arr;
			}

			arr = new Rider[arrCapacity]; //���� �迭�� ���� ������ ������ŭ�� �޸𸮸� ���� �Ҵ�

			for (int i = 0; i < realLength; i++) //������ ����
			{
				arr[i] = newarr[i];
			}
		}

		else //���� ������ ������ 5 �̻��� ��
		{
			arrCapacity = realLength * 2;

			if (arr != NULL)
			{
				delete[] arr; //���� �迭 ����
			}

			arr = new Rider[arrCapacity]; //���� �迭�� ���� ������ ������ 2�踸ŭ�� �޸𸮸� ���� �Ҵ�

			for (int i = 0; i < realLength; i++) //������ ����
			{
				arr[i] = newarr[i];
			}
		}
	}

	else //capacity�� ����� ��
	{
		Rider* newarr2 = new Rider[realLength]; //position ���� ���Ҹ� �������� �迭

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

				newarr2[i] = arr[i];
			}
		}

		for (int i = 0; i < realLength; i++)
		{
			if (i < ind) //poistion ������ ���Ҵ� �ǵ帮�� ����
				continue;

			else if (i == ind) //position�� ���ο� ���� ����
			{
				arr[i] = value;
			}

			else //postion ���� ���Ҵ� �ϳ��� �̷� ����
			{
				arr[i] = newarr2[ind];
				ind++;
			}
		}
	}
}

void Vector_Rider::insert(iterator position, const Rider* first, const Rider* last)
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

	Rider* newarr = new Rider[realLength]; //������ ����� �迭 ����

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

			if (arr != NULL)
			{
				delete[] arr; //���� �迭 ����
			}

			arr = new Rider[arrCapacity]; //�迭�� ���� ������ ������ŭ �޸𸮸� ���� �Ҵ�

			for (int i = 0; i < arrCapacity; i++) //���ο� ���Ҹ� ���� �����͸� ����
			{
				arr[i] = newarr[i];
			}
		}

		else //���� ������ ������ 5 �̻��� ��
		{
			arrCapacity = realLength * 2;

			if (arr != NULL)
			{
				delete[] arr; //���� �迭 ����
			}

			arr = new Rider[arrCapacity]; //�迭�� ���� ������ ���� * 2��ŭ �޸𸮸� ���� �Ҵ�

			for (int i = 0; i < realLength; i++) //���ο� ���Ҹ� ���� �����͸� ����
			{
				arr[i] = newarr[i];
			}
		}
	}

	else //�޸𸮿� ������ ���� ��
	{
		for (int i = 0; i < realLength; i++)
		{
			arr[i] = newarr[i];
		}
	}
}

void Vector_Rider::erase(iterator position)
{
	for (int i = 0; i < arrCapacity; i++)
	{
		if (&arr[i] < position) //�����ؾ� �ϴ� ��ġ �������� skip
			continue;

		else if (&arr[i] >= position && i < realLength - 1) //position���� �� ���� ���ҵ��� �� �ڸ��� ��ܼ� ����
		{
			arr[i] = arr[i + 1];
		}

		else //���� ������ skip
			break;
	}

	realLength--; //���� ������ ���� ������Ʈ
}

void Vector_Rider::clear()
{
	delete[] arr; //�迭 �Ҵ� �޸� ����
	arrCapacity = 0; //capacity ����
	realLength = 0; //������ ���� ����
}

Rider& Vector_Rider::operator[](int index)
{
	return arr[index];
}

const Rider& Vector_Rider::operator[](int index) const
{
	const Rider& i = arr[index];

	return i;
}

Vector_Rider& Vector_Rider::operator=(const Vector_Rider& v)
{
	arrCapacity = v.arrCapacity;
	realLength = v.realLength;

	arr = new Rider[arrCapacity];

	for (int i = 0; i < realLength; i++)
	{
		arr[i] = v.arr[i];
	}

	return *this;
}