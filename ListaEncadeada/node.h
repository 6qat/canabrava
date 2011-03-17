#ifndef NODE_H
#define NODE_H


class List;

class Node
{
public:
        Node(int, List *pai);
        int value();
        Node * next();

        friend class List;


private:
        int _value;
        Node * _next;
        List * _list;
};


#endif // NODE_H
