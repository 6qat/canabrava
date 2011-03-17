#ifndef LIST_H
#define LIST_H

class Node;

class List
{
public:
        List(void);
        ~List(void);

        int & operator [](int i);
        void operator+= (int novo);
        int tamanho() const {return _tamanho;}
        List & operator << (int novo);

        void print();


private:
        Node *_first;
        Node *_last;
        int _tamanho;

};



#endif // LIST_H
