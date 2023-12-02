#include <iostream>
#include "Student.h"

using namespace std;

// TODO: Task 1.1
Student::Student(int sid,
                 const string& name,
                 const string& major,
                 bool isLocal,
                 int ECANum,
                 int travelFastest,
                 int travelCheapest,
                 bool isFirstApplication) {
                    this->sid = sid;
                    this->name = name;
                    this->major = major;
                    this->isLocal = isLocal;
                    this->ECANum = ECANum;
                    this->travelFastest = travelFastest;
                    this->travelCheapest = travelCheapest;
                    this->isFirstApplication = isFirstApplication;

                    // int check = 0;
                    // if (isFirstApplication == true) check = 1;
                    // else check = 0;

                    if (isLocal == true){
                        totalHallPoints = (travelCheapest + travelFastest)/4 + ECANum*5 + isFirstApplication*5;
                    }
                    else{
                        totalHallPoints = 15 + isFirstApplication*20 + ECANum*5;
                    }

                    status = QUEUEING;
                 }

// TODO: Task 1.2
bool Student::operator==(int sid) const {
    if (this->sid == sid) return true;
    else return false;
}
