#ifndef cLIST_H
#define cLIST_H

#include <iostream>
#include "cListNode.h" 
using namespace std;

class cList {
public:
    cList();
    ~cList();
    void insertAtFront(const char&);
    void insertAtBack(const char&);
    bool removeFromFront(char&);
    bool removeFromBack(char&);
    bool isEmpty() const;
	
    void print() const;
protected:
    cListNode* firstPtr;
    cListNode* lastPtr;

    cListNode* getNewNode(const char&);
};


cList::cList() : firstPtr(0), lastPtr(0)
{
    
}

cList::~cList()
{
    if (!isEmpty())
    {
        cout << "Destroying nodes ...\n";

        cListNode* currentPtr = firstPtr;
        cListNode* tempPtr;

        while (currentPtr != 0) 
        {
            tempPtr = currentPtr;
            cout << tempPtr->data << '\n';
            currentPtr = currentPtr->nextPtr;
            delete tempPtr;
        }
    }

    cout << "All nodes destroyed\n\n";
}

void cList::insertAtFront(const char& value)
{
    cListNode* newPtr = getNewNode(value);

    if (isEmpty())
        firstPtr = lastPtr = newPtr;
    else
    {
        newPtr->nextPtr = firstPtr;
        firstPtr = newPtr;
    }
}

void cList::insertAtBack(const char& value)
{
    cListNode* newPtr = getNewNode(value);

    if (isEmpty())
        firstPtr = lastPtr = newPtr;
    else
    {
        lastPtr->nextPtr = newPtr;
        lastPtr = newPtr;
    }
}

bool cList::removeFromFront(char& value)
{
    if (isEmpty())
        return false;
    else
    {
        cListNode* tempPtr = firstPtr;

        if (firstPtr == lastPtr)
            firstPtr = lastPtr = 0;
        else
            firstPtr = firstPtr->nextPtr;

        value = tempPtr->data;
        delete tempPtr;
        return true;
    }
}

bool cList::removeFromBack(char& value)
{
    if (isEmpty())
        return false; 
    else
    {
        cListNode* tempPtr = lastPtr;

        if (firstPtr == lastPtr)
            firstPtr = lastPtr = 0;
        else
        {
            cListNode* currentPtr = firstPtr;
			
            while (currentPtr->nextPtr != lastPtr)
                currentPtr = currentPtr->nextPtr;

            lastPtr = currentPtr;
            currentPtr->nextPtr = 0;
        }

        value = tempPtr->data;
        delete tempPtr;
        return true;
    }
}

bool cList::isEmpty() const
{
    return firstPtr == 0;
}

cListNode* cList::getNewNode(const char& value)
{
    return new cListNode(value);
}

void cList::print() const
{
    if (isEmpty())
    {
        cout << "The list is empty\n\n";
        return;
    }

    cListNode* currentPtr = firstPtr;

    //cout << "The list is: ";

    while (currentPtr != 0)
    {
        cout << currentPtr->data << ' ';
        currentPtr = currentPtr->nextPtr;
    }
    
	//cout << "\n";
}

#endif

