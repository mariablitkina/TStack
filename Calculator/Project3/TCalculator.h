#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include "TStack.h"
using namespace std;

class TCalc {
private:
	std::string expr; // строка, содержащая некрасивое мат. выражение
	std::string pstfix; // строка, переведённая в постфиксную форму
	TStack<char> st_char; // стек, в который записываем числа
	TStack<double> st_d; // стек, в который записываем операции 

	int priority(char operation);
public:
	TCalc(); // Конструктор
	~TCalc(); // Деструктор
	TCalc(const TCalc& other); // Конструктор копирования

	TCalc& operator=(const TCalc& other); // оператор присваивания

	void set_expr(std::string _expr);
	std::string get_expr();
	std::string get_pstfix();
	bool check_expr();// проверить строку
	void convert_to_postfix();// перевести в постфиксную форму
	double calc();// сосчитать
};

int TCalc::priority(char op) { // Функция приоритета операций
	switch (op) {
	case '(': return 0;
	case '+': return 1;
	case '-': return 1;
	case '*': return 2;
	case '/': return 2;
	case '^': return 3;
	}
	return 0;
}

TCalc::TCalc() { // Конструктор
}

TCalc::~TCalc() { // Деструктор
}

TCalc::TCalc(const TCalc& other) { // Конструктор копирования
	expr = other.expr;
	pstfix = other.pstfix;
}

// оператор присваивания

TCalc& TCalc::operator=(const TCalc& other) {
	expr = other.expr;
	pstfix = other.pstfix;
	return *this;
}

void TCalc::set_expr(string _expr) {
	expr = _expr;
}

string TCalc::get_expr() {
	return expr;
}

string TCalc::get_pstfix() {
	return pstfix;
}
// проверка выражения
bool TCalc::check_expr() {
	for (int i = 0; i < expr.length(); i++)
	{
		if (expr[i] == '(') {
			st_char.push(expr[i]);
		}
		else if (expr[i] == ')')
		{
			if (st_char.empty()) {
				return false;
			}
			else {
				st_char.pop();
			}
		}
	}
	return st_char.empty();
};

// перевод в постфиксную запись 
void TCalc::convert_to_postfix() {
	
	string infix = "(" + expr + ")";
	pstfix = "";
	st_char.Clear();

	for (int i = 0; i < infix.size(); i++)
	{
		if (isdigit(infix[i]))
		{
			size_t idx;
			double tmp = stod(&infix[i], &idx);
			ostringstream ss;
			ss << tmp;

			pstfix = pstfix + ss.str();
			pstfix = pstfix + " ";
			i += idx - 1;
		}
		else if (infix[i] == '(')
		{
			st_char.push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			while (st_char.top() != '(')
			{
				pstfix += st_char.pop();
				pstfix += " ";
			}
			st_char.pop();
		}
		else if ((infix[i] == '+') || (infix[i] == '-') || (infix[i] == '*') || (infix[i] == '/') || (infix[i] == '^'))
		{
			while (priority(infix[i]) <= priority(st_char.top()))
			{
				pstfix += st_char.pop();
				pstfix += " ";
			}
			st_char.push(infix[i]);
		}
	}
	if (!pstfix.empty())
		pstfix.pop_back();
}

// Функция, которая всё считает
double TCalc::calc() {
	string infix = "(" + expr + ")";

	st_char.Clear();
	st_d.Clear();

	for (int i = 0; i < infix.length(); i++)
	{
		if (infix[i] == '(')
		{
			st_char.push(infix[i]);
		}
		else if (isdigit(infix[i]))
		{
			size_t idx;
			double tmp = stod(&infix[i], &idx);
			st_d.push(tmp);
			i = i + idx - 1;
		}
		else if ((infix[i] == '+') || (infix[i] == '-') || (infix[i] == '*') || (infix[i] == '/') || (infix[i] == '^'))
		{
			while (priority(infix[i]) <= priority(st_char.top()))
			{
				if (st_d.empty())
					throw "Too much operations";
				double second = st_d.pop();

				if (st_d.empty())
					throw "Too much operations";
				double first = st_d.pop();

				char op = st_char.pop();

				switch (op)
				{
				case '+':
					st_d.push(first + second);
					break;
				case '-':
					st_d.push(first - second);
					break;
				case '*':
					st_d.push(first * second);
					break;
				case '/':
					st_d.push(first / second);
					break;
				case '^':
					st_d.push(pow(first, second));
					break;
				}
			}
			st_char.push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			while (st_char.top() != '(')
			{
				if (st_d.empty()) throw "Too much operations";
				double second = st_d.pop();

				if (st_d.empty()) throw "Too much operations";
				double first = st_d.pop();

				char op = st_char.pop();

				switch (op)
				{
				case '+':
					st_d.push(first + second);
					break;
				case '-':
					st_d.push(first - second);
					break;
				case '*':
					st_d.push(first * second);
					break;
				case '/':
					st_d.push(first / second);
					break;
				case '^':
					st_d.push(pow(first, second));
					break;
				}
			}
			st_char.pop();
		}
	}

	if (st_d.empty()) throw "No operands in the string";
	double result = st_d.pop();

	if (st_d.full()) throw "Too many operands in the string";

	return result;
}