#include <iostream>
#include "LinkedList.h"
#include "Student.h"

// TODO: Task 2.2
LinkedList::LinkedList(const LinkedList& ll) {
    this->size = ll.getSize();

    LLNode* copy1 = ll.getHead();
    this->head = new LLNode(copy1->getData());
    LLNode* temp1 = this->head;
    temp1->prev = nullptr;
    temp1->next = nullptr;
    LLNode* save = nullptr;

    for (int i=0; i<this->size; i++){
        if (temp1 != this->head){
            temp1 = new LLNode(copy1->getData());
            save->next = temp1;
            temp1->prev = save;
        }
        save = temp1;
        temp1->next = nullptr;
        temp1 = temp1->next;
        copy1 = copy1->next;

        if (i == this->size-1){
            this->tail = save;
        }
    }
}

// TODO: Task 2.1
bool LinkedList::contains(const Student* data) const {
    LLNode* temp = this->head;

    if (temp != nullptr){
        for (int i=0; i<this->size; i++){
            if (temp->getData() == data){
                return true;
            }
            else{
                temp = temp->getNext();
            }
        }
    }
    return false;
}

// TODO: Task 2.3
LinkedList& LinkedList::operator=(const LinkedList& ll) {
    if (this != &ll) {
        // Clear the existing nodes in the list.
        this->clear();

        // Copy all the nodes in ll to the LinkedList object.
        LLNode* current = ll.head;
        while (current != nullptr) {
            this->add(current->getData());
            current = current->getNext();
        }
    }
    return *this;
}
