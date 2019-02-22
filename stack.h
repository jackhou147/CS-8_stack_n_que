#ifndef STACK_H
#define STACK_H
#include <list.h>
template <class T>
class Stack{
public:
    Stack(){}
    Stack(const Stack<T>& other):_stack(other._stack){}
    Stack<T>& operator =(const Stack<T>& rhs)
    {
        _stack = rhs._stack;
        return *this;
    }

    void push(T item)
    {   //push a new node with item to head
        _stack.insert(item);
    }

    T pop()
    {   //pop the head and return its item
        return _stack.remove();
    }

    T top()
    {   //return top item
        return *(_stack.begin());
    }

    bool empty()
    {
        return (_stack.count() == 0);
    }
    friend ostream& operator << (ostream& outs, const Stack& s){
        outs << s._stack << endl;
        return outs;
    }
private:
    List<T> _stack;
};
#endif // STACK_H
