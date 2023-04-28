#ifndef cSTACK_H
#define cSTACK_H

#include "cList.h" 


class cStack : public cList
{
public:

    void push(const char& data)
	{
        cList::insertAtFront(data);
    }

    char pop(char& data)
	{
        return cList::removeFromFront(data);
    }

    char stackTop() const
	{
        return !cList::isEmpty() ? cList::firstPtr->getData() : static_cast<char>(0);
    }
	
    bool isStackEmpty() const
	{
        return this->isEmpty();
    }
	
    void printStack() const
	{
        if (this->isEmpty())
		{
            cout << "The stack is empty\n";
            return;
        }
        cout << "The stack is: ";
        this->print();
        cout << "\n";
    }

};

#endif

