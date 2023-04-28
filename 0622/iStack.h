#ifndef iStack_H
#define iStack_H

#include "iList.h" 

class iStack : public iList
{
public:
	void push(const int& data)
	{
        iList::insertAtFront(data);
    }

    bool pop(int& data)
	{
        return iList::removeFromFront(data);
    }

    bool isStackEmpty() const
	{
        return iList::isEmpty();
    }
	
    void printStack() const
	{
        if ( iList::isEmpty())
		{
            cout << "The stack is empty\n";
            return;
        }
        else
		{
        cout << "The stack is: ";
        iList::print();
        cout << "\n";
    	}
	}
};

#endif
