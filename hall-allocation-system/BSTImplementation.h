#ifndef __BST_IMPLEMENTATION_H__
#define __BST_IMPLEMENTATION_H__

#include "BST.h"
#include "BSTNode.h"
#include "LinkedList.h"

// TODO: Task 3.1
template <typename K>
const BST<K>* BST<K>::find(K key) const {
    BSTNode<K>* temp = this->root;

    if (temp == nullptr){
        return nullptr;
    }
    if (temp->key == key){
        return this;
    }
    if (key < temp->key){
        return temp->left.find(key);
    }
    else if (key > temp->key){
        return temp->right.find(key);
    }
    return nullptr;
}

// TODO: Task 3.2
template <typename K>
bool BST<K>::contains(K key, const Student* student) const {
    BSTNode<K>* temp = this->root;

    if (temp == nullptr){
        return false;
    }
    if (key < temp->key){
        return temp->left.contains(key, student);
    }
    else if (key > temp->key){
        return temp->right.contains(key, student);
    }
    if (temp->key == key){
        if (temp->value.contains(student) == true){
            return true;
        }
    }
    return false;
}

// TODO: Task 3.3
template <typename K>
int BST<K>::size() const {
    BSTNode<K>* temp = this->root;
    int LEFT = 0;
    int RIGHT = 0;
    if (temp == nullptr) return 0;
    if (temp->left.root != nullptr){
        LEFT = temp->left.size();
    }
    if (temp->right.root != nullptr){
        RIGHT = temp->right.size();
    }
    return temp->value.getSize() + LEFT + RIGHT;
}

// TODO: Task 3.4
template <typename K>
void BST<K>::add(K key, Student* student) {
    if (this->root == nullptr){
        this->root = new BSTNode<K>(key, student);
    }
    else if (key == this->root->key){
        this->root->add(student);
    }
    else if (key < this->root->key){
        this->root->left.add(key, student); // Recursion on the left sub-tree
    }
    else if (key > this->root->key){
        this->root->right.add(key, student); // Recursion on the right sub-tree
    }
}

// TODO: Task 3.5
template <typename K>
LinkedList BST<K>::getAllValues() const {
    LinkedList temp;
    if (this->root == nullptr){
        return temp;
    }
    if (this->root->right.root != nullptr){
        temp.add(this->root->right.getAllValues());
    }
    temp.add(this->root->value);
    if (this->root->left.root != nullptr){
        temp.add(this->root->left.getAllValues());
    }
    return temp;
}

// TODO: Task 3.6
template <typename K>
const BST<K>* BST<K>::kthLargest(int k) const {
    if (k == 0) return nullptr;
    const BSTNode<K>* temp = this->root;
    static const BST<K>* RIGHT = nullptr;
    static const BST<K>* LEFT = nullptr;

    if (temp == nullptr) return nullptr;
    if (temp->right.root != nullptr){
        RIGHT = temp->right.kthLargest(k);
        if (RIGHT != nullptr) return RIGHT;
    }
    if (temp->value.getSize() >= (k - temp->right.size())){
        return this;
    }
    if (temp->left.root != nullptr){
        LEFT = temp->left.kthLargest(k - temp->right.size() - temp->value.getSize());
        if (LEFT != nullptr) return LEFT;
    }
    return nullptr;
}

// TODO: Task 3.7
template <typename K>
void BST<K>::remove(K key) {
    // If the tree is empty, return immediately.
    if (isEmpty()) {
        return;
    }

    // If the key is smaller than the root key, recursively remove from the left subtree.
    if (key < root->key) {
        root->left.remove(key);
    }
    // If the key is greater than the root key, recursively remove from the right subtree.
    else if (key > root->key) {
        root->right.remove(key);
    }
    // If the key is equal to the root key, remove the root node.
    else if (key == root->key){
        // If the root node has no child or only one child, replace the root with its child.
        if (root->left.isEmpty()) {
            BSTNode<K>* temp = root->right.root;
            root->right.root = nullptr;
            delete root;
            root = temp;
        }
        else if (root->right.isEmpty()) {
            BSTNode<K>* temp = root->left.root;
            root->left.root = nullptr;
            delete root;
            root = temp;
        }
        // If the root node has two children, replace the root with the maximum node in the left subtree.
        else {
            BSTNode<K>* maxNode = root->left.root;
            while (!maxNode->right.isEmpty()) {
                maxNode = maxNode->right.root;
            }
            root->key = maxNode->key;
            root->value = maxNode->value;
            root->left.remove(maxNode->key);
        }
    }
}

// TODO: Task 3.8
template <typename K>
void BST<K>::remove(K key, const Student* student) {
    if (this->root == nullptr){
        return;
    }
    if (key < root->key){
        root->left.remove(key, student);
    } 
    else if (key > root->key){
        root->right.remove(key, student);
    } 
    else if (key == root->key){
        if (this->contains(key, student) == true){
            this->root->value.remove(student);
        }
        if (this->root->value.isEmpty() == true){
            // cout << "go to remove key " << key << endl;
            this->remove(key);
        }
    }
}
#endif