// staticStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "linkedStack.cpp"
using namespace std;
bool Balanced_Parentheses(string );
bool charCompare(char, char);
int main()
{
	string str;
	cout << "Enter String: "; 
	cin >> str;
	if (Balanced_Parentheses(str))
		cout << " Balanced";
	else
		cout << "Not Balanced"; 
	
}
bool Balanced_Parentheses(string stringCheck)
{
	stack<char> s;
	int i = 0; 
	while (stringCheck[i] != '\0')
	{
		if (stringCheck[i] == '[' || stringCheck[i] == '(' || stringCheck[i] == '{')
		{
			s.pushToStack(stringCheck[i]); 
		}
		else if (stringCheck[i] == ']' || stringCheck[i] == ')' || stringCheck[i] == '}')
		{
			/* Compere between top of stack and current charchter */
			char topOfStack; 
			s.getTopOfStack(&topOfStack); 
			if (charCompare(topOfStack, stringCheck[i]))
			{
				s.popFromStack();
			}
			else
			{
				return 0; 
			}
		}
		i++; 
	}
	if (s.isEmpty())
		return 1;
	return 0; 
}

bool charCompare(char start, char end)
{
	return ((start == '[' && end == ']') || (start == '{' && end == '}') || (start == '(' && end == ')')); 

}