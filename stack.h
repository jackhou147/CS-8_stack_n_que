/*
 * Author: Jack Hou
 * Project: Stack n Que
 * Purpose: Stack class
 * Notes:
 */

#ifndef STACK_H
#define STACK_H
#include <list.h>
template <class T>
class Stack{
public:
    //-----CONSTRUCTORS
    Stack(){}
    Stack(const Stack<T>& other):_stack(other._stack){}

    //-----METHODS
    void push(T item);  //push to top
    T pop();    //pop the first item out of stack and return it
    T top();    //return the first item
    bool empty();   //whether stack is empty

    //-----OPERATORS
    friend ostream& operator << (ostream& outs, const Stack& s)
    {
        outs << s._stack << endl;
        return outs;
    }

    Stack<T>& operator =(const Stack<T>& rhs)
    {
        /*
         * Pre-condition:
         * Post-condition:
         * Purpose: assignment operator
         */
        _stack = rhs._stack;
        return *this;
    }
private:
    List<T> _stack;
};



//=========
//=========IMPLEMENTATION===========
//                       ===========

template <class T>
void Stack<T>::push(T item)
{   //push a new node with item to head
    /*
     * Pre-condition:
     * Post-condition:
     * Purpose: insert item at top
     */
    _stack.insert(item);
}

template <class T>
T Stack<T>::pop()
{   //pop the head and return its item
    /*
     * Pre-condition:
     * Post-condition:
     * Purpose: pop first item and return it
     */
    return _stack.remove();
}

template <class T>
T Stack<T>::top()
{   //return top item
    /*
     * Pre-condition:
     * Post-condition:
     * Purpose: return first item
     */
    return *(_stack.begin());
}

template <class T>
bool Stack<T>::empty()
{
    /*
     * Pre-condition:
     * Post-condition:
     * Purpose: return true if empty stack; false otherwise
     */
    return (_stack.count() == 0);
}
#endif // STACK_H
