#include "dictionary.h"

Dictionary::Dictionary(){
    // Task 1.1: Implement the constructor of Dictionary.
    arraySize = 0;
    dataPairs = nullptr;
}

Dictionary::~Dictionary(){
    // Task 1.2: Implement the destructor of Dictionary.
    // for (int i=0; i<arraySize; i++){ 
    //     delete dataPairs[i];
    // }
    delete [] dataPairs;
}

int Dictionary::find(const string &key) const{
    // Task 1.3: Search a given key from the Dictionary.
    if (arraySize == 0) return NULL_VALUE;
    else{
        for (int i=0; i<arraySize; i++){
            if (dataPairs[i].key == key) return dataPairs[i].value;
        }
    }
    return NULL_VALUE;
}

bool Dictionary::insert(const string &key, int value){
    // Task 1.4: Insert a given pair into the Dictionary.
    for (int i=0; i<arraySize; i++){
        if (dataPairs[i].key == key) return false;
    }
    DataPair* New = new DataPair [arraySize+1];
    for (int i=0; i<arraySize; i++){
        New[i].value = dataPairs[i].value;
        New[i].key = dataPairs[i].key;
    }
    New[arraySize].value = value;
    New[arraySize].key = key;
    arraySize++;

    delete [] dataPairs;
    dataPairs = New;

    return true;
}