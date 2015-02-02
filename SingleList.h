#pragma once
#include "Interfaces01.h"
class SingleList:public ISingleList
{
public:
	SingleList();
	~SingleList();
	ISingleNode * getHead();
	 void setHead(ISingleNode * head);
	 void addHead(int value) ;
	 void orderSort2();
	 void orderSort3();
	 void sequenceOrderSort();
	 void reverse();
private:
	ISingleNode * h=NULL;
};

