#include "DoubleList.h"
#include "DoubleNode.h"

DoubleList::DoubleList()
{
}


DoubleList::~DoubleList()
{
}
IDoubleNode * DoubleList::getHead(){ return h; }
IDoubleNode * DoubleList::getTail(){ return t; }
void DoubleList::setHead(IDoubleNode * head){
	h=head;
}
void DoubleList::setTail(IDoubleNode * tail){
	t = tail;
}
void DoubleList::addSorted(int value){ 
	IDoubleNode * node = new DoubleNode;
	IDoubleNode * tmp = NULL;
	tmp = h;
	IDoubleNode * cur = NULL;
	cur = h;
	node->setValue(value);
	if (h == NULL && t==NULL){
		h = node;
		t = node;
		node->setPrev(NULL);
		node->setNext(NULL);
		return;
	}
	else if (h->getValue() > value){
		node->setNext(h);
		h->setPrev(node);
		h = node;
	}
	else if (t->getValue() < value){
		t->setNext(node);
		node->setPrev(t);
		t = node;
	}
	else{
		while (cur != NULL && value > cur->getValue()){
			tmp = cur;
			cur = cur->getNext();
		}
		node->setNext(cur);
		cur->setPrev(node);
		tmp->setNext(node);
		node->setPrev(tmp);
	}
}
	

void DoubleList::orderSort2(){
	IDoubleNode * cur = NULL;
	cur=h->getNext();
	h->setNext(cur->getNext());
	cur->getNext()->setPrev(h);
	h->setPrev(cur);
	cur->setNext(h);
	cur->setPrev(NULL);
	h = cur;
	IDoubleNode * last = NULL;
		last=cur->getNext();
	IDoubleNode * tmp = new DoubleNode();
	cur = last->getNext();
	bool str = true;
	while (cur != NULL)
	{
		if (!str)
		{
			tmp->setNext(cur->getNext());
			if (cur->getNext() != NULL)
			cur->getNext()->setPrev(tmp);
			cur->setNext(tmp);
			tmp->setPrev(cur);
			last->setNext(cur);
			cur->setPrev(last);
			last = tmp;
			t = tmp;
			cur = tmp->getNext();
			str = true;
		}
		else{
			tmp = cur;
			cur = cur->getNext();
			str = false;
		}
	}
}
void DoubleList::orderSort3(){
	IDoubleNode * cur = NULL;
		cur=h;
	IDoubleNode * tmp = NULL;
		tmp=h->getNext();
	IDoubleNode * next = NULL;
		next=tmp->getNext();
	cur->setNext(next->getNext());
	next->getNext()->setPrev(cur);
	next->setNext(tmp);
	next->setPrev(NULL);
	tmp->setPrev(next);
	tmp->setNext(cur);
	cur->setPrev(tmp);
	h = next;
	t = cur;
	IDoubleNode * last = NULL;
	last = cur;
	cur = cur->getNext();
	while (cur != NULL)
	{
		tmp = cur->getNext();
		next = tmp->getNext();
		if (next == NULL)
		{
			last->setNext(tmp);
			tmp->setPrev(last);
			cur->setNext(tmp->getNext());
			//if (tmp->getNext() != NULL)
			//	tmp->getNext()->setPrev(cur);
			
			tmp->setNext(cur);
			cur->setPrev(tmp);
			t = cur;
			return;

		}
		else{
			cur->setNext(next->getNext());
			last->setNext(next);
			if (next->getNext() != NULL){
				next->getNext()->setPrev(cur);
			}
			next->setPrev(last);
			next->setNext(tmp);
			tmp->setPrev(next);
			tmp->setNext(cur);
			cur->setPrev(tmp);
			last = cur;
			t = cur;
			cur = cur->getNext();
			//continue;
		}
	}
}
void DoubleList::sequenceOrderSort(){
	IDoubleNode * cur = NULL;
	cur = h;
	IDoubleNode * tmp = NULL;
	tmp = cur->getNext();
	cur->setNext(tmp->getNext());
//	IDoubleNode * node = NULL;
//	node = tmp->getNext();
//	node->setPrev(cur);
	tmp->getNext()->setPrev(cur);
	tmp->setNext(cur);
	cur->setPrev(tmp);
	tmp->setPrev(NULL);
	h = tmp;
	IDoubleNode * last = NULL;
	
	last = cur;
	//cur = tmp;
	cur = cur->getNext();
	
	tmp = cur;
	IDoubleNode * ptr_HEAD = NULL;
	ptr_HEAD = cur;
	cur = tmp->getNext();
	int i = 1;
	int cntr = 3;
	while (cur != NULL){
		if (i > 0 &&  i<cntr){
			last->setNext(cur);
			tmp->setNext(cur->getNext());
			
			IDoubleNode * cur_NEXT = NULL;
			cur_NEXT = cur->getNext();
			if (cur->getNext() != NULL){
				
				cur_NEXT->setPrev(tmp);
			}
			
			
			cur->setPrev(last);
			cur->setNext(ptr_HEAD);
			ptr_HEAD->setPrev(cur);
			//ptr->setPrev(cur);
			ptr_HEAD = cur;
			//cntr++;
			t = tmp;
			i++;
			
			cur = tmp->getNext();
		}
		else if (i == cntr){
			last = tmp;
			ptr_HEAD = cur;
			tmp = cur;
			t = tmp;
			i = 1;
			cntr++;
			cur = cur->getNext();
		}
	}

}
void DoubleList::reverse(){
	IDoubleNode * cur = NULL;
	IDoubleNode * tmp = NULL;
	tmp = h;
	h = t;
	t = tmp;
	cur = h;
	while (cur!=NULL){
		tmp = cur->getNext();
		cur->setNext(cur->getPrev());
		cur->setPrev(tmp);
		cur = cur->getNext();
	}
}
