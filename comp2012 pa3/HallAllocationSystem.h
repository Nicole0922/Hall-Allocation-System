#ifndef __HALLALLOCATIONSYSTEM_H__
#define __HALLALLOCATIONSYSTEM_H__

#include "BST.h"
#include "HashTable.h"
#include "LinkedList.h"
#include "Student.h"

class HallAllocationSystem {
   private:
    HashTable* studentTable;
    BST<int>* studentQueue;
    LinkedList studentPendingList;
    int totalHallAvailable;

   public:
    HallAllocationSystem(int totalHallAvailable);
    ~HallAllocationSystem();
    void allocateHall();
    void addStudent(Student* student);
    void removeStudent(const Student* student);
    bool predict(const Student* student) const;
    void acceptOffer(Student* student);
    void rejectOffer(Student* student);
    void acceptAllOffers();
    void rejectAllOffers();
    const BST<int>* getStudentQueue() const { return studentQueue; }
    const HashTable* getStudentTable() const { return studentTable; }
    const LinkedList* getStudentPendingList() const {
        return &studentPendingList;
    }
    int getTotalHallAvailable() const { return totalHallAvailable; }
};

#endif