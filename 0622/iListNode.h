#ifndef iListNODE_H
#define iListNODE_H

class iListNode
{
	friend class iList;
public:
	iListNode(const int&);
	int getData() const;
protected:
	int data;
	iListNode* nextPtr;
};


iListNode::iListNode(const int& info)
: data(info), nextPtr(0)
{
 	
}

int iListNode::getData() const
{
	return data;
}

#endif

