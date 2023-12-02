#include <iostream>
#include "libCLI11.hpp"
#include "HashTable.h"
#include "LinkedList.h"
#include "Student.h"
#include "mainGenerate.h"
#include "mainInteractive.h"
#include "mainTest.h"

using namespace std;

enum Mode { TEST = 0, MAIN, GENERATE, CANNOT_FIND };

Mode convert(string mode) {
    std::transform(mode.begin(), mode.end(), mode.begin(), ::tolower);
    if (mode == "test") {
        return TEST;
    } else if (mode == "main") {
        return MAIN;
    } else if (mode == "generate") {
        return GENERATE;
    } else {
        return CANNOT_FIND;
    }
}

int main(int argc, char** argv) {
    CLI::App app{"COMP 2012 PA3: Hall Allocation Challenge"};
    string mode = "main";
    string path = "";
    std::pair<string, int> output_path_config = std::pair<string, int>("", 0);
    int test_case = 0;
    CLI::Option* mode_option =
        app.add_option("--mode, -m", mode, "Choose the mode to run the program")
            ->required()
            ->default_str("main");
    CLI::Option* test_case_option = app.add_option(
        "--testcase, -t", test_case, "Choose the test case to run the program");
    CLI::Option* path_option =
        app.add_option("--source, --src, -s", path,
                       "Choose the source txt to run the program");
    CLI::Option* output_option =
        app.add_option("--output, -o", output_path_config,
                       "Choose the output txt and number of record to store "
                       "the generated result");
    path_option->check(CLI::ExistingFile);
    // Put the test case range here
    // test_case_option = test_case_option->check(CLI::Range(1,19));
    output_option->check(CLI::NonexistentPath);

    CLI11_PARSE(app, argc, argv);
    Mode modeEnum = convert(mode);
    if (modeEnum == TEST) {
        TestSuite suite = TestSuite();
        suite.run(test_case);
    } else if (modeEnum == MAIN) {
        if (path == "") {
            cout << "Please specify the source txt" << endl;
            return 0;
        }
        InteractiveMain interactive_main = InteractiveMain(path);
        interactive_main.runMain();
    } else if (modeEnum == GENERATE) {
        if (output_path_config.first == "") {
            cout << "Please specify the output txt" << endl;
            return 0;
        }
        if (output_path_config.second == 0) {
            cout << "Please specify the number of record to store" << endl;
            return 0;
        }

        ofstream output_file = ofstream(output_path_config.first);
        GenerateSuite::generateRandomData(output_file,
                                          output_path_config.second);
    }
    return 0;
}