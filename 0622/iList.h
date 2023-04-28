#ifndef iList_H
#define iList_H

#include <iostream>
#include "iListNode.h"
using namespace std;

class iList {
public:
    iList();
    ~iList();
    void insertAtFront(const int&);
    void insertAtBack(const int&);
    bool removeFromFront(int&);
    bool removeFromBack(int&);
    bool isEmpty() const;
    void print() const;
protected:
    iListNode * firstPtr;
    iListNode * lastPtr;

    iListNode* getNewNode(const int&);
};


iList::iList() : firstPtr(0), lastPtr(0)
{
    
}

iList::~iList()
{
    if (!isEmpty())
    {
        cout << "Destroying nodes ...\n";

        iListNode* currentPtr = firstPtr;
        iListNode* tempPtr;

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

void iList::insertAtFront(const int& value)
{
   iListNode *newPtr = getNewNode( value );

   if ( isEmpty() )
   	  	firstPtr = lastPtr = newPtr;
   else
   {
      	newPtr->nextPtr = firstPtr;
      	firstPtr = newPtr;
   }
}

void iList::insertAtBack(const int& value)
{
    iListNode* newPtr = getNewNode(value);

    if (isEmpty())
        firstPtr = lastPtr = newPtr;
    else
    {
        lastPtr->nextPtr = newPtr;
        lastPtr = newPtr;
    }
}

bool iList::removeFromFront(int& value)
{
  if ( isEmpty() )
      return false;
   else 
   {
      iListNode *tempPtr = firstPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else
         firstPtr = firstPtr->nextPtr;

      value = tempPtr->data;
      delete tempPtr;
      return true;
   }
}

bool iList::removeFromBack(int& value)
{
    if (isEmpty())
        return false;
    else
    {
        iListNode* tempPtr = lastPtr;

        if (firstPtr == lastPtr)
            firstPtr = lastPtr = 0;
        else
        {
            iListNode* currentPtr = firstPtr;
			
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

bool iList::isEmpty() const
{
    return firstPtr == 0;
}

iListNode* iList::getNewNode(const int& value)
{
    return new iListNode(value);
}

void iList::print() const
{
    if (isEmpty())
    {
        cout << "The list is empty\n\n";
        return;
    }

    iListNode* currentPtr = firstPtr;

    //cout << "The list is: ";

    while (currentPtr != 0)
    {
        cout << currentPtr->data << ' ';
        currentPtr = currentPtr->nextPtr;
    }

	//cout << "\n";
}

#endif
