#include <iostream>
#include "Student.h"

int Student::getSid() const {
    return sid;
}

int Student::getTotalHallPoints() const {
    return totalHallPoints;
}

string Student::getName() const {
    return name;
}

string Student::getMajor() const {
    return major;
}

bool Student::getIsLocal() const {
    return isLocal;
}

int Student::getECANum() const {
    return ECANum;
}

int Student::getTravelFastest() const {
    return travelFastest;
}

int Student::getTravelCheapest() const {
    return travelCheapest;
}

bool Student::getIsFirstApplication() const {
    return isFirstApplication;
}

void Student::setStatus(const HallApplicationStatus status) {
    this->status = status;
}

ostream& operator<<(ostream& os, const Student& s) {
    os << "Student ID: " << s.sid << "\t";
    os << "Total hall point: " << s.totalHallPoints << "\t";
    os << "Status: " << s.status << endl;
    return os;
}

bool Student::operator==(const Student& s) const {
    return sid == s.sid;
}

bool Student::operator<(const Student& s) const {
    return sid < s.sid;
}

HallApplicationStatus Student::getStatus() const {
    return status;
}
