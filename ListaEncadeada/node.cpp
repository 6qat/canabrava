#include "node.h"

Node::Node(int v, List *pai):_value(v),_next(0)
{

}

int Node::value()
{
        return this->_value;
}

Node * Node::next()
{
        return this->_next;
}
