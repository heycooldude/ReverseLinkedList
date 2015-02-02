#include "DoubleNode.h"


DoubleNode::DoubleNode()
{
}


DoubleNode::~DoubleNode()
{
}
void DoubleNode::setValue(int value){ key = value; }
int DoubleNode::getValue(){ return key; }
IDoubleNode * DoubleNode::getPrev(){ return t; }
IDoubleNode * DoubleNode::getNext(){ return h; }
void DoubleNode::setPrev(IDoubleNode * prev){  t=prev; }
void DoubleNode::setNext(IDoubleNode * next){ h=next; }