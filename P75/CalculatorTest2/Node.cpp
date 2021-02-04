#include <iostream>
#include "Node.h"

Node::Node() 
{
    std::cout<<"Node ..."<<std::endl;
}
Node::~Node()
{
    std::cout<<"~Node ..."<<std::endl;
}
void Node::Calc() const
{
    std::cout<<"Node::Calc ..."<<std::endl;
}