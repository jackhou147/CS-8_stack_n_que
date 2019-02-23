#ifndef QUE_H
#define QUE_H
#include <node.h>

template <class T>
class Que{
public:
    //-----CONSTRUCTORS
    Que():_head(NULL), _tail(NULL){}
    ~Que();
    Que(const Que<T>& other);


    //-----METHODS
    bool empty();
    void push(T item);
    T pop();
    T front();


    //-----OPERATORS
    Que<T> &operator =(const Que& rhs)
    {
        delete_all(_head);
        _tail = copy_list(rhs._head, _head);
        return *this;
    }

    friend ostream& operator <<(ostream& outs, const Que& q){
        return print_list(q._head, outs) << endl;
    }


private:
    node<T>* _head;
    node<T>* _tail;
};










//=========
//=========IMPLEMENTATION===========
//                       ===========


template <class T>
Que<T>::~Que(){
    delete_all(_head);
}

template <class T>
Que<T>::Que(const Que<T>& other)
{
    if(!other._head){
        init_head(_head);
        _tail = _head;
    }
    else{
        _tail = copy_list(other._head, _head);
    }
}


template <class T>
void Que<T>::push(T item)
{   //push to tail
    _tail = insert_after(_head, _tail, item);
}

template <class T>
T Que<T>::pop()
{   //remove the head
    return delete_head(_head);
}

template <class T>
bool Que<T>::empty()
{
    return !_head;  //if head is null, its an empty list
}

template <class T>
T Que<T>::front()
{
    return _head->_item;
}



#endif // QUE_H
