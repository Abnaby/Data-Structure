// staticStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string> 
#include "linkedStack.cpp"
using namespace std;
bool isOperator(char Arthoperator); 
float postfixCalculator(string postFix);
float performOperation(float op1, float op2, char op);
int main()
{
	float ans;
	char exp[1000]; 
	cout << "Enter a Postfix Expression: ( e.g. 4 5 * )\n";
	cin.getline(exp, 1000);
	ans = postfixCalculator(exp); 
	cout << ans; 
}
float postfixCalculator(string postFix)
{
	stack<float> s; 
	float answer = 0; 
	string op1="", op2="";
	float oper1 = 0,oper2 = 0;
	bool opSelction = false; // 0 op1    1 op2
	float tempNumber = 0;  
	for (int i = 0; i < (int)postFix.length(); i++)
	{
		if (postFix[i] >= '0' && postFix[i] <= '9')
		{
			if (opSelction)
			{
				op2 += postFix[i];
			}
			else {
				op1 += postFix[i];
			}
		}
		else if(postFix[i] ==' ')
		{
			// END OF Operator
			if (opSelction)
			{
				tempNumber = stof(op2); 
				s.pushToStack(tempNumber);
				op2 = ""; 
				opSelction = false;
			}
			else {
				tempNumber = stof(op1);
				s.pushToStack(tempNumber);
				op1 = ""; 
				opSelction = true;
			}
		}
		else if(isOperator(postFix[i]))
		{
			if (s.getNumberOfElement() >= 2)
			{
				  s.popFromStack(&oper2);
				  s.popFromStack(&oper1);
				  answer = performOperation(oper1, oper2, postFix[i]);
				  s.pushToStack(answer); 
				 
			}
			else
			{
				// <TODO ERROR> 
			}
			opSelction = true;
			i++;
		}
		else
		{
			// <TODO> ERROR 
		}

	}
	s.popFromStack(&answer);
	return answer;
}

bool isOperator(char Arthoperator)
{

	return (Arthoperator == '+' || Arthoperator == '-' || Arthoperator == '*' || Arthoperator == '/'); 
}

float performOperation(float op1, float op2, char op)
{
	float ans = 0;
	switch (op) {
	case '+':
		ans = op1 + op2;
		break;
	case '-':
		ans = op1 - op2;
		break;
	case '*':
		ans = op1 * op2;
		break;
	case '/':
		ans = op1 / op2;
		break;
	}
	return ans;
}

