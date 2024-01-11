#include "HallAllocationSystem.h"
#include "BST.h"
#include "HashTable.h"
#include "LinkedList.h"
#include "Student.h"

// TODO: Task 5.1
HallAllocationSystem::HallAllocationSystem(int totalHallAvailable):totalHallAvailable(totalHallAvailable){
    studentTable = new HashTable(193);
    studentQueue = new BST<int>;
}

// TODO: Task 5.2
HallAllocationSystem::~HallAllocationSystem(){
    delete studentTable;
    delete studentQueue;
}

// TODO: Task 5.3
void HallAllocationSystem::allocateHall(){
    if (studentPendingList.isEmpty() == false) return;
    LinkedList save;
    while (totalHallAvailable != 0 && studentQueue->isEmpty() == false){
        const BST<int>* hihi = studentQueue->kthLargest(1);
        int KEY = hihi->getKey();
        LinkedList temp = hihi->getValue();
        LLNode* head = temp.getHead();

        for (int i=0; i<temp.getSize(); i++){
            head->getData()->setStatus(PENDING_ACTION);
            head = head->getNext();
        }

        save.add(temp);
        studentQueue->remove(KEY);
        totalHallAvailable -= temp.getSize();
        if (totalHallAvailable < 0) totalHallAvailable = 0;
    }
    studentPendingList.add(save);
}

// TODO: Task 5.4
void HallAllocationSystem::addStudent(Student* student) {
    if (studentQueue->contains(student->getTotalHallPoints(), student) 
        && studentTable->get(student->getSid()) != nullptr){
        return;
    }
    if (student->getStatus() == QUEUEING){
        studentQueue->add(student->getTotalHallPoints(), student);
        studentTable->add(student);
    }
    else return;
}

// TODO: Task 5.5
void HallAllocationSystem::removeStudent(const Student* student) {
    if (studentTable->get(student->getSid()) != nullptr){
        studentTable->remove(student);
    }

    studentQueue->remove(student->getTotalHallPoints(), student);

    if (studentPendingList.contains(student)){
        studentPendingList.remove(student);
    }
}

// TODO: Task 5.6
bool HallAllocationSystem::predict(const Student* student) const {
    if (!studentQueue->contains(student->getTotalHallPoints(), student)){
        return false;
    }
    if (totalHallAvailable == 0) return false;
    int test = studentQueue->kthLargest(totalHallAvailable)->getKey();
    if (student->getTotalHallPoints() >= test){
        return true;
    }
    else return false;
}

// TODO: Task 5.7
void HallAllocationSystem::acceptOffer(Student* student) {
    if (!studentPendingList.contains(student)) return;
    studentPendingList.remove(student);
    student->setStatus(ACCEPTED);
}

// TODO: Task 5.8
void HallAllocationSystem::rejectOffer(Student* student) {
    if (!studentPendingList.contains(student)) return;
    studentPendingList.remove(student);
    student->setStatus(REJECTED);
    totalHallAvailable++;
}

// TODO: Task 5.9
void HallAllocationSystem::acceptAllOffers() {
    LLNode* student = studentPendingList.getHead();
    int size = studentPendingList.getSize();
    for (int i=0; i<size; i++){
        LLNode* temp = student;
        student = student->getNext();
        acceptOffer(temp->getData());
    }
}

// TODO: Task 5.10
void HallAllocationSystem::rejectAllOffers() {
    LLNode* student = studentPendingList.getHead();
    int size = studentPendingList.getSize();
    for (int i=0; i<size; i++){
        LLNode* temp = student;
        student = student->getNext();
        rejectOffer(temp->getData());
    }
}