/*
 * Author: Jack Hou
 * Project: Stack and Queue
 * Purpose: Implementation of the Stack and Queue data structures
 *  using linked lists and low level functions that process
    node objects.
 * Notes: Stack is implemented using linked list; Queue is implemented
 *  directly using nodes and low level functions.
 */

#include <iostream>
#include <stack.h>
#include <que.h>
#include <string>

using namespace std;

template <class T>
void driver(T container, bool stack);  //for testing stack and queue

template<class T>
void print(const T& print_me);  //helper function


int main()
{

//    cout << "hel world";
//    Que<int> q;
//    q.push(0);
//    q.pop();
////    cout << "popped " << q.pop() << endl;
//    cout << q << endl;

//    Que<int> q;
//    q.push(1);
//    print(q._head == q._tail);
//    q.pop();
//    cout << q << endl;

    //works fine
//    q.push(1);
//    q.push(2);
//    cout << q << endl;
//    cout << "popped: " << q.pop() << endl;
//    cout << q << endl;
//    cout << "popped: " << q.pop() << endl;
//    cout << q << endl;

//    node<int>* nP = new node<int>(4);
//    cout << *nP << endl;
//    delete nP;
//    nP = 0;
//    cout << *nP;















//    q.push(0);
//    q.pop();
//    if(q._head) cout << *(q._head) << endl;
//    if(q._tail) cout << "tail not deleted" << *(q._tail) << endl;
//    q.push(1);
//    cout << q << endl;

//    //====TESTING STACK
    Stack<int> s;
    driver(s, 1);

    cout << endl << "===============" << endl;

//    //====TESTING QUEUE
    Que<int> q;
    driver(q,0);
    return 0;
}

template <class T>
void driver(T container, bool stack)
{
    /*
     * Pre-condition:
     * Post-condition:
     * Purpose: for testing stack and queue; each step
     *  is written according to canvas project description.
     *
     */


    //helper function used for printing
    auto name = [](bool stack){return stack?'s':'q';};

    //1. declare an instance of the Stack (Queue) class, in a for loop, push 0..9 into the object, print the object
    for(int i=0; i<10; i++)
        container.push(i);
    cout << name(stack) << ": " <<container << endl;

    //2. Declare another object using the copy constructor to be a copy of this first object.
    T cpy(container);
    cout << name(stack) << "2: " <<cpy << endl;

    //3. while the container is not empty, pop (show the popped item in braces { } )and reprint the object
    while(!container.empty())
    {
        cout << "{ " << container.pop() << " } " << container << endl;
    }

    //4. when the object is empty, assign the second object back into the first and reprint both objects.
    container = cpy;
    cout<< "assigning " << name(stack) <<"2 back into " << name(stack)
        << ": " << name(stack) << ": "<< container << endl
        << name(stack) << "2: " << cpy << endl;
}

template<class T>
void print(const T& print_me)
{   //use this function to replace couts.
    cout << ": " << print_me << endl;
}
