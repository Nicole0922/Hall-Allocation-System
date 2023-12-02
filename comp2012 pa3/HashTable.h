#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#include "LinkedList.h"
#include "Student.h"

class HashTable {
    friend class TestSuite;

   private:
    // Number of cells in the hash table
    int size;

    // The array of storing the values, using separate chaining
    LinkedList* table;

   public:
    HashTable(int size);
    ~HashTable();
    void add(Student* student);
    Student* get(int sid) const;
    void remove(const Student* student);
    void printTable() const;
    static int hash(int sid);
};
#endif