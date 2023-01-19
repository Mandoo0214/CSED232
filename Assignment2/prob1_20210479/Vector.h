/* 객체지향 프로그래밍 Assignment 2 Prob1_20210479 이주현*/

#pragma once
#include <iostream>

using namespace std;

class Vector
{
	private:
		float* arr = NULL; //실제 원소를 저장할 배열
		int arrCapacity = 0; //배열의 최대 길이
		int realLength = 0; //실제 원소가 저장된 길이

	public:
		typedef float* iterator;
		typedef const float* const_iterator;
		
		Vector();
		Vector(int size);
		Vector(int size, const float& init);
		Vector(int size, const float* intit);
		Vector(const Vector& v);
		~Vector();
		int capacity() const;
		int size() const;
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		float& front();
		const float& front() const;
		float& back();
		const float& back() const;
		void allocate(int capacity);
		void resize(int size);
		void push_back(const float& value);
		void pop_back();
		void insert(iterator position, const float& value);
		void insert(iterator position, const float* first, const float* last);
		void erase(iterator position);
		void clear();
		float& operator[](int index);
		const float& operator[](int index) const;
		Vector& operator=(const Vector& v);
};