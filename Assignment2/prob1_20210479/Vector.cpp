/* 객체지향 프로그래밍 Assignment 2 Prob1_20210479 이주현*/

#include "Vector.h"
#include <cstdio>

using namespace std;

Vector::Vector() { } //class 내에서 멤버 변수 선언 시 초기화하였음

Vector::Vector(int size)
{
	arrCapacity = size; //할당된 메모리 사이즈 업데이트, 최종 데이터 개수는 0으로 유지됨
	arr = new float[size]{0, }; //size만큼 메모리를 동적 할당, 모든 원소 0으로 초기화
}

Vector::Vector(int size, const float& init)
{
	arrCapacity = size; //할당된 메모리 사이즈 업데이트
	realLength = size; //모든 원소가 init으로 초기화되므로 size == length

	arr = new float[size]; //size만큼 메모리를 동적 할당

	for (int i = 0; i < size; i++) //배열의 모든 원소 init으로 초기화
	{
		arr[i] = init;
	}
}

Vector::Vector(int size, const float* init)
{
	arrCapacity = size; //할당된 메모리 사이즈 업데이트

	for (int i = 0; i < size; i++)
	{
		if (*(init + i) == '\0')
			break;

		realLength++;
	}

	arr = new float[size]; //size만큼 메모리를 동적 할당
	
	for (int i = 0; i < size; i++)
	{
		if (i < realLength) //init 배열의 원소를 모두 입력
		{
			arr[i] = init[i];
		}

		else //만약 size가 realLength보다 클 경우 나머지 원소들은 0으로 초기화
		{
			arr[i] = 0;
		}
	}
}

Vector::Vector(const Vector& v)
{
	arrCapacity = v.arrCapacity; //할당된 메모리 사이즈 복사
	realLength = v.realLength; //최종 데이터 개수 복사

	arr = new float[arrCapacity]; //v의 할당된 메모리 크기만큼의 메모리를 할당
	
	for (int i = 0; i < arrCapacity; i++) //v의 모든 원소 복사
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
	return arrCapacity; //할당된 메모리 사이즈 반환
}

int Vector::size() const
{
	return realLength; //최종 데이터 개수 반환
}

Vector::iterator Vector::begin()
{
	iterator firstAdd = &arr[0]; //데이터 배열의 맨 처음 주소 대입

	return firstAdd;
}

Vector::const_iterator Vector::begin() const
{
	const_iterator firstAdd = &arr[0]; //데이터 배열의 맨 처음 주소 대입 (const ver)

	return firstAdd;
}

Vector::iterator Vector::end()
{
	iterator lastAdd = &arr[realLength]; //데이터 배열의 맨 마지막 주소 다음 것을 대입

	return lastAdd;
}

Vector::const_iterator Vector::end() const
{
	const_iterator lastAdd = &arr[realLength]; //데이터 배열의 맨 마지막 주소 다음 것을 대입 (const ver)

	return lastAdd;
}

float& Vector::front()
{
	return arr[0]; //맨 앞 데이터 반환
}

const float& Vector::front() const
{
	const float& front = arr[0]; //arr[0]의 값을 대입한 const reference 변수 선언 

	return front;
}

float& Vector::back()
{
	return arr[realLength - 1];
}

const float& Vector::back() const
{
	const float& last = arr[realLength - 1]; //arr[realLength - 1]의 값을 대입한 const reference 변수 선언

	return last;
}

void Vector::allocate(int capacity)
{
	if (capacity <= realLength) //새로 할당해 준 capacity가 데이터 개수보다 작거나 같을 때
	{
		if (realLength < 5) //최종 데이터 개수가 5개 미만일 때
		{
			arrCapacity = realLength; //최종 데이터 개수만큼의 메모리를 할당
			float* newarr = new float[arrCapacity]; //데이터 복사용 배열 선언

			for (int i = 0; i < arrCapacity; i++) //기존 배열 내의 데이터 복사
			{
				newarr[i] = arr[i];
			}
			
			delete[] arr; //기존 배열 삭제
			arr = new float[arrCapacity]; //기존 배열에 최종 데이터 개수만큼 새로 메모리를 할당
			
			for (int i = 0; i < arrCapacity; i++) //새로 동적 할당한 후 다시 데이터 복사
			{
				arr[i] = newarr[i];
			}
		}

		else //최종 데이터 개수가 5개 이상일 때
		{
			float* newarr2 = new float[realLength]; //데이터 복사용 배열 선언

			for (int i = 0; i < realLength; i++) //기존 배열 내의 데이터 복사
			{
				newarr2[i] = arr[i];
			}

			arrCapacity = 2 * realLength;

			delete[] arr; //기존 배열 삭제
			arr = new float[arrCapacity]; //기존 배열에 최종 데이터 개수의 2배만큼 새로 메모리를 할당

			for (int i = 0; i < arrCapacity; i++)
			{
				if (i < realLength) //기존에 존재한 데이터 복사
				{
					arr[i] = newarr2[i];
				}

				else //데이터가 존재하지 않는 여유 공간은 0으로 초기화
				{
					arr[i] = 0;
				}
			}
		}	
	}

	else //새로 할당해 준 capacity가 넉넉할 때
	{
		float* newarr3 = new float[realLength]; //데이터 복사용 배열 선언

		for (int i = 0; i < realLength; i++) //기존 배열 내의 데이터 복사
		{
			newarr3[i] = arr[i];
		}

		if (arrCapacity) //배열에 들어있는 원소가 있을 때
		{
			arrCapacity = capacity;

			delete[] arr; //기존 배열 삭제
			arr = new float[arrCapacity]; //기존 배열에 capacity만큼 새로 메모리를 할당
		}

		else //배열에 들어있는 원소가 있을 때
		{
			arrCapacity = capacity;
			arr = new float[arrCapacity]; //기존 배열에 capacity만큼 새로 메모리를 할당
		}
		

		for (int i = 0; i < arrCapacity; i++)
		{
			if (i < realLength) //기존에 존재한 데이터 복사
			{
				arr[i] = newarr3[i];
			}

			else //데이터가 존재하지 않는 여유 공간은 0으로 초기화
			{
				arr[i] = 0;
			}
		}
	}
}

void Vector::resize(int size)
{
	if (size <= arrCapacity) //새로 할당하려는 size가 더 작거나 같은 경우
	{
		float* newarr = new float[size]; //데이터 복사용 배열 선언

		for (int i = 0; i < size; i++) //기존 배열 내의 데이터 중 size 개수까지만을 복사
		{
			newarr[i] = arr[i];
		}

		arrCapacity = size;

		delete[] arr; //기존 배열 삭제
		arr = new float[size]; //기존 배열에 size만큼 새로 메모리를 할당

		for (int i = 0; i < size; i++) //size까지만 기존에 존재한 데이터 복사
		{
			arr[i] = newarr[i];
		}

		realLength = size; //최종 데이터 개수 업데이트
	}
	
	else //새로 할당하려는 메모리가 더 클 때
	{
		float* newarr2 = new float[realLength]; //데이터 복사용 배열 선언

		for (int i = 0; i < realLength; i++) //기존 배열 내의 데이터 복사
		{
			newarr2[i] = arr[i];
		}

		arrCapacity = size;

		delete[] arr;
		arr = new float[arrCapacity];

		for (int i = 0; i < size; i++)
		{
			if (i < realLength) //기존의 실제 데이터 복사
			{
				arr[i] = newarr2[i];
			}

			else //여유 공간은 0으로 초기화
			{
				arr[i] = 0;
			}
		}
	}
}

void Vector::push_back(const float& value)
{
	realLength++; //최종 데이터 개수 업데이트

	if (realLength >= arrCapacity) //데이터 추가 시 할당된 데이터 크기를 초과하는 경우
	{
		if (realLength < 5) //최종 데이터 개수가 5 미만일 때
		{
			float* newarr = new float[realLength]; //데이터 복사용 배열 선언

			for (int i = 0; i < realLength; i++)
			{
				if (i == realLength - 1) //맨 마지막에 새로운 원소 추가
				{
					newarr[i] = value;
				}

				else //나머지 기존에 존재한 원소 복사
				{
					newarr[i] = arr[i];
				}
			}

			arrCapacity = realLength;

			delete[] arr; //기존 배열 삭제
			arr = new float[arrCapacity]; //기존 배열에 최종 데이터 개수만큼의 메모리를 새로 할당

			for (int i = 0; i < arrCapacity; i++)
			{
				if (i < realLength) //기존의 데이터 + 새로운 원소 1개 복사
				{
					arr[i] = newarr[i];
				}

				else //나머지 여유 공간에는 0을 저장
				{
					arr[i] = 0;
				}
			}
		}
		
		else //최종 데이터 개수가 5 이상일 때
		{
			float* newarr2 = new float[realLength]; //데이터 복사용 배열 선언

			for (int i = 0; i < realLength; i++)
			{
				if (i == realLength - 1) //맨 마지막에 새로운 원소 추가
				{
					newarr2[i] = value;
				}

				else //나머지 기존에 존재한 원소 복사
				{
					newarr2[i] = arr[i];
				}
			}

			arrCapacity = realLength * 2;

			delete[] arr; //기존 배열 삭제
			arr = new float[arrCapacity]; //기존 배열에 realLength의 2배만큼의 메모리를 새로 할당

			for (int i = 0; i < arrCapacity; i++)
			{
				if (i < realLength) //기존의 데이터 + 새로운 원소 1개 복사
				{
					arr[i] = newarr2[i];
				}

				else //나머지 여유 공간에는 0을 저장
				{
					arr[i] = 0;
				}
			}
		}
	}

	else //capacity가 충분할 때
	{
		arr[realLength - 1] = value; //맨 마지막에 새로운 원소 추가
	}
}

void Vector::pop_back()
{
	arr[realLength - 1] = NULL; //실질적 데이터를 갖는 맨 뒤의 원소 제거

	realLength--; //최종 데이터 개수 업데이트
}

void Vector::insert(iterator position, const float& value)
{
	realLength++;

	if (realLength >= arrCapacity) //데이터 추가 시 할당된 데이터 크기를 초과하는 경우
	{
		if (realLength < 5) //최종 데이터 개수가 5 미만일 때
		{
			float* newarr = new float[realLength]; //데이터 복사용 배열 선언

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

			arrCapacity = realLength;

			delete[] arr; //기존 배열 삭제
			arr = new float[arrCapacity]; //기존 배열에 최종 데이터 개수만큼의 메모리를 새로 할당

			for (int i = 0; i < arrCapacity; i++)
			{
				if (i < realLength) //기존의 데이터 + 새로운 원소 1개 복사
				{
					arr[i] = newarr[i];
				}

				else //나머지 여유 공간에는 0을 저장
				{
					arr[i] = 0;
				}
			}
		}

		else //최종 데이터 개수가 5 이상일 때
		{
			float* newarr2 = new float[realLength]; //데이터 복사용 배열 선언

			for (int i = 0; i <= realLength; i++)
			{
				if (&arr[i] < position) //position 전까지는 기존 원소 복사
				{
					newarr2[i] = arr[i];
				}

				else if (&arr[i] == position) //position 자리에 새로운 원소 삽입
				{
					newarr2[i] = value;
				}

				else //position 뒤의 원소를 하나씩 미루어서 저장
				{
					newarr2[i] = arr[i - 1];
				}
			}

			arrCapacity = realLength * 2;

			delete[] arr; //기존 배열 삭제
			arr = new float[arrCapacity]; //기존 배열에 최종 데이터 개수의 2배만큼의 메모리를 새로 할당

			for (int i = 0; i < arrCapacity; i++)
			{
				if (i < realLength) //기존의 데이터 + 새로운 원소 1개 복사
				{
					arr[i] = newarr2[i];
				}

				else //나머지 여유 공간에는 0을 저장
				{
					arr[i] = 0;
				}
			}
		}
	}

	else //capacity가 충분할 때
	{
		float* newarr3 = new float[realLength]; //position 뒤쪽 원소를 저장해줄 배열

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

				newarr3[i] = arr[i];
			}
		}

		for (int i = 0; i < arrCapacity; i++)
		{
			if (i < ind) //poistion 이전의 원소는 건드리지 않음
				continue;

			else if (i == ind) //position에 새로운 원소 삽입
			{
				arr[i] = value;
			}

			else if (i > ind && i < realLength)//postion 뒤의 원소는 하나씩 미루어서 삽입
			{
				arr[i] = newarr3[ind];
				ind++;
			}

			else //여유 공간은 0으로 초기화
			{
				arr[i] = 0;
			}
		}
	}
}

void Vector::insert(iterator position, const float* first, const float* last)
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

	float* newarr = new float[realLength]; //데이터 복사용 배열 선언

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

			delete[] arr; //기존 배열 삭제
			arr = new float[arrCapacity]; //배열에 최종 데이터 개수만큼 메모리를 새로 할당

			for (int i = 0; i < arrCapacity; i++) //새로운 원소를 넣은 데이터를 복사
			{
				arr[i] = newarr[i];
			}
		}

		else //최종 데이터 개수가 5 이상일 때
		{
			arrCapacity = realLength * 2;

			delete[] arr; //기존 배열 삭제
			arr = new float[arrCapacity]; //배열에 최종 데이터 개수 * 2만큼 메모리를 새로 할당

			for (int i = 0; i < arrCapacity; i++) //새로운 원소를 넣은 데이터를 복사
			{
				if (i < realLength) //데이터가 들어있는 부분 복사
				{
					arr[i] = newarr[i];
				}

				else //여유 공간은 0으로 초기화
				{
					arr[i] = 0;
				}
			}
		}
	}

	else //메모리에 여유가 있을 때
	{
		for (int i = 0; i < arrCapacity; i++)
		{
			if (i < realLength) //데이터가 들어있는 부분 복사
			{
				arr[i] = newarr[i];
			}

			else //여유 공간은 0으로 초기화
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
		if (&arr[i] < position) //삭제해야 하는 위치 전까지는 skip
			continue;

		else if (&arr[i] >= position && i < realLength - 1) //position부터 그 뒤의 원소들을 한 자리씩 당겨서 저장
		{
			arr[i] = arr[i + 1];
		}

		else //여유 공간은 0으로 초기화
		{
			arr[i] = 0;
		}
	}

	realLength--; //최종 데이터 개수 업데이트
}

void Vector::clear()
{
	delete[] arr; //배열 할당 메모리 삭제
	arrCapacity = 0; //capacity 삭제
	realLength = 0; //데이터 개수 삭제
}

float& Vector::operator[](int index)
{
	return arr[index];
}

const float& Vector::operator[](int index) const
{
	const float& i = arr[index]; //리턴 형식에 맞는 변수 선언

	return i;
}

Vector& Vector::operator=(const Vector& v)
{
	arrCapacity = v.arrCapacity;
	realLength = v.realLength;

	arr = new float[arrCapacity]; //배열 복사를 위해 필요한 메모리만큼 동적 할당

	for (int i = 0; i < arrCapacity; i++) //배열 내 데이터 복사
	{
		arr[i] = v.arr[i];
	}

	return *this;
}