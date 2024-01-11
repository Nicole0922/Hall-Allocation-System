#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "mainInteractive.h"
#include "BST.h"
#include "HallAllocationSystem.h"
#include "HashTable.h"
#include "Student.h"

using namespace std;

vector<Student*> readFromFiles(string path) {
    ifstream file{path};
    string line;
    vector<Student*> students;
    while (getline(file, line)) {
        istringstream iss{line};
        int sid, ECA_num, travel_fatest, travel_cheapest;
        string name, major;
        bool is_local, no_hall_before;

        if (iss >> sid >> name >> major >> is_local >> ECA_num >>
            travel_fatest >> travel_cheapest >> no_hall_before) {
            Student* s =
                new Student(sid, name, major, is_local, ECA_num, travel_fatest,
                            travel_cheapest, no_hall_before);
            students.push_back(s);
        }
    }
    return students;
}

void printAction() {
    cout << "Please select an action:" << endl;
    cout << "1. Remove a student from the hall allocation system" << endl;
    cout << "2. Add a student exists in database to the hall allocation system"
         << endl;
    cout << "3. Allocate halls to students" << endl;
    cout << "4. Help a student to accept hall offer" << endl;
    cout << "5. Help a student to reject hall offer" << endl;
    cout << "6. Print all students in the database" << endl;
    cout << "7. Print all students in the hall allocation system" << endl;
    cout << "8. Help all students in waiting list to accept hall offer" << endl;
    cout << "9. Help all students in waiting list to reject hall offer" << endl;
    cout << "10. Print internal structure of the hall allocation system"
         << endl;
    cout << "11. Help a student predict the hall offer" << endl;
    cout << "12. Quit" << endl;
}

InteractiveMain::InteractiveMain(string path)
    : path{path}, students{readFromFiles(path)} {}

InteractiveMain::~InteractiveMain() {
    for (Student* s : students) {
        delete s;
    }
}

void InteractiveMain::runMain() {
    cout << "Welcome to the HKUST hall allocation system!" << endl;
    cout << "Importing students..." << endl;
    cout << "Import completed. There are " << students.size()
         << " students in the database." << endl;
    cout << "Please enter the number of halls available in the system: "
         << endl;
    int num_halls;
    cin >> num_halls;
    if (num_halls < 0) {
        cout << "Invalid number of halls. Please try again." << endl;
        return;
    }

    HallAllocationSystem* system = new HallAllocationSystem(num_halls);
    for (Student* s : students) {
        system->addStudent(s);
    }
    cout << "All students in the database have been added to the hall "
            "allocation system."
         << endl;
    while (true) {
        printAction();
        int action;
        cin >> action;
        switch (action) {
            case 1: {
                cout << "Please enter the student ID of the student you want "
                        "to remove: "
                     << endl;
                int sid;
                cin >> sid;
                Student* stu = system->getStudentTable()->get(sid);
                if (stu != nullptr) {
                    system->removeStudent(stu);
                    cout << "Student " << sid
                         << " has been removed from the hall allocation system."
                         << endl;
                } else {
                    cout << "Student " << sid
                         << " does not exist in the hall allocation system."
                         << endl;
                }
                break;
            }

            case 2: {
                cout << "Please enter the student ID of the student you want "
                        "to add: "
                     << endl;
                int sid2;
                cin >> sid2;
                Student* stu2 = nullptr;
                for (int i = 0; i < students.size(); i++) {
                    if (students[i]->getSid() == sid2) {
                        stu2 = students[i];
                        break;
                    }
                }
                if (stu2 != nullptr) {
                    system->addStudent(stu2);
                    cout << "Student " << sid2
                         << " has been added to the hall allocation system."
                         << endl;
                } else {
                    cout << "Student " << sid2
                         << " does not exist in the database." << endl;
                }
                break;
            }

            case 3: {
                system->allocateHall();
                cout << "Halls have been allocated to students." << endl;
                break;
            }
            case 4: {
                cout << "Please enter the student ID of the student you want "
                        "to help: "
                     << endl;
                int sid3;
                cin >> sid3;
                Student* stu3 = system->getStudentTable()->get(sid3);
                if (stu3 != nullptr) {
                    system->acceptOffer(stu3);
                    cout << "Student " << sid3
                         << " has accepted the hall offer if the student is "
                            "valid."
                         << endl;
                } else {
                    cout << "Student " << sid3
                         << " does not exist in the hall allocation system."
                         << endl;
                }
                break;
            }

            case 5: {
                cout << "Please enter the student ID of the student you want "
                        "to help: "
                     << endl;
                int sid4;
                cin >> sid4;
                Student* stu4 = system->getStudentTable()->get(sid4);
                if (stu4 != nullptr) {
                    system->rejectOffer(stu4);
                    cout << "Student " << sid4
                         << " has rejected the hall offer if the student "
                            "status is valid."
                         << endl;
                } else {
                    cout << "Student " << sid4
                         << " does not exist in the hall allocation system."
                         << endl;
                }
                break;
            }

            case 6: {
                cout << "Students in the database:" << endl;
                for (int i = 0; i < students.size(); i++) {
                    cout << *(students[i]);
                }
                break;
            }

            case 7: {
                cout << "Students in the hall allocation system:" << endl;
                system->getStudentTable()->printTable();
                break;
            }

            case 8: {
                system->acceptAllOffers();
                cout << "All students in the waiting list have accepted the "
                        "hall offer."
                     << endl;
                break;
            }

            case 9: {
                system->rejectAllOffers();
                cout << "All students in the waiting list have rejected the "
                        "hall offer."
                     << endl;
                break;
            }

            case 10: {
                cout << "Internal structure of the hall allocation system:"
                     << endl;
                cout << "There are total of " << system->getTotalHallAvailable()
                     << " halls available." << endl;
                cout << "The Overall BST (key, length) is ..." << endl;
                system->getStudentQueue()->printTreeOnly();
                cout << "The Hash Table is ..." << endl;
                system->getStudentTable()->printTable();
                break;
            }

            case 12: {
                cout << "Thank you for using the HKUST hall allocation system!"
                     << endl;
                delete system;
                return;
            }

            case 11: {
                cout << "Please enter the student ID of the student you want "
                        "to help: "
                     << endl;
                int sid4;
                cin >> sid4;
                Student* stu4 = system->getStudentTable()->get(sid4);
                if (stu4 != nullptr) {
                    system->predict(stu4);
                    cout << "Student " << sid4 << " is "
                         << (system->predict(stu4) ? "likely" : "NOT likely")
                         << " to get a hall offer if currently in the queue."
                         << endl;
                } else {
                    cout << "Student " << sid4
                         << " does not exist in the hall allocation system."
                         << endl;
                }
                break;
            }
        }
    }
}