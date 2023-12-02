#ifndef __GENERATE_SUITE_H__
#define __GENERATE_SUITE_H__

#include <fstream>
#include <iostream>
#include <random>
#include <set>
#include <string>

using namespace std;

class GenerateSuite {
   public:
    static void generateRandomData(std::ofstream& file, int size) {
        std::set<int> id_data = std::set<int>();
        random_device rd;
        mt19937 gen(rd());

        uniform_int_distribution<int> dis(1, 1000000);
        uniform_int_distribution<int> name_dist(0, 25);
        uniform_int_distribution<int> major_dist(0, 9);
        uniform_int_distribution<int> bool_dist(0, 1);
        uniform_int_distribution<int> ECA_dist(0, 10);
        uniform_int_distribution<int> travel_dist(0, 100);
        for (int i = 0; i < size; i++) {
            int sid = dis(gen);
            while (id_data.find(sid) != id_data.end()) {
                sid = dis(gen);
            }
            id_data.insert(sid);
            string name = "";
            for (int j = 0; j < 10; j++) {
                name += (char)(name_dist(gen) + 'a');
            }
            string major = "";
            for (int j = 0; j < 4; j++) {
                major += (char)(major_dist(gen) + 'a');
            }
            bool is_local = bool_dist(gen);
            int ECA_num = ECA_dist(gen);
            int travel_fatest = travel_dist(gen);
            int travel_cheapest = travel_dist(gen);
            bool no_hall_before = bool_dist(gen);
            file << sid << " " << name << " " << major << " " << is_local << " "
                 << ECA_num << " " << travel_fatest << " " << travel_cheapest
                 << " " << no_hall_before << endl;
        }
    }
};

#endif