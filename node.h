/*
 * Author: Jack Hou
 * Project: Stack n Que
 * Purpose: Node class and its processing functions
 * Notes:
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <class T>
struct node{

    //---constructors
    node(const T& item = T(), node<T>* next = NULL):_item(item), _next(next){}

    //---operators
    node<T>& operator =(const node<T>& other){
        delete_all(_next);
        _item = other._item;
        return *this;
    }
    friend ostream& operator << (ostream& outs, const node<T>& print_me){
        //print this when the list is not empty
        if(!empty(&print_me))
            outs<<"["<<print_me._item<<"]->";
        //print this when list is empty
        else
            outs << "|||";
        return outs;
    }

    //---attributes
    T _item;
    node<T>* _next;
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

template <class T>
node<T>* copy_list(const node<T>* head, node<T>* & cpy)
{
    /*
     * Pre-condition:
     * Post-condition:
     * Purpose: makes a copy of the list, returns a pointer to the last node:
     * Note:! if given an empty(null) head, cpy is initialized to null.
     */

    if(!head) {
        init_head(cpy);
        return 0;
    }



    node<T>* last;
    recurs_cpy(head,cpy,last);
    return last;
}

template<class T>
node<T>* search(node<T>* headPtr, T _item)
{
    /*
     * Pre-condition: headPtr != 0
     * Post-condition: node is returned if it's found;
     *                  otherwise, NULL is returned
     * Purpose: search for node with the given item
     */

    assert(headPtr);

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
    /*
     * Pre-condition:
     * Post-condition:
     * Purpose: return size of the list
     */


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

template <class T>
node<T>* init_head(node<T>* &head)
{
    /*
     * Pre-condition:
     * Post-condition:
     * Purpose: initializes head to NULL
     */
    head = NULL;
    return head;
}



template <class T>
bool empty(const node<T>* head)
{
    /*
     * Pre-condition:
     * Post-condition:
     * Purpose: true if head is NULL, false otherwise.
     */
    return !head;
}

template<class T>
void delete_all(node<T>*&head)
{
    /*
     * Pre-condition:
     * Post-condition:
     * Purpose: deletes all the nodes in the list
     */
    while(head)
    {
//        cout << "head is not null" << endl;
        node<T>* temp = head->_next;
        delete_head(head);
        head = temp;
    }
}

template <class T>
T delete_head(node<T>* &head)
{
    /*
     * Pre-condition:
     * Post-condition:
     * Purpose: delete the node at the head of the list, return the item
     */

    assert(head);

    T item = head->_item;
    node<T>* temp_ptr = head;
    head = head->_next;
    delete temp_ptr;
    return item;
}


template <class T>
node<T>* insert_after(node<T>* &head, node<T>* after, const T& item)
{
    /*
     * Pre-condition:
     * Post-condition:
     * Purpose: insert_after: if after is NULL, inserts at head
     */

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

template <class T>
node<T>* insert_head(node<T>* &head, T item)
{
    /*
     * Pre-condition:
     * Post-condition:
     * Purpose: insert at the beginning of the list:
     */
    node<T>* temp_ptr = new node<T>(item, head);
    head = temp_ptr;

    return head;
}

template<class T>
ostream& print_list(const node<T>* head, ostream& outs=cout)
{
    /*
     * Pre-condition:
     * Post-condition:
     * Purpose: print the list and return outs
     */
    if(empty(head))
    {
        outs << *head;
        return outs;
    }


    node<T>* temp_ptr = new node<T>(head->_item,head->_next);
    //while the list not empty, keep printing
    while(!empty(temp_ptr))
    {
        outs << *temp_ptr;
        temp_ptr = temp_ptr->_next;
    }
    outs << *temp_ptr;


    return outs;
}





//==========TESTED=============


#endif // NODE_H
