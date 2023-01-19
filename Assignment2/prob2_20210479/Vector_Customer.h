#pragma once

#include "Customer.h"

class Vector_Customer
{
	private:
		Customer* arr = NULL; //배열 저장용 변수
		int arrCapacity = 0; //할당된 데이터 저장용 변수
		int realLength = 0; //실제 데이터 개수 저장용 변수

	public:
		typedef Customer* iterator;
		typedef const Customer* const_iterator;

		Vector_Customer();
		Vector_Customer(int size);
		Vector_Customer(int size, const Customer& init);
		Vector_Customer(int size, const Customer* init);
		Vector_Customer(const Vector_Customer& v);
		~Vector_Customer();

		int capacity() const;
		int size() const;

		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		Customer& front();
		const Customer& front() const;
		Customer& back();
		const Customer& back() const;

		void allocate(int capacity);
		void resize(int size);

		void push_back(const Customer& value);
		void pop_back();
		void insert(iterator position, const Customer& value);
		void insert(iterator position, const Customer* first, const Customer* last);

		void erase(iterator position);
		void clear();

		Customer& operator[](int index);
		const Customer& operator[](int index) const;
		Vector_Customer& operator=(const Vector_Customer& v);
};
