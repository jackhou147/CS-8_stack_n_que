#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;
template <class T>
struct node{
    //variables...
    T _item;
    node<T>* _next;


    //methods...
    node(const T& item = T(), node<T>* next = NULL):_item(item), _next(next){}
    node<T>& operator =(const node<T>& other){
        delete_all(_next);
        _item = other._item;
        return *this;
    }
    friend ostream& operator << (ostream& outs, const node<T>& print_me){
        outs<<"["<<print_me._item<<"]->";
        return outs;
    }
};

template <class T>
node<T>* recurs_cpy(const node<T>* head, node<T>* & cpy, node<T>*& last)
{

    //---terminate condition
    if(head && !head->_next) last = new node<T>(head->_item);//set last node
    if(!head) return 0;

    //--copy the head first
    cpy = new node<T>(head->_item);

    //--let the next iteration copy the rest  :)
    cpy->_next = recurs_cpy(head->_next, cpy->_next, last);

    //(head + body) is the body of the previous iteration. return it
    return cpy;
}


//makes a copy of the list, returns a pointer to the last node:
template <class T>
node<T>* copy_list(const node<T>* head, node<T>* & cpy)
{
    //wrapper function for recurs_cpy()
    if(!head) return 0;
    node<T>* last;
    recurs_cpy(head,cpy,last);
    return last;
}

// 1 2 3 4 5












template<class T>
node<T>* search(node<T>* headPtr, T _item){
    node<T>* current = headPtr;
    while(current)
    {
        if(current->_item == _item) return current;
        current = current->_next;
    };
    return NULL;
}

template<class T>
int size(node<T>* headPtr)
{
    int counter = 0;
    node<T>* current = headPtr;
    while(current)
    {
        counter ++;
        current = current->_next;
    }
    return counter;
}







//==========50% TESTED=============

//makes a copy of the list, returns a pointer to the last node:
//template <class T>
//node<T>* copy_list(const node<T>* head, node<T>* & cpy)
//{
//    //node ptr current = head, last = current, cpy = new node(current)
//    cpy = new node<T>(head->_item);
//    node<T>* last = cpy;
//    node<T>* current = head->_next;
//    //iterate thru the list,
//    while(current)
//    {
//        //for each node,
//            //copy it and insert the copied node into the end of copied list
//        last = insert_after(cpy, last, current->_item);
//        current = current->_next;
//    }
//    //return the last node
//    return last;
//}

//initializes head to NULL
template <class T>
node<T>* init_head(node<T>* &head)
{
    head = NULL;
    return head;
}


//true if head is NULL, false otherwise.
template <class T>
bool empty(const node<T>* head)
{
    return !head;
}

//deletes all the nodes in the list
template<class T>
void delete_all(node<T>*&head)
{

    while(head)
    {
        cout << "head is not null" << endl;
        node<T>* temp = head->_next;
        delete_head(head);
        head = temp;
    }
}

//delete the node at the head of the list, return the item:
template <class T>
T delete_head(node<T>* &head)
{
    T item = head->_item;
    node<T>* temp_ptr = head;
    head = head->_next;
    delete temp_ptr;
    return item;
}


//insert_after: if after is NULL, inserts at head
template <class T>
node<T>* insert_after(node<T>* &head, node<T>* after, const T& item)
{
    T it = item;
    //if after is not null
    if(after)
    {
        node<T>* temp_ptr = new node<T>(item, after->_next);
        after->_next = temp_ptr;
        return temp_ptr;
    }
    //if after is null, insert at head
    return insert_head(head,it);
}

//insert at the beginning of the list:
template <class T>
node<T>* insert_head(node<T>* &head, T item)
{
    cout << "insert head fired" << endl;
    node<T>* temp_ptr = new node<T>(item, head);
    head = temp_ptr;
    return head;
}

//print the list and return outs
template<class T>
ostream& print_list(const node<T>* head, ostream& outs=cout)
{
    if(empty(head)) return outs;
    node<T>* temp_ptr = new node<T>(head->_item,head->_next);
    //while the list not empty, keep printing
    while(!empty(temp_ptr))
    {
        outs << *temp_ptr;
        temp_ptr = temp_ptr->_next;
    }
    return outs;
}





//==========TESTED=============


#endif // NODE_H
