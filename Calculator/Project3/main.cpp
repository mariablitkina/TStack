#include <iostream>
#include<string>
#include "TStack.h"
#include "TCalculator.h"
using namespace std;

int main()
{
	TCalc calc;
	string exp;
	
	while (true)
	{
		cout << "Enter expression" << endl;
		getline(cin, exp);
		calc.set_expr(exp);
		cout << "Expression is : " << calc.get_expr() << endl;

		// проверка скобок
		bool braces = calc.check_expr();
		if (braces) {
			cout << "Braces are correct"<< endl;
		}
		else {
			cout << "Braces are incorrect"<<endl;
			continue;
		}
		cout << "Postfix: "<< endl;
		calc.convert_to_postfix();
		cout << calc.get_pstfix() << endl;

		cout << "Result:  ";
		try
		{
			cout << calc.calc() << endl;
		}
		catch (...)
		{
			cout << "Exception" << endl;
		}

		return 0;
	}
	
}