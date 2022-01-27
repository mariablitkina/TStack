#pragma once
// Класс двойной стек!!
template<class T>
class TDStack
{
private:
	T* mas;			// массив
	int size;		// размер массива
	int top1;		// вершина первого стека
	int top2;		// вершина второго стека

public:

	TDStack(int _size = 10);						// конструктор
	~TDStack() { delete[] mas; }					// деструктор
	TDStack(const TDStack& s);					// конструктор копирования
	TDStack<T>& operator=(const TDStack<T>& s);	// оператор присваивания
	
	bool Empty1() { return top1 == -1; }			// проверка на пустоту 1 стека
	bool Empty2() { return top2 == size; }			// проверка на пустоту второго стека
	bool Full() { return top1 == top2 - 1; }		// проверка на полноту

	void Push1(T elem);							// положить элемент в 1 стек
	void Push2(T elem);							// положить элемент во 2 стек
	T Pop1();									// взять элемент из 1 стека
	T Pop2();									// взять элемент из 2 стека
	T Top1();									// посмотреть на вершину 1 стека
	T Top2();									// посмотреть на вершину 2 стека
	void Clear() { top1 = -1; top2 = size; }	// очистить массив


};

template<class T>
inline TDStack<T>::TDStack(int _size)
{
	if (_size <= 0) throw "Wrong size";
	size = _size;
	mas = new T[size];
	top1 = -1;			
	top2 = size;		
}

template<class T>
inline TDStack<T>::TDStack(const TDStack<T>& s)
{
	size = s.size;
	mas = new T[size];
	top1 = s.top1;
	top2 = s.top2;

	for (int i = 0; i <= top1; i++)
		mas[i] = s.mas[i];

	for (int i = size - 1; i >= top2; i--)
		mas[i] = s.mas[i];
}

template<class T>
inline TDStack<T>& TDStack<T>::operator=(const TDStack<T>& s)
{
	if (size != s.size)
	{
		delete[] mas;
		size = s.size;
		mas = new T[size];
	}

	top1 = s.top1;
	top2 = s.top2;

	for (int i = 0; i <= top1; i++)
		mas[i] = s.mas[i];

	for (int i = size - 1; i >= top2; i--)
		mas[i] = s.mas[i];

	return *this;
}

template<class T>
inline void TDStack<T>::Push1(T elem)
{
	if (Full()) throw "Stack owerflow";
	mas[++top1] = elem;
}

template<class T>
inline void TDStack<T>::Push2(T elem)
{
	if (Full()) throw "Stack owerflow";
	mas[--top2] = elem;
}

template<class T>
inline T TDStack<T>::Pop1()
{
	if (Empty1()) throw "Stack is empty";
	T temp = mas[top1];
	top1--;
	return temp;
}

template<class T>
inline T TDStack<T>::Pop2()
{
	if (Empty2()) throw "Stack is empty";
	T temp = mas[top2];
	top2++;
	return temp;
}

template<class T>
inline T TDStack<T>::Top1()
{
	if (Empty1()) throw "Stack1 is empty";
	return mas[top1];
}

template<class T>
inline T TDStack<T>::Top2()
{
	if (Empty2()) throw "Stack2 is empty";
	return mas[top2];
}