#include "list.h"
#include "node.h"
#include <QCoreApplication>

#include <iostream>
using namespace std;

List::List(void):_first(0),_tamanho(0),_last(0)
{
}


int & List::operator [](int idx)
{
        if(! _tamanho || _tamanho > (idx -1))
                QCoreApplication::quit();


        int atual = 0;
        Node *temp = _first;
        for(int i=0;i<idx;++i)
                temp = temp->next();
        return temp->_value;



}

void List::operator+= (int n)
{
        Node *novo = new Node(n, this);
        if(!_tamanho)
        {
                _first = novo;
                _last = novo;

        }else {
                _last->_next = novo;
                _last = novo;
        }

        ++_tamanho;

}

void List::print()
{

        for(int i = 0; i< _tamanho; ++i)
                cout << (*this)[i] << endl;
}

List & List::operator << (int novo)
{

        (*this)+= novo;
        return *this;
}

List::~List()
{
}

int List::pop()
{
}
