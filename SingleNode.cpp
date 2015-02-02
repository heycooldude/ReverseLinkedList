#include "SingleNode.h"


SingleNode::SingleNode(){}
SingleNode::~SingleNode(){}
void SingleNode::setValue(int value){
	key = value;
}
int SingleNode::getValue(){ return key; }
ISingleNode * SingleNode::getNext(){ return node; }
void SingleNode::setNext(ISingleNode * next){
	node = next;
}
