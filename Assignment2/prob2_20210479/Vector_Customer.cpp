#include "Vector_Customer.h"

Vector_Customer::Vector_Customer() { } //private 변수 선언 시 초기화

Vector_Customer::Vector_Customer(int size)
{
	arrCapacity = size; //할당된 메모리 사이즈 업데이트
	realLength = size; //최종 데이터 업데이트

	arr = new Customer[size]; //size만큼 메모리를 동적 할당
}

Vector_Customer::Vector_Customer(int size, const Customer& init)
{
	arrCapacity = size; //할당된 메모리 사이즈 업데이트
	realLength = size; //모든 원소가 init으로 초기화되므로 size == length

	arr = new Customer[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = init;
	}
}

Vector_Customer::Vector_Customer(int size, const Customer* init)
{
	arrCapacity = size; //할당된 메모리 사이즈 업데이트
	realLength = size; //최종 데이터 개수 업데이트

	arr = new Customer[size]; //size만큼 메모리를 동적 할당

	for (int i = 0; i < size; i++) //배열의 원소 복사
	{
		arr[i] = init[i];
	}
}

Vector_Customer::Vector_Customer(const Vector_Customer& v)
{
	arrCapacity = v.arrCapacity; //할당된 메모리 사이즈 복사
	realLength = v.realLength; //최종 데이터 개수 업데이트

	arr = new Customer[arrCapacity]; //size만큼 메모리를 동적 할당

	for (int i = 0; i < arrCapacity; i++) //배열의 원소 복사
	{
		arr[i] = v.arr[i];
	}
}

Vector_Customer::~Vector_Customer()
{
	delete[] arr;
}

int Vector_Customer::capacity() const
{
	return arrCapacity;
}

int Vector_Customer::size() const
{
	return realLength;
}

Vector_Customer::iterator Vector_Customer::begin()
{
	iterator firstAdd = &arr[0]; //데이터 배열의 맨 처음 주소 대입

	return firstAdd;
}

Vector_Customer::const_iterator Vector_Customer::begin() const
{
	const_iterator firstAdd = &arr[0]; //데이터 배열의 맨 처음 주소 대입 (const ver)

	return firstAdd;
}

Vector_Customer::iterator Vector_Customer::end()
{
	iterator lastAdd = &arr[realLength]; //데이터 배열의 맨 마지막 주소 다음 것을 대입

	return lastAdd;
}

Vector_Customer::const_iterator Vector_Customer::end() const
{
	const_iterator lastAdd = &arr[realLength]; //데이터 배열의 맨 마지막 주소 다음 것을 대입 (const ver)

	return lastAdd;
}

Customer& Vector_Customer::front()
{
	return arr[0]; //맨 앞 데이터 반환
}

const Customer& Vector_Customer::front() const
{
	const Customer& front = arr[0]; //arr[0]의 값을 대입한 const reference 변수 선언 

	return front;
}

Customer& Vector_Customer::back()
{
	return arr[realLength - 1];
}

const Customer& Vector_Customer::back() const
{
	const Customer& last = arr[realLength - 1]; //arr[realLength - 1]의 값을 대입한 const reference 변수 선언

	return last;
}

void Vector_Customer::allocate(int capacity)
{
	Customer* newarr = new Customer[realLength]; //데이터 복사용 배열 선언

	for (int i = 0; i < realLength; i++) //기존 데이터 복사
	{
		newarr[i] = arr[i];
	}
	
	if (capacity <= realLength) //새로 할당해 준 capacity가 데이터 개수보다 작거나 같을 때
	{
		if (realLength < 5) //최종 데이터 개수가 5개 미만일 때
		{
			arrCapacity = realLength; //최종 데이터 개수만큼의 메모리를 할당
			
			delete[] arr; //기존 배열 삭제
			arr = new Customer[arrCapacity]; //기존 배열에 최종 데이터 개수만큼 새로 메모리를 할당

			for (int i = 0; i < arrCapacity; i++) //새로 동적 할당한 후 다시 데이터 복사
			{
				arr[i] = newarr[i];
			}
		}

		else //최종 데이터 개수가 5개 이상일 때
		{
			arrCapacity = 2 * realLength;

			delete[] arr; //기존 배열 삭제
			arr = new Customer[arrCapacity]; //기존 배열에 최종 데이터 개수의 2배만큼 새로 메모리를 할당

			for (int i = 0; i < realLength; i++) //기존 배열 내의 데이터 복사
			{
				arr[i] = newarr[i];
			}
		}
	}

	else //새로 할당해 준 capacity가 넉넉할 때
	{
		if (arrCapacity) //배열에 들어있는 원소가 있을 때
		{
			arrCapacity = capacity; //할당된 메모리 크기 업데이트

			delete[] arr; //기존 배열 삭제
			arr = new Customer[arrCapacity]; //기존 배열에 capacity만큼 새로 메모리를 할당
		}

		else //배열에 들어있는 원소가 있을 때
		{
			arrCapacity = capacity; //할당된 메모리 크기 업데이트

			arr = new Customer[arrCapacity]; //기존 배열에 capacity만큼 새로 메모리를 할당
		}

		for (int i = 0; i < realLength; i++) //메모리 복사 (최종 데이터 개수는 일정하게 유지됨)
		{
			arr[i] = newarr[i];
		}
	}
}

void Vector_Customer::resize(int size)
{
	Customer* newarr = new Customer[realLength]; //데이터 복사용 배열 선언

	for (int i = 0; i < realLength; i++) //기존 배열 내의 데이터 복사
	{
		newarr[i] = arr[i];
	}
	
	if (size <= arrCapacity) //새로 할당하려는 size가 더 작거나 같은 경우
	{
		if (realLength == 0) //데이터가 안 들어있었을 경우
		{
			arrCapacity = size; //할당된 메모리 크기 업데이트

			arr = new Customer[size]; //기존 배열에 size만큼 새로 메모리를 할당
		}
		
		else
		{
			arrCapacity = size; //할당된 메모리 크기 업데이트

			delete[] arr; //기존 배열 삭제
			arr = new Customer[size]; //기존 배열에 size만큼 새로 메모리를 할당

			realLength = size; //최종 데이터 개수 업데이트

			for (int i = 0; i < size; i++) //size까지만 기존에 존재한 데이터 복사
			{
				arr[i] = newarr[i];
			}
		}
	}

	else //새로 할당하려는 메모리가 더 클 때
	{
		arrCapacity = size;

		if (arr != NULL)
		{
			delete[] arr;
		}

		arr = new Customer[size];

		for (int i = 0; i < realLength; i++)
		{
			arr[i] = newarr[i];
		}
	}
}

void Vector_Customer::push_back(const Customer& value)
{
	realLength++; //최종 데이터 개수 업데이트

	if (realLength >= arrCapacity) //데이터 추가 시 할당된 데이터 크기를 초과하는 경우
	{
		Customer* newarr = new Customer[realLength]; //데이터 복사용 배열 선언

		for (int i = 0; i < realLength; i++) //맨 마지막에 새로운 원소 추가
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
		
		if (realLength < 5) //최종 데이터 개수가 5 미만일 때
		{
			arrCapacity = realLength;

			delete[] arr; //기존 배열 삭제
			arr = new Customer[arrCapacity]; //기존 배열에 최종 데이터 개수만큼의 메모리를 새로 할당

			for (int i = 0; i < arrCapacity; i++) //데이터 복사
			{
				arr[i] = newarr[i];
			}
		}

		else //최종 데이터 개수가 5 이상일 때
		{
			arrCapacity = realLength * 2;

			delete[] arr; //기존 배열 삭제
			arr = new Customer[arrCapacity]; //기존 배열에 realLength의 2배만큼의 메모리를 새로 할당

			for (int i = 0; i < realLength; i++) //데이터 복사
			{
					arr[i] = newarr[i];
			}
		}
	}

	else //capacity가 충분할 때
	{
		arr[realLength - 1] = value; //맨 마지막에 새로운 원소 추가
	}
}

void Vector_Customer::pop_back()
{
	realLength--; //최종 데이터 개수 업데이트 (나중에 삽입 시 덮어 씌워짐)
}

void Vector_Customer::insert(iterator position, const Customer& value)
{
	realLength++;

	if (realLength >= arrCapacity) //데이터 추가 시 할당된 데이터 크기를 초과하는 경우
	{
		Customer* newarr = new Customer[realLength]; //데이터 복사용 배열 선언

		for (int i = 0; i < realLength; i++)
		{
			if (&arr[i] < position) //position 전까지는 기존 원소 복사
			{
				newarr[i] = arr[i];
			}

			else if (&arr[i] == position) //position 자리에 새로운 원소 삽입
			{
				newarr[i] = value;
			}

			else //position 뒤의 원소를 하나씩 미루어서 저장
			{
				newarr[i] = arr[i - 1];
			}
		}

		if (realLength < 5) //최종 데이터 개수가 5 미만일 때
		{	
			arrCapacity = realLength;

			if (arr != NULL)
			{
				delete[] arr;
			}

			arr = new Customer[arrCapacity]; //기존 배열에 최종 데이터 개수만큼의 메모리를 새로 할당

			for (int i = 0; i < realLength; i++) //데이터 복사
			{
					arr[i] = newarr[i];
			}
		}

		else //최종 데이터 개수가 5 이상일 때
		{
			arrCapacity = realLength * 2;

			if (arr != NULL)
			{
				delete[] arr; //기존 배열 삭제
			}

			arr = new Customer[arrCapacity]; //기존 배열에 최종 데이터 개수의 2배만큼의 메모리를 새로 할당

			for (int i = 0; i < realLength; i++) //데이터 복사
			{
					arr[i] = newarr[i];
			}
		}
	}

	else //capacity가 충분할 때
	{
		Customer* newarr2 = new Customer[realLength]; //position 뒤쪽 원소를 저장해줄 배열

		int ind = 0; //position의 index를 저장할 변수

		for (int i = 0; i < realLength; i++)
		{
			if (&arr[i] < position)
				continue;

			else //postion 뒤쪽의 원소를 복사
			{
				if (&arr[i] == position) //positon의 index 저장
				{
					ind = i;
				}

				newarr2[i] = arr[i];
			}
		}

		for (int i = 0; i < realLength; i++)
		{
			if (i < ind) //poistion 이전의 원소는 건드리지 않음
				continue;

			else if (i == ind) //position에 새로운 원소 삽입
			{
				arr[i] = value;
			}

			else //postion 뒤의 원소는 하나씩 미루어서 삽입
			{
				arr[i] = newarr2[ind];
				ind++;
			}
		}
	}
}

void Vector_Customer::insert(iterator position, const Customer* first, const Customer* last)
{
	int arrSize = 0; //삽입할 배열의 크기 저장용 변수
	int ind = 0; //배열 인덱스 표시용 변수

	while (1) //삽입할 배열의 크기 알아내기
	{
		if (first + ind == last)
			break;

		arrSize++; //삽입할 배열의 크기 업데이트
		ind++; //인덱스 업데이트
	}

	realLength += arrSize;
	ind = 0; //변수 재활용을 위해 초기화

	Customer* newarr = new Customer[realLength]; //데이터 복사용 배열 선언

	for (int i = 0; i < realLength; i++)
	{
		if (&arr[i] < position) //position 전까지는 기존 데이터 복사
		{
			newarr[i] = arr[i];
		}

		else if (&arr[i] >= position && &arr[i] < position + arrSize) //새로운 배열 삽입
		{
			newarr[i] = *(first + ind);
			ind++;
		}

		else
		{
			newarr[i] = arr[i - ind];
		}
	}

	if (realLength >= arrCapacity)//최종 데이터 개수가 할당 메모리보다 클 때
	{
		if (realLength < 5) //최종 데이터 개수가 5 미만일 때
		{
			arrCapacity = realLength;

			if (arr != NULL)
			{
				delete[] arr; //기존 배열 삭제
			}

			arr = new Customer[arrCapacity]; //배열에 최종 데이터 개수만큼 메모리를 새로 할당

			for (int i = 0; i < arrCapacity; i++) //새로운 원소를 넣은 데이터를 복사
			{
				arr[i] = newarr[i];
			}
		}

		else //최종 데이터 개수가 5 이상일 때
		{
			arrCapacity = realLength * 2;

			if (arr != NULL)
			{
				delete[] arr; //기존 배열 삭제
			}

			arr = new Customer[arrCapacity]; //배열에 최종 데이터 개수 * 2만큼 메모리를 새로 할당

			for (int i = 0; i < realLength; i++) //새로운 원소를 넣은 데이터를 복사
			{
				arr[i] = newarr[i];
			}
		}
	}

	else //메모리에 여유가 있을 때
	{
		for (int i = 0; i < realLength; i++)
		{
			arr[i] = newarr[i];
		}
	}
}

void Vector_Customer::erase(iterator position)
{
	for (int i = 0; i < arrCapacity; i++)
	{
		if (&arr[i] < position) //삭제해야 하는 위치 전까지는 skip
			continue;

		else if (&arr[i] >= position && i < realLength - 1) //position부터 그 뒤의 원소들을 한 자리씩 당겨서 저장
		{
			arr[i] = arr[i + 1];
		}

		else //여유 공간은 skip
			break;
	}

	realLength--; //최종 데이터 개수 업데이트
}

void Vector_Customer::clear()
{
	delete[] arr; //배열 할당 메모리 삭제
	arrCapacity = 0; //capacity 삭제
	realLength = 0; //데이터 개수 삭제
}

Customer& Vector_Customer::operator[](int index)
{
	return arr[index];
}

const Customer& Vector_Customer::operator[](int index) const
{
	const Customer& i = arr[index];

	return i;
}

Vector_Customer& Vector_Customer::operator=(const Vector_Customer& v)
{
	arrCapacity = v.arrCapacity;
	realLength = v.realLength;

	arr = new Customer[arrCapacity];

	for (int i = 0; i < realLength; i++)
	{
		arr[i] = v.arr[i];
	}

	return *this;
}