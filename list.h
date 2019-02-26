/*
 * Author: Jack Hou
 * Project: Stack n Que
 * Purpose: List class
 * Notes:
 */

#ifndef LIST_H
#define LIST_H

#include <node.h>

template<class T>
class List
{
public:
    //---constructors
    List();
    List(T _item):headPtr(new node<T>(_item)){}
    ~List();
    List(const List<T>& other);

    //---operators
    List<T>& operator =(const List<T>& other)
    {
        delete_all(headPtr);
        copy_list(other.headPtr, headPtr);
        return *this;
    }

    friend ostream& operator << (ostream& outs, const List<T>& print_me)
    {
        return print_list(print_me.headPtr, outs);
    }

    //---methods
    void insert(T _item);

    void insert(node<T>*_node ,T _item);

    T remove();

    node<T>* find(T _item);

    int count();


    //---public iterator
    class listIterator
    {
    public:
        //---constructors
        listIterator():pos(0){}
        listIterator(node<T>* ndPtr):pos(ndPtr){}
        listIterator(const listIterator& other):pos(other.pos){}

        //---operators
        listIterator& operator=(const listIterator& other)
        {
            if(pos) delete pos;
            copy_list(other.pos,pos);
            return *this;
        }
        //accessor/mutators
        T& operator*() const{
            assert(pos);

            return pos->_item;
        }

        //increment/decrement
        listIterator& operator++(){
            assert(pos);

            pos = pos->_next;
            return *this;
        }     //prefix
        listIterator operator ++(int){
            assert(pos);

            listIterator oldVal = *this;
            pos = pos->_next;
            return oldVal;
        }  //postfix

        //comparison
        bool operator==(const listIterator& other) const{
            return pos == other.pos;
        }
        bool operator!=(const listIterator& other) const{
            return !(*this == other);
        }


    private:
        node<T>* pos;
        friend class List;
    };

    listIterator begin()
    {
        /*
         * Pre-condition:
         * Post-condition:
         * Purpose: return an iterator instance that points to
         *  the head of list
         */
        return listIterator(headPtr);
    }

    listIterator end()
    {
        /*
         * Pre-condition:
         * Post-condition:
         * Purpose: return an iterator instance that points to null
         */
        return listIterator();
    }


private:
    node<T>* headPtr;
};



//=========
//=========IMPLEMENTATION===========
//                       ===========



template<class T>
List<T>::List()
{
    //default constructor
    init_head(headPtr);
}

template<class T>
List<T>::~List()
{
    //destructor
    delete_all(headPtr);
}

template<class T>
List<T>::List(const List<T>& other)
{
    //copy constructor
    copy_list(other.headPtr, headPtr);
}

template<class T>
void List<T>::insert(T _item)
{
    /*
     * Pre-condition:
     * Post-condition:
     * Purpose: insert at head
     */
    insert_head(headPtr, _item);
}


template<class T>
void List<T>::insert(node<T>*_node ,T _item)
{
    /*
     * Pre-condition:
     * Post-condition:
     * Purpose:insert after given node
     */
    insert_after(headPtr, _node, _item);
}


template<class T>
T List<T>::remove()
{
    /*
     * Pre-condition:
     * Post-condition:
     * Purpose: remove the head and return the ITEM */
    return delete_head(headPtr);
}

template<class T>
node<T>*  List<T>::find(T _item){
    /*
     * Pre-condition:
     * Post-condition:
     * Purpose: find item(first occurance)
     */
    return search(headPtr,_item);
}

template<class T>
int List<T>::count()
{
    /*
     * Pre-condition:
     * Post-condition:
     * Purpose:list size
     */
    return size(headPtr);
}




#endif // LIST_H
