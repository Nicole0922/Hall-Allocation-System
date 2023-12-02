#ifndef __INTERACTIVE_MAIN_H__
#define __INTERACTIVE_MAIN_H__

#include <string>
#include <vector>
#include "Student.h"

class InteractiveMain {
   private:
    string path;
    vector<Student*> students;

   public:
    InteractiveMain(string path);
    void runMain();
    ~InteractiveMain();
};
#endif