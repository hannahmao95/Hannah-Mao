
#include <cstdlib>
#include <iostream>
#include <stdexcept>


using namespace std;

template<class T>
class DoublyLinkedList; // class declaration

// list node
template<class T>
class DListNode{
private: T obj;
    DListNode<T> *prev, *next;
    friend class DoublyLinkedList<T>;
public:
    DListNode<T>(T e=T(), DListNode<T> *p = NULL, DListNode<T> *n = NULL)
    : obj(e), prev(p), next(n) {}
    T getElem() const { return obj; }
    DListNode<T> * getNext() const { return next;}
    DListNode<T> * getPrev() const { return prev;}
   
                              
};

// doubly linked list
template<class T>
class DoublyLinkedList {
protected: DListNode<T> header, trailer;
public:
    DoublyLinkedList<T>() : header(T()), trailer(T()) // constructor
    { header.next = &trailer; trailer.prev = &header; }
    DoublyLinkedList<T>(const DoublyLinkedList<T>& dll); // copy constructor
    ~DoublyLinkedList<T>(); // destructor
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& dll); // assignment operator
    // return the poTer to the first node
    DListNode<T> *getFirst() const { return header.next; }
    // return the pointer to the trailer
    const DListNode<T> *getAfterLast() const { return &trailer; }
    // return if the list is empty
    bool isEmpty() const { return header.next == &trailer; }
    T first() const; // return the first object
    T last() const; // return the last object
    void insertFirst(T newobj); // insert to the first of the list
    T removeFirst(); // remove the first node
    void insertLast(T newobj); // insert to the last of the list
    T removeLast(); // remove the last node
    
    
};

// output operator
template<typename T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll);



// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
    explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

// copy constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& dll)
{
    // Initialize the list
    header.next = &trailer; trailer.prev = &header;
    
    // Copy from dll
    DListNode<T> *newNode =dll.getFirst();  //get the first node
    header.next= trailer.prev= new DListNode<T>(newNode->getElem(), &header, &trailer);
    newNode=newNode->getNext();
    
    /* Complete this function */
    while(newNode != dll.getAfterLast()) //while it is not the last node
    {
        insertLast(newNode->getElem());//insert element to the last node
        newNode=newNode->getNext(); //newNode poTs to the nextnode
    }
    
    
    
}

// assignment operator
template<class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& dll)
{
    // Delete the whole list
    /* Complete this function */
    while(!(this->isEmpty())){
        this->removeLast();
    }
    
    header=T();
    trailer=T();
    header.next=&trailer;
    trailer.prev=&header;
    
    // Copy from dll
    /* Complete this function */
    
    DListNode<T> * newNode=dll.getFirst();
    header.next= trailer.prev= new DListNode<T>(newNode->getElem(), &header, &trailer);
    newNode=newNode->getNext();
    
    while(newNode != dll.getAfterLast())
    {
        insertLast(newNode->getElem());
        newNode=newNode->getNext();
    }
    
    return *this;
    
    
}

// insert the object to the first of the linked list
template<class T>
void DoublyLinkedList<T>::insertFirst(T newobj)
{
    DListNode<T> *newNode = new DListNode<T>(newobj, &header, header.next);
    header.next->prev = newNode;
    header.next = newNode;
}

// insert the object to the last of the linked list
template<class T>
void DoublyLinkedList<T>::insertLast(T newobj)
{
    DListNode<T> *newNode = new DListNode<T>(newobj, trailer.prev,&trailer);
    trailer.prev->next = newNode;
    trailer.prev = newNode;
}

// remove the first object of the list
template<class T>
T DoublyLinkedList<T>::removeFirst()
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode<T> *node = header.next;
    node->next->prev = &header;
    header.next = node->next;
    T obj = node->obj;
    delete node;
    return obj;
}

// remove the last object of the list
template<class T>
T DoublyLinkedList<T>::removeLast()
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    DListNode<T> *node = trailer.prev;
    node->prev->next = &trailer;
    trailer.prev = node->prev;
    T obj = node->obj;
    delete node;
    return obj;
}

// destructor
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList<T>()
{
    DListNode<T> *prev_node, *node = header.next;
    while (node != &trailer) {
        prev_node = node;
        node = node->next;
        delete prev_node;
    }
    header.next = &trailer;
    trailer.prev = &header;
}

// return the first object
template<class T>
T DoublyLinkedList<T>::first() const
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    return header.next->obj;
}

// return the last object
template<class T>
T DoublyLinkedList<T>::last() const
{
    if (isEmpty())
        throw EmptyDLinkedListException("Empty Doubly Linked List");
    return trailer.prev->obj;
}

// return the list length
template<class T>
T DoublyLinkedListLength(DoublyLinkedList<T>& dll) {
    DListNode<T> *current = dll.getFirst();
    int count = 0;
    while(current != dll.getAfterLast()) { 
        count++;
        current = current->getNext();
    }
    return count;
}



// output operator
template<class T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll) {
    
    /* Complete this function */
    DListNode<T> *Node= dll.getFirst(); //go to the first node
    
    while (Node != dll.getAfterLast()) {   //while it is not the last node
        out<< Node->getElem()<<" "; //output the element
        Node= Node->getNext();   //go to the next node
    }
    
    return out;
}
