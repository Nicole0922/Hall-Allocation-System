#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <iostream>
#include <string>

using namespace std;

enum HallApplicationStatus { QUEUEING = 0, PENDING_ACTION, ACCEPTED, REJECTED };

class Student {
   private:
    int sid;
    string name;
    string major;
    bool isLocal;
    int ECANum;
    int travelFastest;
    int travelCheapest;
    bool isFirstApplication;
    int totalHallPoints;
    HallApplicationStatus status;

   public:
    Student(int sid,
            const string& name,
            const string& major,
            bool isLocal,
            int ECANum,
            int travelFastest,
            int travelCheapest,
            bool isFirstApplication);

    int getSid() const;
    int getTotalHallPoints() const;
    string getName() const;
    string getMajor() const;
    bool getIsLocal() const;
    int getECANum() const;
    int getTravelFastest() const;
    int getTravelCheapest() const;
    bool getIsFirstApplication() const;
    HallApplicationStatus getStatus() const;
    void setStatus(const HallApplicationStatus status);
    friend ostream& operator<<(ostream& os, const Student& s);
    bool operator==(int sid) const;
    bool operator==(const Student& s) const;
    bool operator<(const Student& s) const;
};

#endif