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
    print("Hello world");
    print("----testing starts here-----");
    cout << endl;

    node<int> n;
    print(n._item);







//    print("Stack of other other data types");
//    print("Stack of queues");
//    Stack<Que<char>> JackGenius;
//    Que<char> Jack, genius;
//    string str1 = "Jack";
//    string str2 = "genius";
//    for(string::iterator it = str1.begin(); it!=str1.end();it++)
//        Jack.push(*it);
//    for(string::iterator it = str2.begin(); it!=str2.end();it++)
//        genius.push(*it);
//    JackGenius.push(genius);
//    JackGenius.push(Jack);

//    print("que 1:");
//    print(Jack);
//    print("que 2: ");
//    print(genius);
//    print("stack of que 1 + que 2");
//    print(JackGenius);



//    print("Stack of strings");
//    Stack<string> s;
//    s.push("Genius");
//    s.push("a");
//    s.push("is");
//    s.push("Jack");
//    print(s);
//    print("Queue of strings");
//    Que<string> q;
//    q.push("Jack");
//    q.push("is");
//    q.push("a");
//    q.push("genius");
//    print(q);









//    print("outputting an empty list");
//    List<int> l;
//    print(l);

//    print("calling the copy constructor with source being empty");
//    List<int> l2(l);
//    print(l2);

//    print("calling assignment operator with source being empty");
//    List<int> l3;
//    l3 = l2;
//    print(l3);

//    print("accessing the top  of an empty list");
//    print(*l.begin());

//    print("accessing the end of an empty list");
//    print(*l.end());

//    print("push item to empty list then access its top AND end");
//    l.insert(1);
//    print("top: ");
//    print(*l.begin());
//    print("end: ");
//    print(*l.end());

//    cout << endl;
//    print("assigning an empty list to a non-empty list");
//    l = l2;
//    print("destination: ");
//    print(l);
//    print("source:");
//    print(l2);



    //    cout << endl;
    //    print("assigning an empty stack to a non-empty stack");
    //    s = s2;
    //    print("destination: ");
    //    print(s);
    //    print("source:");
    //    print(s2);


//    print("outputting an empty stack");
//    Stack<int> s;
//    print(s);

//    print("calling the copy constructor with source being empty");
//    Stack<int> s2(s);
//    print(s2);

//    print("calling assignment operator with source being empty");
//    Stack<int> s3;
//    s3 = s2;
//    print(s3);

//    print("accessing the front of an empty stack");
//    print(s.top());

//    print("push item to empty stack then access its top");
//    s.push(1);
//    print(s.top());

//    cout << endl;
//    print("assigning an empty stack to a non-empty stack");
//    s = s2;
//    print("destination: ");
//    print(s);
//    print("source:");
//    print(s2);


//    cout << endl;
//    print("assigning an empty queue to a non-empty queue");
//    q = q2;
//    print("destination: ");
//    print(q);
//    print("source:");
//    print(q2);


//    print("outputting an empty queue");
//    Que<int> q;
//    print(q);

//    print("calling the copy constructor with source being empty");
//    Que<int> q2(q);
//    print(q2);

//    print("calling assignment operator with source being empty");
//    Que<int> q3;
//    q3 = q2;
//    print(q3);

//    print("accessing the front of an empty queue");
//    print(q.front());

//    print("push item to empty queue then access its front");
//    q.push(1);
//    print(q.front());

//    cout << endl;
//    print("assigning an empty queue to a non-empty queue");
//    q = q2;
//    print("destination: ");
//    print(q);
//    print("source:");
//    print(q2);










//    //====TESTING STACK
//    Stack<int> s;
//    driver(s, 1);

//    cout << endl << "===============" << endl;

//    //====TESTING QUEUE
//    Que<int> q;
//    driver(q,0);
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
{
    cout << ": " << print_me << endl;
}
