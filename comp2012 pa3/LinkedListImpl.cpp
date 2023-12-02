#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {
    LLNode* curr = head;
    while (curr != nullptr) {
        // Delete the node object, NOT the object inside the node
        LLNode* next = curr->next;
        delete curr;
        curr = next;
    }
}

void LinkedList::remove(const Student* student) {
    if (student == nullptr) {
        return;
    }
    LLNode* curr = head;
    while (curr != nullptr) {
        if (*(curr->data) == *student) {
            if (curr->prev != nullptr) {
                curr->prev->next = curr->next;
            } else {
                head = curr->next;
            }
            if (curr->next != nullptr) {
                curr->next->prev = curr->prev;
            } else {
                tail = curr->prev;
            }
            delete curr;
            size--;
            return;
        }
        curr = curr->next;
    }
}

int LinkedList::getSize() const {
    return size;
}

bool LinkedList::isEmpty() const {
    return size == 0;
}

LLNode* LinkedList::getNode(Student* student) {
    LLNode* curr = head;
    while (curr != nullptr) {
        if (*(curr->data) == *student) {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

void LinkedList::add(Student* student) {
    if (head == nullptr) {
        head = new LLNode(student);
        tail = head;
        size++;
        return;
    } else {
        LLNode* firstLarger = nullptr;
        bool doesExist = false;
        for (LLNode* curr = head; curr != nullptr; curr = curr->next) {
            if (*(curr->data) < (*student)) {
                continue;
            }
            if (*(curr->data) == (*student)) {
                doesExist = true;
                break;
            }
            // Record the first node that is larger than the student
            // But don't break, because we need to check if the student already
            // exists
            if (firstLarger == nullptr) {
                firstLarger = curr;
            }
        }
        // If the student already exists, don't add it
        if (doesExist) {
            return;
        }
        // Otherwise, add it at the position of firstLarger
        LLNode* node = new LLNode(student);
        if (firstLarger == nullptr) {
            // there is no firstLarger, so the student should be put at the end
            tail->next = node;
            node->prev = tail;
            tail = node;
            size++;
            return;
        }
        if (firstLarger->prev == nullptr) {
            // firstLarger is the first node. So the student should be put at
            // the beginning
            head = node;
        } else {
            // firstLarger is something in the middle
            firstLarger->prev->next = node;
            node->prev = firstLarger->prev;
        }
        node->next = firstLarger;
        firstLarger->prev = node;
        size++;
        return;
    }
}

LLNode* LinkedList::getHead() const {
    return head;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
    LLNode* curr = ll.head;
    while (curr != nullptr) {
        os << *(curr->getData()) << " ";
        curr = curr->getNext();
    }
    return os;
}

void LinkedList::add(const LinkedList& ll) {
    if (this == &ll) {
        return;
    }

    LLNode* curr = ll.head;
    while (curr != nullptr) {
        add(curr->data);
        curr = curr->next;
    }
}

void LinkedList::clear() {
    LLNode* curr = head;
    while (curr != nullptr) {
        LLNode* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}