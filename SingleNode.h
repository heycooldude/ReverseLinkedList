#pragma once
#include "Interfaces01.h"
class SingleNode:public ISingleNode
{

public:
	SingleNode();
	~SingleNode();
	void setValue(int value);
	int getValue();
	ISingleNode * getNext();
	void setNext(ISingleNode * next);
private:
	int key;
	ISingleNode * node=NULL;
};

