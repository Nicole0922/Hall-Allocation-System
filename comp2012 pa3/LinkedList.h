#ifndef __LLIST_H__
#define __LLIST_H__

#include <iostream>
#include "Student.h"

class LLNode {
   private:
    Student* data;
    LLNode* next;
    LLNode* prev;
    LLNode(Student* data) : data{data}, next{nullptr}, prev{nullptr} {}

   public:
    LLNode* getNext() const { return next; }
    LLNode* getPrev() const { return prev; }
    Student* getData() const { return data; }
    friend class LinkedList;
};

class LinkedList {
   private:
    LLNode* head;
    LLNode* tail;
    int size;

   public:
    LinkedList();
    LinkedList(const LinkedList& ll);
    ~LinkedList();
    int getSize() const;
    LLNode* getHead() const;
    LLNode* getNode(Student* student);
    bool isEmpty() const;
    void add(Student* student);
    void add(const LinkedList& another);
    void remove(const Student* student);
    bool contains(const Student* student) const;
    void clear();
    friend ostream& operator<<(ostream& os, const LinkedList& ll);
    LinkedList& operator=(const LinkedList& ll);
};
#endif