/**************************************************************************/
/* Author	: Mohamed                                               	  */
/* Date		: 26 July 2021                                 		    	 */
/* Version	: V01.1							  							  */
/**************************************************************************/

// Include the string library
#include <string>
#include <iostream>
#include "staticStackConfig.h"
template <class workingDataType>
class staticStack
{
public:
	staticStack(void)
	{
		top = -1;
	}

	void pushToStack(workingDataType copy_intPushNumToStack)
	{
		if (isFull() == 0)
		{
			top++;
			stack[top] = copy_intPushNumToStack;
		}
		else
		{
			// TODO ERROR
		}
	}
	bool isEmpty(void)
	{
		if (top  == -1)
			return 1;
		return 0;
	}
	bool isFull(void)
	{
		if (top > stackArraySize)
			return 1;
		return 0;
	}
	void popFromStack(void)
	{
		if (getNumberOfElement() == 0) {//TODO ERROR}
		else
		{
			top--;
		}

	}
	int getNumberOfElement(void)
	{
		return (top + 1);
	}
	workingDataType getTopOfStack(void)
	{
		if (getNumberOfElement() > 0)
		{
			return stack[top];
		}
		else
		{
			// TODO ERROR
		}
		return 0;
	}


private:
	int top; 
	workingDataType stack[stackArraySize];
};

