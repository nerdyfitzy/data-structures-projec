#ifndef __SLLIST_H__
#define __SLLIST_H__

#include <iostream>
using namespace std;

namespace ds {

template <typename ItemType> class Node {
public:
  ItemType item;
  Node *next;

  Node(ItemType i, Node *n = nullptr) {
    this->item = i;
    this->next = n;
  }
};

template <typename ItemType>
class TestDriver; // for autograding only; please ignore

/** Singly linked list. */
template <typename ItemType> class SLList {
  friend class TestDriver<ItemType>; // for autograding only; please ignore

private:
  /** Pointer pointing to the sentinel node. */
  Node<ItemType> *sentinel;

  /** Stores the current size of the list. */
  int count;

public:
  /** Construct a new SLList object. */
  SLList() {
    this->sentinel = new Node<ItemType>(ItemType(), nullptr);
    this->count = 0;
  }

  /** Destroy the SLList object. */
  ~SLList() {
    count = 0;
    while (sentinel != nullptr) {
      Node<ItemType> *curr = sentinel;
      sentinel = sentinel->next;
      delete curr;
    }
  }

  /** Add x at the beginning of the list. */
  void addFirst(ItemType x) {
    count += 1;
    sentinel->next = new Node<ItemType>(x, sentinel->next);
  }

  /** Return the first element. */
  ItemType &getFirst() const { return sentinel->next->item; }

  /** Return the number of elements in list. */
  int size() const { return count; }

  /** Append the list with x. */
  void addLast(ItemType x) {
    count += 1;
    Node<ItemType> *p = sentinel;
    while (p->next != nullptr) {
      p = p->next;
    }
    p->next = new Node<ItemType>(x, nullptr);
  }


  inline SLList(const SLList<ItemType> &other);
  inline ItemType &get(int i) const;
  inline void insertAt (ItemType x, int pos);
  inline ItemType removeFirst();
  inline ItemType removeLast();
};

/**
 * Copy-construct a new SLList<ItemType>::SLList object
 *
 * @param other some list
 */
template <typename ItemType>
SLList<ItemType>::SLList(const SLList<ItemType> &other) {
  // Initialize the SLList to be an identical copy of `other`
  
  /** going through every one of other 
      make a copy of the node in current list */
  Node<ItemType> * p = other.sentinel;

  Node<ItemType> * prev = nullptr;

  int pos=0;
  
  while (p!=nullptr) 
  {
        cout <<"Copying node"<<p->item<<endl;
	Node<ItemType> * newNode = new Node<ItemType> (p->item, nullptr);
 
        if (pos==0)
		sentinel = newNode;
        else
                prev->next = newNode;

        prev = newNode; //the newNode becomes previous node... 

        pos++;

        //move to next node in other 
        p = p->next;
  }

  count = other.count;
  
}

/**
 *  Return the i-th item in list. Index starts from 0.
 *  For simplicity, assume the item always exists.
 *
 * @param i index of item
 * @return ItemType& the i-th item
 */
template <typename ItemType> ItemType &SLList<ItemType>::get(int i) const 
{
   int pos=0;  //sentinel is the -1-th node 
   Node<ItemType> *p = sentinel->next;

   while (pos<i) 
   {
      p = p->next;
      pos++;
   }
   return (p->item);
 
 
}

/**
 *  Add a new Itemtype of valeu x into the list at the i-th item in list. Index starts from 0.
 *  For simplicity, assume the list containts at least i number of items.
 * @param x new item to into the list 
 * @param i index for the new item
 */
template <typename ItemType> void SLList<ItemType>::insertAt(ItemType x, int i) 
{
  //first find the (i-1)-th node 
  int pos=-1;
  Node<ItemType> * p =sentinel;

  while (pos<i-1) {
      p = p->next;
      pos++;
  }
 
  //Now create a new node to store x
  Node<ItemType> * n = new Node<ItemType> (x, p->next); 

  p->next = n;

  count++;
  
}

/**
 * Remove and return the first item of the list.
 * For example, list [1,2,3] becomes [2,3] and 1 is returned.
 *
 * @return ItemType the first item in the original list before removing
 */
template <typename ItemType> ItemType SLList<ItemType>::removeFirst() {
  
  Node<ItemType> * p =sentinel->next;

  //skip this first node, by making sentinel's next point to the node after p
  sentinel->next = p->next; 

  ItemType value = p->item;
  delete p;

  count--;
  return value;

}

/**
 * Remove and return the last item of the list.
 * For example, list [1,2,3] becomes [1,2] and 3 is returned.
 *
 * @return ItemType the last item in the original list before removing
 */
template <typename ItemType> ItemType SLList<ItemType>::removeLast() {
  
  //move p,q forward until they point to second last and last node 

  //set up p, q so that q is one step ahead of p
  Node<ItemType> * p = sentinel;
  Node<ItemType> * q = p->next;
  while (q->next!=nullptr) //keep moving until q points to last node 
		//and therefore p points to the node before it 
  { 
     p = p->next; 
     q = q->next;
  }
 
  //q points to last node, p points to the node before last node
  p->next = nullptr; //remove last node from linked list
  count--;

  ItemType value = q->item;
  delete q;
  
  return value;
 
}

} // namespace ds

#endif // __SLLIST_H__
