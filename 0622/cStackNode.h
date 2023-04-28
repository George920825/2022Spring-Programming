#ifndef cSTACKNODE_H
#define cSTACKNODE_H

//template< typename T > class Stack; // forward declaration

class cStackNode
{
    friend class cStack;
public:
    cStackNode(const char& = 0, cStackNode* = 0);
    char getData() const;

    // set point to next stack node
    void setNextPtr(cStackNode* nPtr)
    {
        nextPtr = nPtr;
    } // end function setNextPtr

    // get point to next stack node
    cStackNode* getNextPtr() const
    {
        return nextPtr;
    } // end function getNextPtr

private:
    char data;
    cStackNode* nextPtr;
}; // end class StackNode

// member-function definitions for class StackNode
// constructor
cStackNode::cStackNode(const char& d, cStackNode* ptr)
{
    data = d;
    nextPtr = ptr;
} // end constructor

// get data
char cStackNode::getData() const
{
    return data;
} // end function getData

#endif
