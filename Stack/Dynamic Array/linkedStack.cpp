/**************************************************************************/
/* Author	: Mohamed                                               	  */
/* Date		: 27 July 2021                                 		    	 */
/* Version	: V02							  							  */
/**************************************************************************/
#include <string>
template <class workingDataType>
class stack
{

public:
	stack() {
		top = NULL;
		numberOfNodes = 0;
	}
	~stack()
	{
		delete top;
	}
	void pushToStack(workingDataType copy_PushItemToStack)
	{
		// Create malloc of struct size 
		Node* newItemPtr = new Node;
		//Check process for allocating mem 
		if (newItemPtr != NULL)
		{
			numberOfNodes++;
			//Add Vlaue to stack
			newItemPtr->nodeNumValue = copy_PushItemToStack;
			//Link New Node With Old Node 
			newItemPtr->nextPointer = top;
			// Change Top/Head to newest Node 
			top = newItemPtr;
		}
		else
		{
			// <TODO ERROR> if newItemPtr = NULL cann't allocate memory
		}
	}
	bool isEmpty(void)
	{
		return top == NULL;
	}
	bool isFull(void)
	{
		return 0;
	}
	void popFromStack(void)
	{
		if (!isEmpty())
		{
			// make temp ptr point to last node 
			Node* tempPtr = top;
			// Make TopPtr point to new place
			top = top->nextPointer;
			// Disconnect Between two nodes
			tempPtr = tempPtr->nextPointer = NULL;
			delete tempPtr;
		}
		else
		{
			//<TODO ERROR> stack is empty
		}
	}
	void popFromStack(workingDataType* topOfStack)
	{
		if (!isEmpty())
		{
			// Return Value
			*topOfStack = top->nodeNumValue; 
			// make temp ptr point to last node 
			Node* tempPtr = top;
			// Make TopPtr point to new place
			top = top->nextPointer;
			// Disconnect Between two nodes
			tempPtr = tempPtr->nextPointer = NULL;
			delete tempPtr;
		}
		else
		{
			//<TODO ERROR> stack is empty
		}
	}
	int getNumberOfElement(void)
	{
		return numberOfNodes;
	}
	void getTopOfStack(workingDataType* topOfStack)
	{
		if (!isEmpty())
		{
			*topOfStack =  top->nodeNumValue;
		}
		else
		{
			//<TODO ERROR> stack is empty
		}
	}


private:
	struct Node
	{
		workingDataType nodeNumValue;
		Node* nextPointer;
	};
	// Represent stack pointer
	Node* top;
	int numberOfNodes;
};
