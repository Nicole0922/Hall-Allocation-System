#include <iostream>
#include <vector>
#include "mainTest.h"
#include "BST.h"
#include "HallAllocationSystem.h"
#include "HashTable.h"
#include "LinkedList.h"
#include "Student.h"
using namespace std;

std::vector<Student*> getStudent_1() {
    std::vector<Student*> students;
    students.push_back(new Student(1, "John", "CS", true, 3, 30, 30, true));
    students.push_back(new Student(2, "Mary", "CS", false, 2, 30, 30, true));
    students.push_back(new Student(3, "Peter", "CS", true, 1, 30, 30, true));
    students.push_back(new Student(4, "Peter", "CS", true, 1, 60, 30, false));
    students.push_back(new Student(5, "Peter", "CS", true, 4, 30, 60, false));
    students.push_back(new Student(6, "Peter", "CS", true, 4, 30, 60, true));
    students.push_back(new Student(7, "Peter", "CS", true, 4, 30, 60, false));
    students.push_back(new Student(8, "Peter", "CS", true, 4, 30, 60, false));
    students.push_back(new Student(9, "Peter", "CS", true, 4, 30, 60, true));
    students.push_back(new Student(10, "Peter", "CS", true, 4, 30, 60, false));
    students.push_back(new Student(11, "Peter", "CS", true, 4, 20, 60, false));
    students.push_back(new Student(12, "Peter", "CS", true, 4, 30, 60, false));
    students.push_back(new Student(13, "Peter", "CS", true, 4, 30, 60, false));
    students.push_back(new Student(14, "Peter", "CS", true, 4, 30, 60, false));
    students.push_back(new Student(15, "Peter", "CS", true, 4, 30, 60, false));
    students.push_back(new Student(16, "Peter", "CS", true, 4, 30, 60, false));
    students.push_back(new Student(17, "Peter", "CS", true, 4, 30, 60, false));
    return students;
}

// Test Student Constructor (Task 1.1)
// GIVEN
void test_1() {
    cout << "============================" << endl;
    cout << "Running Test Case 1....." << endl;
    Student a = Student(999, "Desmond", "CSE", true, 1, 60, 60, true);
    Student b = Student(998, "Desmond", "CSE", false, 1, 30, 30, true);
    if (a.getTotalHallPoints() == 40 &&
        a.getStatus() == HallApplicationStatus::QUEUEING &&
        b.getTotalHallPoints() == 40 &&
        b.getStatus() == HallApplicationStatus::QUEUEING) {
        cout << "Test Case 1 Passed!" << endl;
    } else {
        cout << "Test Case 1 Failed!" << endl;
    }
    cout << "============================" << endl;
}

// Test Student operator== (Task 1.2)
// GIVEN
void test_2() {
    cout << "============================" << endl;
    cout << "Running Test Case 2....." << endl;
    Student a = Student(999, "Desmond", "CSE", true, 1, 60, 60, true);
    if (a == 999 && !(a == 9)) {
        cout << "Test Case 2 Passed!" << endl;
    } else {
        cout << "Test Case 2 Failed!" << endl;
    }
    cout << "============================" << endl;
}

// Test LinkedList::contains (Task 2.1)
// GIVEN
void test_3() {
    cout << "============================" << endl;
    cout << "Running Test Case 3....." << endl;
    LinkedList ll = LinkedList();
    Student* a = new Student(999, "Desmond", "CSE", true, 1, 60, 60, true);
    Student* b = new Student(998, "Desmond", "CSE", true, 1, 60, 60, true);
    Student* c = new Student(997, "Desmond", "CSE", true, 1, 60, 60, true);
    ll.add(a);
    ll.add(b);

    if (ll.contains(a) && ll.contains(b) && !ll.contains(c)) {
        cout << "Test Case 3 Passed!" << endl;
    } else {
        cout << "Test Case 3 Failed!" << endl;
    }
    cout << "============================" << endl;
    delete a;
    delete b;
    delete c;
}

// Test LinkedList copy constructor (Task 2.2)
// Given
void test_4() {
    cout << "============================" << endl;
    cout << "Running Test Case 4....." << endl;
    LinkedList ll = LinkedList();
    Student* a = new Student(999, "Desmond", "CSE", true, 1, 60, 60, true);
    Student* b = new Student(998, "Desmond", "CSE", true, 1, 60, 60, true);
    Student* c = new Student(997, "Desmond", "CSE", true, 1, 60, 60, true);
    ll.add(a);
    ll.add(b);
    ll.add(c);

    LinkedList other = LinkedList(ll);
    LLNode* cur1 = ll.getHead();
    LLNode* cur2 = other.getHead();

    bool same = true;
    if (other.getSize() != ll.getSize()) {
        same = false;
    }
    while (cur1 != nullptr && cur2 != nullptr) {
        if (cur1->getData() != cur2->getData() || cur1 == cur2) {
            same = false;
            break;
        }
        cur1 = cur1->getNext();
        cur2 = cur2->getNext();
    }

    if (same) {
        cout << "Test Case 4 Passed!" << endl;
    } else {
        cout << "Test Case 4 Failed!" << endl;
    }

    cout << "============================" << endl;
    delete a;
    delete b;
    delete c;
}

// Test LinkedList operator= (Task 2.3)
// Given
void test_5() {
    cout << "============================" << endl;
    cout << "Running Test Case 5....." << endl;
    LinkedList ll = LinkedList();
    Student* a = new Student(999, "Desmond", "CSE", true, 1, 60, 60, true);
    Student* b = new Student(998, "Desmond", "CSE", true, 1, 60, 60, true);
    Student* c = new Student(997, "Desmond", "CSE", true, 1, 60, 60, true);
    ll.add(a);
    ll.add(b);
    ll.add(c);

    LinkedList other = ll;
    LLNode* cur1 = ll.getHead();
    LLNode* cur2 = other.getHead();

    bool same = true;
    if (other.getSize() != ll.getSize()) {
        same = false;
    }
    while (cur1 != nullptr && cur2 != nullptr) {
        if (cur1->getData() != cur2->getData() || cur1 == cur2) {
            same = false;
            break;
        }
        cur1 = cur1->getNext();
        cur2 = cur2->getNext();
    }

    if (same) {
        cout << "Test Case 5 Passed!" << endl;
    } else {
        cout << "Test Case 5 Failed!" << endl;
    }

    cout << "============================" << endl;
    delete a;
    delete b;
    delete c;
}

// Test BST contains, size, add (Task 3.2-3.4)
// Given
void test_6() {
    cout << "============================" << endl;
    cout << "Running Test Case 6....." << endl;
    BST<int>* bst = new BST<int>();
    Student* a = new Student(999, "Desmond", "CSE", true, 1, 60, 60, true);
    Student* b = new Student(998, "Desmond", "CSE", true, 1, 60, 60, true);
    Student* c = new Student(997, "Desmond", "CSE", true, 1, 60, 60, true);
    Student* d = new Student(996, "Desmond", "CSE", true, 1, 60, 60, true);

    bst->add(a->getTotalHallPoints(), a);
    bst->add(b->getTotalHallPoints(), b);
    bst->add(c->getTotalHallPoints(), c);

    bool res = (bst->size() == 3);
    res = res && (bst->contains(a->getTotalHallPoints(), a));
    res = res && (bst->contains(b->getTotalHallPoints(), b));
    res = res && (bst->contains(c->getTotalHallPoints(), c));
    res = res && (!bst->contains(d->getTotalHallPoints(), d));

    if (!res) {
        cout << "Test Case 6 Failed!" << endl;
    } else {
        cout << "The tree structure (key, length) is..." << endl;
        bst->printTreeOnly();
        cout << "Test Case 6 Completed" << endl;
    }
    cout << "============================" << endl;
    delete a;
    delete b;
    delete c;
    delete d;
    delete bst;
}

// Test BST add (Task 3.4) #2
// Given
void test_7() {
    cout << "============================" << endl;
    cout << "Running Test 7....." << endl;
    BST<int>* bst = new BST<int>();
    Student* s1 = new Student(1, "John", "CS", true, 3, 30, 30, true);
    Student* s2 = new Student(2, "Mary", "CS", false, 2, 30, 30, true);
    Student* s3 = new Student(10, "Peter", "CS", true, 1, 30, 30, true);

    bst->add(s1->getTotalHallPoints(), s1);
    bst->add(s2->getTotalHallPoints(), s2);
    bst->add(s3->getTotalHallPoints(), s3);
    bst->add(s3->getTotalHallPoints(), s3);

    cout << "Students' information is..." << endl;
    cout << *s1 << *s2 << *s3 << endl;
    cout << "The tree structure (key, length) is..." << endl;
    bst->printTreeOnly();
    cout << "Test Case 7 Completed" << endl;
    cout << "============================" << endl;
    delete s1;
    delete s2;
    delete s3;
    delete bst;
}

// Test BST add (Task 3.4) #3
// Given
void test_8() {
    cout << "============================" << endl;
    cout << "Running Test 8....." << endl;
    BST<int>* bst = new BST<int>();
    Student* s1 = new Student(1, "John", "CS", true, 3, 30, 30, true);
    Student* s2 = new Student(2, "Mary", "CS", false, 2, 30, 30, true);
    Student* s3 = new Student(10, "Peter", "CS", true, 1, 30, 30, true);
    Student* s4 = new Student(11, "Peter", "CS", true, 1, 60, 30, false);
    Student* s5 = new Student(12, "Peter", "CS", true, 4, 30, 60, false);

    bst->add(s1->getTotalHallPoints(), s1);
    bst->add(s2->getTotalHallPoints(), s2);
    bst->add(s3->getTotalHallPoints(), s3);
    bst->add(s4->getTotalHallPoints(), s4);
    bst->add(s5->getTotalHallPoints(), s5);

    cout << "Students' information is..." << endl;
    cout << *s1 << *s2 << *s3 << *s4 << *s5 << endl;
    cout << "The tree structure (key, length) is..." << endl;
    bst->printTreeOnly();
    cout << "Test Case 8 Completed" << endl;
    cout << "============================" << endl;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    delete bst;
}

// Test BST getAllValues (Task 3.5)
// Given
void test_9() {
    cout << "============================" << endl;
    cout << "Running Test 9....." << endl;
    BST<int>* bst = new BST<int>();
    Student* s1 = new Student(1, "John", "CS", true, 3, 30, 30, true);
    Student* s2 = new Student(2, "Mary", "CS", false, 2, 30, 30, true);
    Student* s3 = new Student(10, "Peter", "CS", true, 1, 30, 30, true);
    Student* s4 = new Student(11, "Peter", "CS", true, 1, 60, 30, false);
    Student* s5 = new Student(12, "Peter", "CS", true, 4, 30, 60, false);

    bst->add(s1->getTotalHallPoints(), s1);
    bst->add(s2->getTotalHallPoints(), s2);
    bst->add(s3->getTotalHallPoints(), s3);
    bst->add(s4->getTotalHallPoints(), s4);
    bst->add(s5->getTotalHallPoints(), s5);

    cout << "Students' information is..." << endl;
    cout << *s1 << *s2 << *s3 << *s4 << *s5 << endl;
    cout << "The tree structure (key, length) is ..." << endl;
    bst->printTreeOnly();
    LinkedList ll = bst->getAllValues();
    cout << "getAllValues returns the following LinkedList..." << endl;
    cout << ll << endl;
    cout << "Test Case 9 Completed" << endl;
    cout << "============================" << endl;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    delete bst;
}

// Test BST find (Task 3.1)
// Given
void test_10() {
    cout << "============================" << endl;
    cout << "Running Test 10....." << endl;
    BST<int>* bst = new BST<int>();
    Student* s1 = new Student(1, "John", "CS", true, 3, 30, 30, true);
    Student* s2 = new Student(2, "Mary", "CS", false, 2, 30, 30, true);
    Student* s3 = new Student(10, "Peter", "CS", true, 1, 30, 30, true);
    Student* s4 = new Student(11, "Peter", "CS", true, 1, 60, 30, false);
    Student* s5 = new Student(12, "Peter", "CS", true, 4, 30, 60, false);

    bst->add(s1->getTotalHallPoints(), s1);
    bst->add(s2->getTotalHallPoints(), s2);
    bst->add(s3->getTotalHallPoints(), s3);
    bst->add(s4->getTotalHallPoints(), s4);
    bst->add(s5->getTotalHallPoints(), s5);
    bool res = bst->find(s1->getTotalHallPoints())
                   ->contains(s1->getTotalHallPoints(), s1);
    res = res && bst->find(s2->getTotalHallPoints())
                     ->contains(s2->getTotalHallPoints(), s2);
    res = res && bst->find(s3->getTotalHallPoints())
                     ->contains(s3->getTotalHallPoints(), s3);
    res = res && bst->find(s4->getTotalHallPoints())
                     ->contains(s4->getTotalHallPoints(), s4);
    res = res && bst->find(s5->getTotalHallPoints())
                     ->contains(s5->getTotalHallPoints(), s5);
    res = res && (bst->find(999999) == nullptr);
    if (res) {
        cout << "Test Case 10 Passed!" << endl;
    } else {
        cout << "Test Case 10 Failed!" << endl;
    }
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    delete bst;
    cout << "============================" << endl;
}

// Test 11 kthLargest (Task 3.6)
// Given
void test_11() {
    cout << "============================" << endl;
    cout << "Running Test 11....." << endl;
    BST<int>* bst = new BST<int>();
    Student* s1 = new Student(1, "John", "CS", true, 3, 30, 30, true);
    Student* s2 = new Student(2, "Mary", "CS", false, 2, 30, 30, true);
    Student* s3 = new Student(10, "Peter", "CS", true, 1, 30, 30, true);
    Student* s4 = new Student(11, "Peter", "CS", true, 1, 30, 30, true);
    Student* s5 = new Student(12, "Peter", "CS", true, 1, 28, 29, true);

    bst->add(s5->getTotalHallPoints(), s1);
    bst->add(s2->getTotalHallPoints(), s2);
    bst->add(s3->getTotalHallPoints(), s3);
    bst->add(s3->getTotalHallPoints(), s3);
    bst->add(s4->getTotalHallPoints(), s4);
    bst->add(s1->getTotalHallPoints(), s5);

    cout << "Students' information is..." << endl;
    cout << *s1 << *s2 << *s3 << *s4 << *s5 << endl;
    cout << "The tree structure (key, length) is..." << endl;
    bst->printTreeOnly();
    cout << "kthLargest(2)" << endl;
    bst->kthLargest(2)->printTreeOnly();

    cout << "kthLargest(1)" << endl;
    bst->kthLargest(1)->printTreeOnly();

    cout << "kthLargest(3)" << endl;
    bst->kthLargest(3)->printTreeOnly();
    cout << "kthLargest(9999)" << endl;
    bool res = (bst->kthLargest(9999) == nullptr);
    if (res) {
        cout << "It is nullptr" << endl;
    } else {
        cout << "It is not nullptr" << endl;
    }
    cout << "Test Case 11 Completed" << endl;
    cout << "============================" << endl;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    delete bst;
}

// Test 12 remove and remove (Task 3.7-3.8)
// Given
void test_12() {
    cout << "============================" << endl;
    cout << "Running Test 12....." << endl;
    BST<int>* bst = new BST<int>();
    Student* s1 = new Student(1, "John", "CS", true, 3, 30, 30, true);
    Student* s2 = new Student(2, "Mary", "CS", false, 2, 30, 30, true);
    Student* s3 = new Student(10, "Peter", "CS", true, 1, 30, 30, true);
    Student* s4 = new Student(11, "Peter", "CS", true, 1, 30, 30, true);
    Student* s5 = new Student(12, "Peter", "CS", true, 1, 28, 29, true);


    bst->add(s5->getTotalHallPoints(), s1);
    bst->add(s2->getTotalHallPoints(), s2);
    bst->add(s3->getTotalHallPoints(), s3);
    bst->add(s3->getTotalHallPoints(), s3);
    bst->add(s4->getTotalHallPoints(), s4);
    bst->add(s1->getTotalHallPoints(), s5);

    cout << "Student information is..." << endl;
    cout << *s1 << *s2 << *s3 << *s4 << *s5 << endl;
    cout << "Before delete s3..." << endl;
    bst->printTreeOnly();
    bst->remove(s3->getTotalHallPoints(), s3);
    cout << "After delete s3..." << endl;
    bst->printTreeOnly();
    cout << "After delete s2..." << endl;
    bst->remove(s2->getTotalHallPoints(), s2);
    bst->printTreeOnly();
    cout << "Delete s2 once again ..." << endl;
    bst->remove(s2->getTotalHallPoints(), s2);
    bst->printTreeOnly();
    cout << "Test Case 12 Completed" << endl;
    cout << "============================" << endl;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    delete bst;
}

// Test 13 constructor and desctructor (Task 4.1-4.2)
// Given
void test_13() {
    cout << "============================" << endl;
    cout << "Running Test 13....." << endl;
    HashTable ht = HashTable(10);
    ht.printTable();
    cout << "Test 13 Completed" << endl;
    cout << "============================" << endl;
}

// Test 14 hash (Task 4.3)
void test_14() {
    cout << "============================" << endl;
    cout << "Running Test Case 14....." << endl;
    Student a = Student(999, "Desmond", "CSE", true, 1, 60, 60, true);
    if (HashTable::hash(a.getSid()) == 998001) {
        cout << "Test Case 14 Passed!" << endl;
    } else {
        cout << "Test Case 14 Failed!" << endl;
    }
    cout << "============================" << endl;
}

// Test 15 add and get (Task 4.4-4.5)
// Given
void test_15() {
    cout << "============================" << endl;
    cout << "Running Test 15....." << endl;
    HashTable ht = HashTable(10);
    Student* s1 = new Student(1, "John", "CS", true, 3, 30, 30, true);
    Student* s2 = new Student(2, "Mary", "CS", false, 2, 30, 30, true);
    Student* s3 = new Student(10, "Peter", "CS", true, 1, 30, 30, true);
    ht.add(s1);
    ht.add(s2);
    ht.add(s3);
    bool res1 = ht.get(s1->getSid()) == s1;
    bool res2 = ht.get(s2->getSid()) == s2;
    bool res3 = ht.get(s3->getSid()) == s3;
    bool res4 = ht.get(777) == nullptr;
    ht.printTable();
    if (res1 && res2 && res3 && res4) {
        cout << "Test 15 Passed!" << endl;
    } else {
        cout << "Test 15 Failed!" << endl;
    }
    delete s1;
    delete s2;
    delete s3;
    cout << "============================" << endl;
}

// Test 16 add, get, remove (4.4-4.6)
// Given
void test_16() {
    cout << "============================" << endl;
    cout << "Running Test 16....." << endl;
    HashTable ht = HashTable(10);
    Student* s1 = new Student(1, "John", "CS", true, 3, 30, 30, true);
    Student* s2 = new Student(2, "Mary", "CS", false, 2, 30, 30, true);
    Student* s3 = new Student(10, "Peter", "CS", true, 1, 30, 30, true);
    ht.add(s1);
    ht.add(s2);
    ht.add(s3);
    bool res = ht.get(s1->getSid()) == s1;
    res = res && ht.get(s2->getSid()) == s2;
    res = res && ht.get(s3->getSid()) == s3;
    res = res && ht.get(777) == nullptr;
    ht.remove(s3);
    res = res && ht.get(s3->getSid()) == nullptr;
    ht.remove(s2);
    res = res && ht.get(s2->getSid()) == nullptr;
    if (!res) {
        cout << "Test 16 Failed!" << endl;
    }
    ht.printTable();
    cout << "Test 16 Completed" << endl;
    cout << "============================" << endl;
    delete s1;
    delete s2;
    delete s3;
}

// Test 17 constructor and destructor (Task 5.1-5.2)
// Given
void test_17() {
    cout << "============================" << endl;
    cout << "Running Test 17....." << endl;
    HallAllocationSystem has = HallAllocationSystem(0);
    cout << "Test 17 Completed" << endl;
    cout << "============================" << endl;
}

// Test 18 allocateHall and addStudent (Task 5.3-5.4)
// Given
void test_18() {
    cout << "============================" << endl;
    cout << "Running Test 18....." << endl;
    HallAllocationSystem has = HallAllocationSystem(5);
    std::vector<Student*> students = getStudent_1();
    for (int i = 0; i < students.size(); i++) {
        has.addStudent(students[i]);
    }
    cout << "Before allocating hall...." << endl;
    has.getStudentQueue()->printTreeOnly();
    has.allocateHall();
    cout << "After allocating hall...." << endl;
    has.getStudentQueue()->printTreeOnly();
    cout << "Result list: " << endl;
    cout << *(has.getStudentPendingList());
    cout << "Test 18 Completed" << endl;
    cout << "============================" << endl;
    for (int i = 0; i < students.size(); i++) {
        delete students[i];
    }
}

// Test 19 addStudent and removeStudent (Task 5.3-5.4)
// Given
void test_19() {
    cout << "============================" << endl;
    cout << "Running Test 19....." << endl;
    HallAllocationSystem has = HallAllocationSystem(5);
    std::vector<Student*> students = getStudent_1();
    for (int i = 0; i < 3; i++) {
        has.addStudent(students[i]);
    }
    cout << "Adding 3 students" << endl;
    has.getStudentQueue()->printTreeOnly();
    cout << "Removing students with ID " << students[0]->getSid() << " and "
         << students[2]->getSid() << endl;
    has.removeStudent(students[0]);  
    has.removeStudent(students[2]);
    has.getStudentQueue()->printTreeOnly();
    cout << "Removing a non-existing student" << endl;
    has.removeStudent(students[5]);
    has.getStudentQueue()->printTreeOnly();
    cout << "Test 19 Completed" << endl;
    cout << "============================" << endl;
    for (int i = 0; i < students.size(); i++) {
        delete students[i];
    }
}

// Test 20 predict (Task 5.6)
void test_20() {
    cout << "============================" << endl;
    cout << "Running Test 20....." << endl;
    HallAllocationSystem system = HallAllocationSystem(5);
    vector<Student*> students = getStudent_1();
    for (int i = 0; i < students.size(); i++) {
        system.addStudent(students[i]);
    }
    cout << "Predict the hall allocation..." << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << "Student: " << *(students[i]);
        cout << "Prediction: " << boolalpha << system.predict(students[i])
             << endl;
    }
    cout << "Allocate hall now..." << endl;
    system.allocateHall();
    cout << "The actual result..." << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << "Student: " << *(students[i]);
        cout << "Got offer: " << boolalpha
             << (students[i]->getStatus() == PENDING_ACTION) << endl;
    }
    cout << "Predict again after hall allocation..." << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << "Student: " << *(students[i]);
        cout << "Prediction: " << boolalpha << system.predict(students[i])
             << endl;
    }
    cout << "Test 20 Completed" << endl;
    cout << "============================" << endl;
    for (int i = 0; i < students.size(); i++) {
        delete students[i];
    }
}

// Test 21 acceptAllOffers (Task 5.9)
// Given
void test_21() {
    cout << "============================" << endl;
    cout << "Running Test 21....." << endl;
    HallAllocationSystem has = HallAllocationSystem(5);
    std::vector<Student*> students = getStudent_1();
    for (int i = 0; i < students.size(); i++) {
        has.addStudent(students[i]);
    }
    cout << "Before allocating hall...." << endl;
    has.getStudentQueue()->printTreeOnly();
    has.allocateHall();
    cout << "After allocating hall...." << endl;
    has.getStudentQueue()->printTreeOnly();
    cout << "Result list before accepting offer: " << endl;
    cout << *(has.getStudentPendingList());
    has.acceptAllOffers();
    cout << "Result list after accepting offer: " << endl;
    cout << *(has.getStudentPendingList());

    cout << "Student list: " << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << *students[i];
    }
    cout << "Number of hall left: " << has.getTotalHallAvailable() << endl;
    cout << "Test 21 Completed" << endl;
    cout << "============================" << endl;
    for (int i = 0; i < students.size(); i++) {
        delete students[i];
    }
}

// Test 22 rejectAllOffers (Task 5.10)
// Given
void test_22() {
    cout << "============================" << endl;
    cout << "Running Test 22....." << endl;
    HallAllocationSystem has = HallAllocationSystem(5);
    std::vector<Student*> students = getStudent_1();
    for (int i = 0; i < students.size(); i++) {
        has.addStudent(students[i]);
    }
    cout << "Before allocating hall...." << endl;
    has.getStudentQueue()->printTreeOnly();
    has.allocateHall();
    cout << "After allocating hall...." << endl;
    has.getStudentQueue()->printTreeOnly();
    cout << "Result list before accepting offer: " << endl;
    cout << *(has.getStudentPendingList());
    cout << "The hash table:" << endl;
    has.getStudentTable()->printTable();
    has.rejectAllOffers();
    cout << "Result list after accepting offer: " << endl;
    cout << *(has.getStudentPendingList());

    cout << "Student list: " << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << *students[i];
    }
    cout << "Number of hall left: " << has.getTotalHallAvailable() << endl;
    cout << "Test 22 Completed" << endl;
    cout << "============================" << endl;
    for (int i = 0; i < students.size(); i++) {
        delete students[i];
    }
}

void TestSuite::run(int id) {
    switch (id) {
        case 1:
            test_1();
            break;
        case 2:
            test_2();
            break;
        case 3:
            test_3();
            break;
        case 4:
            test_4();
            break;
        case 5:
            test_5();
            break;
        case 6:
            test_6();
            break;
        case 7:
            test_7();
            break;
        case 8:
            test_8();
            break;
        case 9:
            test_9();
            break;
        case 10:
            test_10();
            break;
        case 11:
            test_11();
            break;
        case 12:
            test_12();
            break;
        case 13:
            test_13();
            break;
        case 14:
            test_14();
            break;
        case 15:
            test_15();
            break;
        case 16:
            test_16();
            break;
        case 17:
            test_17();
            break;
        case 18:
            test_18();
            break;
        case 19:
            test_19();
            break;
        case 20:
            test_20();
            break;
        case 21:
            test_21();
            break;
        case 22:
            test_22();
            break;
        default:
            cout << "Test case number is out of range" << endl;
            break;
    }
}
