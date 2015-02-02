#pragma once
#include"Interfaces01.h"
class DoubleNode:public IDoubleNode
{
public:
	DoubleNode();
	~DoubleNode();
	 void setValue(int value);
	 int getValue();
	 IDoubleNode * getPrev();
	 IDoubleNode * getNext();
	 void setPrev(IDoubleNode * prev);
	 void setNext(IDoubleNode * next);
private:
	int key;
	IDoubleNode * h=NULL;
	IDoubleNode * t=NULL;
};

