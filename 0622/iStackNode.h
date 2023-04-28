#ifndef iStackNODE_H
#define iStackNODE_H

//template< typename T > class Stack; // forward declaration

class iStackNode
{
    friend class iStack;
public:
    iStackNode(const int& = 0, iStackNode* = 0);
    int getData() const;

    // set point to next stack node
    void setNextPtr(iStackNode* nPtr)
    {
        nextPtr = nPtr;
    } // end function setNextPtr

    // get point to next stack node
    iStackNode* getNextPtr() const
    {
        return nextPtr;
    } // end function getNextPtr

private:
    int data;
    iStackNode* nextPtr;
}; // end class StackNode

// member-function definitions for class StackNode
// constructor
iStackNode::iStackNode(const int& d, iStackNode* ptr)
{
    data = d;
    nextPtr = ptr;
} // end constructor

// get data
int iStackNode::getData() const
{
    return data;
} // end function getData

#endif

