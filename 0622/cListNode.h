#ifndef cLISTNODE_H
#define cLISTNODE_H                         

class cListNode {
	friend class cList;

public:
	cListNode(const char&);
	char getData() const;
protected:
	char data;
	cListNode* nextPtr; 
};

cListNode::cListNode(const char& info)
	: data(info), nextPtr(0)
{
	
}

char cListNode::getData() const
{
	return data;
}

#endif

