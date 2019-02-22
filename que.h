#ifndef QUE_H
#define QUE_H
#include <node.h>

template <class T>
class Que{
public:
    Que():_head(NULL), _tail(NULL){}

    ~Que(){
        delete_all(_head);
    }

    Que(const Que<T>& other)
    {
        if(!other._head){
            init_head(_head);
            _tail = _head;
        }
        else{
            _tail = copy_list(other._head, _head);
        }
    }

    Que<T> &operator =(const Que& rhs)
    {
        delete_all(_head);
        cout << "_head is deleted" << endl;
        _tail = copy_list(rhs._head, _head);
        cout << "_tail is copied" << endl;
        return *this;
    }

    void push(T item)
    {   //push to tail

        _tail = insert_after(_head, _tail, item);

        cout << "haha" << endl;
    }

    T pop()
    {   //remove the head
        return delete_head(_head);
    }

    bool empty()
    {
        return !_head;  //if head is null, its an empty list
    }

    T front()
    {
        return _head->_item;
    }

    friend ostream& operator <<(ostream& outs, const Que& q){
        return print_list(q._head, outs);
    }

private:
    node<T>* _head;
    node<T>* _tail;
};

#endif // QUE_H
