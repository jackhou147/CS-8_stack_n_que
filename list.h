#ifndef LIST_H
#define LIST_H

#include <node.h>

template<class T>
class List
{
public:
    //---constructors
    List(){init_head(headPtr);}
    List(T _item):headPtr(new node<T>(_item)){}
    ~List()
    {
        cout << "List destructor fired" << endl;
        delete_all(headPtr);
        cout << "List destructor finished" << endl;
    }
    List(const List<T>& other) {
        copy_list(other.headPtr, headPtr);
    }

    //---operators
    List<T>& operator =(const List<T>& other) {
        delete_all(headPtr);
        copy_list(other.headPtr, headPtr);

        return *this;
    }

    friend ostream& operator << (ostream& outs, const List<T>& print_me)
    {
        return print_list(print_me.headPtr, outs);
    }

    //---methods
    void insert(T _item){
        insert_head(headPtr, _item);
    }               //insert at head

    void insert(node<T>*_node ,T _item)
    {
        insert_after(headPtr, _node, _item);
    }//insert after given node

    //-----!!!-------
    T remove()
    {   //remove the head and return the ITEM
        return delete_head(headPtr);
    }

    node<T>* find(T _item){
        return search(headPtr,_item);
    }             //find item(first occurance)

    int count(){return size(headPtr);}  //list size


    //---
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
            delete pos;
            copy_list(other.pos,pos);
            return *this;
        }
            //accessor/mutators
        T& operator*() const{
            return pos->_item;
        }

            //increment/decrement
        listIterator& operator++(){
            cout << "++ fired" << endl;
            pos = pos->_next;
            return *this;
        }     //prefix
        listIterator operator ++(int){
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

    listIterator begin(){
        cout << "begin fired" << endl;
        return listIterator(headPtr);
    }

    listIterator end()
    {
        return listIterator();
    }


private:
    node<T>* headPtr;
};

#endif // LIST_H
