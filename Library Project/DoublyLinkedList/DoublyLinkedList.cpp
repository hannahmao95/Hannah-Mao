#include "DoublyLinkedList.h"
#include <stdexcept>
// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};
// copy constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll)
{
  // Initialize the list
  header.next = &trailer; trailer.prev = &header;   //2 operations
  
  // Copy from dll
    DListNode *newNode =dll.getFirst();  //get the first node    //1 operation
    header.next= trailer.prev= new DListNode(newNode->getElem(), &header, &trailer);   //2 operations
    newNode=newNode->getNext();          //1 opearation
    
    /* Complete this function */
    while(newNode != dll.getAfterLast()) //while it is not the last node   //n iterations
    {
        insertLast(newNode->getElem());//insert element to the last node   //1 operation
        newNode=newNode->getNext(); //newNode points to the nextnode       //1 operation
    }
 
    //f(n)=6+2n=O(n)
    
}
// assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)
{
  // Delete the whole list
  /* Complete this function */
    while(!(this->isEmpty())){    //n iterations
        this->removeLast();       //1 operation
    }

    header=0;
    trailer=0;                   //4 operations
    header.next=&trailer;
    trailer.prev=&header;
    
    // Copy from dll
    /* Complete this function */
    
    DListNode * newNode=dll.getFirst(); //1 operation
    header.next= trailer.prev= new DListNode(newNode->getElem(), &header, &trailer); //2 operations
    newNode=newNode->getNext();  //1 operaiton
    
    while(newNode != dll.getAfterLast()) //n iterations
    {
        insertLast(newNode->getElem()); //1 operation
        newNode=newNode->getNext();    //1 operation
    }
    
    return *this;
    
    //f(n)=n+8+2n=3n+8=O(n)
}
// insert the object to the first of the linked list
void DoublyLinkedList::insertFirst(int newobj)
{ 
  DListNode *newNode = new DListNode(newobj, &header, header.next);
  header.next->prev = newNode;
  header.next = newNode;
}
// insert the object to the last of the linked list
void DoublyLinkedList::insertLast(int newobj)
{
  DListNode *newNode = new DListNode(newobj, trailer.prev,&trailer);
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}
// remove the first object of the list
int DoublyLinkedList::removeFirst()
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode *node = header.next;
  node->next->prev = &header;
  header.next = node->next;
  int obj = node->obj;
  delete node;
  return obj;
}
// remove the last object of the list
int DoublyLinkedList::removeLast()
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  int obj = node->obj;
  delete node;
  return obj;
}
// destructor
DoublyLinkedList::~DoublyLinkedList()
{
  DListNode *prev_node, *node = header.next;
  while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
}
// return the first object
int DoublyLinkedList::first() const
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  return header.next->obj;
}
// return the last object
int DoublyLinkedList::last() const
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  return trailer.prev->obj;
}
// return the list length
int DoublyLinkedListLength(DoublyLinkedList& dll) {
  DListNode *current = dll.getFirst();
  int count = 0;
  while(current != dll.getAfterLast()) {
    count++;
    current = current->getNext(); //iterate
  }
  return count;
}
// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList& dll) {
  
  /* Complete this function */
    DListNode *Node= dll.getFirst(); //go to the first node    //1 operation
    
    while (Node != dll.getAfterLast()) {   //while it is not the last node  //n iteraions
        out<< Node->getElem()<<" "; //output the element   //1 operaiton
        Node= Node->getNext();   //go to the next node     //1 operation
    }                                                      //f(n)=1+2n=O(n)
  
  return out;
}
