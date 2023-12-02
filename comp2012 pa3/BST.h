#ifndef __BST_H__
#define __BST_H__

#include "LinkedList.h"
#include "Student.h"

template <typename K>
class BST {
   private:
#include "BSTNode.h"
    BSTNode<K>* root = nullptr;

   public:
    BST() = default;
    BST(const BST& bst) {
        if (!bst.isEmpty()) {
            root = new BSTNode<K>(*bst.root);
        }
    }
    ~BST() {
        if (root != nullptr) {
            delete root;
        }
    }

    bool contains(K key, const Student* student) const;
    void add(K key, Student* student);
    void remove(K key);
    void remove(K key, const Student* student);
    LinkedList getAllValues() const;
    int size() const;
    const BST<K>* kthLargest(int k) const;
    const BST<K>* find(K key) const;

    bool isEmpty() const { return root == nullptr; }
    K getKey() const { return root->key; };
    LinkedList getValue() const { return root->value; };
    void printTreeOnly(int depth = 0) const {
        if (isEmpty()) {
            return;
        }

        root->right.printTreeOnly(depth + 1);
        for (int i = 0; i < depth; i++) {
            std::cout << "\t";
        }
        cout << "(" << root->key << "," << root->value.getSize() << ")" << endl;

        root->left.printTreeOnly(depth + 1);
    }
};

#include "BSTImplementation.h"

#endif