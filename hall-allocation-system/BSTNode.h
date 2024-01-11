#ifndef __BSTNODE_H__
#define __BSTNODE_H__

#include "LinkedList.h"
#include "Student.h"

/**
 * The structure of BSTNode
 * following the lecture slide
 */
template <typename S>
class BSTNode {
   public:
    S key;

    // In this PA, we use LinkedList as the value, then insert the Student
    // pointer with same hall points into the same LinkedList
    LinkedList value;

    BST<S> left;
    BST<S> right;
    BSTNode(S key, Student* student) : key(key) { value.add(student); }
    BSTNode(const BSTNode& node) = default;
    void add(Student* student) { value.add(student); }
};

#endif