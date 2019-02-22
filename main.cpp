#include <iostream>
//#include <node.h>
//#include <list.h>
#include <stack.h>
#include <que.h>
using namespace std;

//void fillList(List<int>& l, int n)
//{
//    //fill a integer list with a total of n random numbers
//    int number;
//    for(int i=0; i<n; i++)
//    {
//        number = rand()%(15-0 + 1) + 0;
//        l.insert(number);
//    }
//}

template <class T>
void driver(T container);  //for testing stack and queue

int main()
{

//    Stack<int> s;
    Que<int> q;
//    driver(s);
//    cout << endl << "===============" << endl;
//    driver(q);

    cout << "hello world" << endl;
    driver(q);


    /*
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s << endl;

    Stack<int> s2;
    s2.push(10);
    cout << s2 << endl;
    s2 = s;
    cout << "s2 is: " << s2 << endl;
*/



//    cout << "Hell Wdorld!" << endl;
//    Que<int> q;
//    q.push(1);

//    q.push(2);
//    q.push(3);
//    cout << q << endl;
//    q.pop();
//    cout << q << endl;
//    cout << "q.front is: " << q.front() << endl;

//    Que<int> q2;
//    q2.push(10);
//    cout << "q2: " << q2 << endl;
//    q2 = q;
//    cout << "q2: " << q2 << endl;






//    List<int> l;
//    fillList(l, 4);
//    cout << l << endl;
//    cout << "-----" << endl;


//    List<int>::listIterator it;
//    for(it=l.begin();it!=l.end();it++)
//    {
//        cout << *it << endl;
//    }






//    it = l.begin();
//    cout << "it is good" << endl;








//    node<int>* n = new node<int>(4);
//    List<int> l2;
//    l2.insert(1);
//    l2.insert(2);
//    l2.insert(3);
//    l2.insert(4);
//    List<int> l1(l2);
//    cout << l1 << endl;

//    l1.insert(l1.find(1),0);
//    cout << l1 << endl;

//    cout << l1.count() << endl;




//    node<int>* intList = new node<int>(4);
//    print_list(intList, cout);
//    cout << intList << endl;

//    node<int>* intList = new node<int>(4);
//    insert_after(intList,intList,5);
//    insert_after(intList,intList,6);
//    insert_after(intList,intList,7);
//    print_list(intList);
//    cout << endl;
//    node<int>* cpyList;
//    copy_list(intList,cpyList);
//    print_list(cpyList);



    return 0;
}


template <class T>
void driver(T container)
{
    /*
     * Pre-condition:
     * Post-condition:
     * Purpose: for testing stack and queue
     */

    //1. declare an instance of the Stack (Queue) class, in a for loop, push 0..9 into the object, print the object
    for(int i=0; i<10; i++)
        container.push(i);
    cout << container;

    //2. Declare another object using the copy constructor to be a copy of this first object.
    T cpy(container);

    //3. while the container is not empty, pop (show the popped item in braces { } )and reprint the object
    while(!container.empty())
    {
        cout << "{ " << container.pop() << " } " << container << endl;
    }

    //4. when the object is empty, assign the second object back into the first and reprint both objects.
    container = cpy;
    cout << "container: " << container << endl;
    cout << "cpy: " << cpy << endl;

}
