// staticStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string> 
#include "stackI.cpp"
using namespace std;
bool isOperator(char Arthoperator); 	
string infixToPostfix(string );
int OperatorPeriority(char op);
bool checkOperatorPeriority(char op1, char op2);
int main()
{
	float ans;
	char exp[1000]; 
	cout << "Enter a InFix Expression: ( e.g. 4+3*2 ) \n";
	cin.getline(exp, 1000);
	
	cout << "PostFix Form: " << infixToPostfix(exp);

}


bool isOperator(char Arthoperator)
{

	return (Arthoperator == '+' || Arthoperator == '-' || Arthoperator == '*' || Arthoperator == '/'); 
}

string infixToPostfix(string infix)
{
	stack<char>operators; 
	string postFix;
	char stackOp;
	for (int i = 0; i < infix.length(); i++)
	{
		if ((infix[i] >= '0' && infix[i] <= '9'))
		{
			postFix += infix[i];
		}
		else if (infix[i] == '(')
		{
			operators.pushToStack(infix[i]);
		}
		else if (infix[i] == ')')
		{
			operators.getTopOfStack(&stackOp);
			while (!operators.isEmpty() && stackOp != '(')
			{
				operators.popFromStack(&stackOp);
				postFix += stackOp;
				
				operators.getTopOfStack(&stackOp);	
				postFix += ' ';
			}
			postFix.pop_back(); 
			operators.popFromStack();
		}

		else if (isOperator(infix[i]))
		{
			postFix += ' ';
			if (!operators.isEmpty())
			{
				operators.getTopOfStack(&stackOp); 
				if (checkOperatorPeriority(stackOp, infix[i]))
				{
					operators.popFromStack(&stackOp); 
					operators.pushToStack(infix[i]); 
					postFix += stackOp;
					postFix += ' ';
				}
				else
				{
					
					operators.pushToStack(infix[i]);
				}
			}
			else
			{
				
				operators.pushToStack(infix[i]); 
			}
		}

	}
	while (!operators.isEmpty())
	{
		operators.popFromStack(&stackOp);
		postFix += ' ';
		postFix += stackOp;
		
	}


	return postFix; 
}
int OperatorPeriority(char op)
{
	int weight=-1 ; 
	switch (op)
	{
	case '+' :
	case '-' :
		weight = 1; break; 
	case '*' :
	case '/' :
		weight = 2; break;
	default:
		break;
	}
	return weight; 
}
bool checkOperatorPeriority(char op1, char op2)
{
	int op1Weight = OperatorPeriority(op1);
	int op2Weight = OperatorPeriority(op2);
	return (op1Weight >= op2Weight );
}

