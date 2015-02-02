#include "SingleList.h"
#include "SingleNode.h"

SingleList::SingleList()
{
}


SingleList::~SingleList()
{

}

ISingleNode * SingleList::getHead(){ return h; }

void SingleList::setHead(ISingleNode * head){
	h = head;
}
void SingleList::addHead(int value){

	ISingleNode * tmp = new SingleNode();
		if (h == NULL){
			tmp->setValue(value);
			tmp->setNext(NULL);
			h = tmp;
		}
		else{
			tmp->setValue(value);
			tmp->setNext(h);
			h = tmp;
		}

}

void SingleList::orderSort2(){
	ISingleNode * cur = NULL;
	cur = h;
	ISingleNode * tmp = NULL;
	tmp = h;
	ISingleNode * last = new SingleNode();
	cur = cur->getNext();
	tmp->setNext(cur->getNext());
	cur->setNext(tmp);
	h = cur;
	last = tmp;
	cur = tmp->getNext();
	bool str = true;
	while (cur != NULL)
	{
		if (!str)
		{
			tmp->setNext(cur->getNext());
			cur->setNext(tmp);
			last->setNext(cur);
			last = tmp;
			cur = tmp->getNext();
			str = true;
		}
		else
		{
			tmp = cur;
			cur = cur->getNext();
			str = false;

		}
	}
}
void SingleList::orderSort3(){

	ISingleNode * cur = NULL;
	cur = h;
	ISingleNode * tmp = NULL;
	tmp = h->getNext();
	ISingleNode * prev = NULL;
	prev = tmp->getNext();
	cur->setNext(prev->getNext());
	prev->setNext(tmp);
	tmp->setNext(cur);
	h = prev;
	ISingleNode * last = NULL;
	last=cur;
	cur = cur->getNext();
	while (cur != NULL)
	{
		tmp = cur->getNext();
		prev = tmp->getNext();
		if (prev == NULL)
		{
			last->setNext(tmp);
			tmp->setNext(cur);
			return;
		}
		else
		{
			cur->setNext(prev->getNext());
			last->setNext(prev);
			prev->setNext(tmp);
			tmp->setNext(cur);
			last = cur;
			cur = cur->getNext();
			//continue;
		}

	}
}
void SingleList::sequenceOrderSort(){
	//ISingleNode * fwd = NULL;
	ISingleNode * bck = NULL;
	ISingleNode * cur = NULL;
	ISingleNode * last = NULL;
	ISingleNode * tmp = NULL;
	//fwd = h;
	cur = h;
	tmp=cur->getNext();
	cur->setNext(tmp->getNext());
	tmp->setNext(cur);
	h = tmp;
	tmp = cur->getNext();
	last = cur;
	cur = tmp;
	int cntr = 3;
	int i = 1;
	
	tmp = cur;
	bck = cur;
	cur = cur->getNext();
	while (cur != NULL)
	{
		if (i < cntr && i > 0)
		//for ( i = 1; i < cntr;)
		{
			bck->setNext(cur->getNext());
			last->setNext(cur);
			cur->setNext(tmp);
			tmp = cur;
			cur = bck;
			i++;
			cur = cur->getNext();
			
		}
		else if (i == cntr)
		{
			last = bck;
			tmp = cur;
			bck = cur;
			i = 1;
			cntr++;
			cur = cur->getNext();
			
		}
	}
}
void SingleList::reverse(){
	/*ISingleNode * cur = h;
	ISingleNode * prev = NULL;
	ISingleNode * tmp = NULL;
	while (cur != NULL){
		tmp = cur->getNext();
		cur->setNext(prev);
		prev = cur;
		cur = tmp;
	}
	h = prev;*/
	ISingleNode * cur = NULL;
	cur = h;
	ISingleNode * tmp = NULL;
	while (cur->getNext() != NULL)
	{
		tmp = cur->getNext();
		cur->setNext(tmp->getNext());
		tmp->setNext(h);
		h = tmp;
	}
	
}
