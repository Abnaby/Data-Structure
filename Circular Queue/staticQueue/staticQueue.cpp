/**************************************************************************/
/* Author	: Mohamed                                               	  */
/* Date		: 9 Aug 2021                                 		    	 */
/* Version	: V1							  							  */
/**************************************************************************/
#include "staticQueue_cfg.h"
#include <iostream>
template <class workingDataType> 
class Queue
{
public:
	Queue()
	{
		front = 0;
		rear = -1;
		size = 0;
	}
	void enQueue(workingDataType copy_elemnetBeEnQueue)
	{
		if (isFull())
		{
			//<!TODO ERROR QUEUE IS FULL 
		}
		else
		{
			rear = (++rear) % queueMaxSize;
			queueArr[rear] = copy_elemnetBeEnQueue;
			size++; 
		}	
	}
	bool isFull(void)
	{
		return (size == queueMaxSize);
	}
	bool isEmpty(void)
	{
		return (size == 0); 
	}
	void deQueue(void)
	{
		if (isEmpty())
		{
			//<TODO ERROR> QUEUE IS EMPTY NOTHING TO DEQUEUE
		}
		else
		{
			front = (++front) % queueMaxSize;
			size--;
		}
	}
	void deQueue(workingDataType *getElement)
	{
		if (isEmpty())
		{
			//<TODO ERROR> QUEUE IS EMPTY NOTHING TO DEQUEUE
		}
		else
		{
			*getElement = queueArr[front];
			front = (++front) % queueMaxSize;
			size--;
		}
	}
	int getNumberOfElement(void)
	{
		if (!isEmpty())
		{
			return size;
		}	
		else
		{
			//<TODO ERROR> QUEUE IS EMPTY NOTHING TO RETURN
		}
		return -1; 
	}
	void getFrontElement(workingDataType* element)
	{
		if (isEmpty())
		{
			//<TODO ERROR> QUEUE IS EMPTY NOTHING TO DEQUEUE
		}
		else
		{
			*element = queueArr[front];
		}
	}
	void traverseQueue(void (*copy_pointerToFunc) (workingDataType element))
	{
		if (!isEmpty())
		{
			for (int i = front; i != rear  ; i = (i + 1) % queueMaxSize)
			{
				(*copy_pointerToFunc)(queueArr[front]);
				front = (++front) % queueMaxSize;
			}
			(*copy_pointerToFunc)(queueArr[rear]);
		}
		else
		{
			//<TODO ERROR> QUEUE IS EMPTY NOTHING TO PUSH
		}

	
	}
	void clearQueue(void)
	{
		front = 0;
		rear = -1;
		size = 0;
	}
private:
	int front; 
	int rear; 
	int size; 
	workingDataType queueArr[queueMaxSize]; 
};
