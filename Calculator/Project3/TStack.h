#pragma once

#include <iostream>
#include<string>
using namespace std;

template <class T>
class TStack
{
	T* mas;
	int size;
	int pos;
public:
	TStack(int _size = 10)
	{
		if (_size <= 0)
			throw _size;
		size = _size;
		mas = new T[size];
		pos = -1;
	};
	~TStack()
	{
		delete[] mas;
	};
	TStack(const TStack& s)
	{
		size = s.size;
		pos = s.pos;
		mas = new T[size];
		for (int i = 0; i <= pos; i++)
		{
			mas[i] = s.mas[i];
		}
	};
	// �������� �� ������� �����
	bool empty()
	{
		if (pos == -1)
			return true;
		else
			return false;
	}
	// �������� �� �������
	bool full()
	{
		if (pos == size-1)
			return true;
		else
			return false;
	}
	//������������
	TStack& operator = (const TStack& s)
	{
		if (size != s.size)
		{
			size = s.size;
			delete[] mas;
			mas = new T[size];
		};
		pos = s.pos;
		for (int i = 0; i < pos; i++)
		{
			mas[i] = s.mas[i];
		}
		return *this;
	}

// �������� ������� 
	void push(T elem)
	{
		//���������� ��.�� ������� � �������
		if (full())
			throw "Stack is full";
		pos++;
		mas[pos] = elem;
	};
	T pop()
	{
		if (empty())
			throw "Stack is empty";
		T elem;
		elem = mas[pos];
		pos--;
		return elem;
	};
	T top()
	{
		if (empty())
			throw "Stack is empty";
		return mas[pos];
	};
	void Clear() 	//���������� ������� � ������� �����
	{
		pos = -1;
	};
	friend ostream& operator<<(ostream& out, const TStack& v)
	{
		for (int i = 0; i <= v.pos; i++)
			out << v.mas[i] << ' ';
		return out;
	}

	// ������, ���-�� ����������� = ���-�� �����������
	// ������������� ���������, ���� "(" - ����� � ����, ���� ����� ")" - ������� �� �����
};