#include "streamingMedian.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 

#define TEST_FAIL 1
#define TEST_PASSED 0
#define TEST_EPS 1e-7

int runTest(std::string);

int main(int argc, char** argv);

int runTest(std::string filename) {
    std::ifstream testFile (filename);
    std::string line;
    std::string word;
    streamingMedian<int> sm;
    double expectedMedian;
    int testResult;

    if (testFile.is_open()) {
        // get first line - the sample over which median will be calculated.
        if (!getline(testFile, line)) {
            std::cout << "Malformed File." << std::endl;
            testResult = TEST_FAIL;
        }

        std::stringstream ss(line);
        while (getline(ss, word, ',')) {
            try {
                sm.add_number(std::stoi(word));
            } catch (const std::invalid_argument& ia) {
                std::cout << "Cannot extract number" << ia.what() << std::endl;
                testResult = TEST_FAIL;
                break;
            } catch (const std::out_of_range& oor) {
                std::cout << "Cannot extract number" << oor.what() << std::endl;
                testResult = TEST_FAIL;
                break;
            }
        }

        // get the expected median from the file
        if (!getline(testFile, line)) {
            std::cout << "Malformed File." << std::endl;
        }

        try {
            expectedMedian = std::stod(line);
        } catch (const std::invalid_argument& ia) {
                std::cout << "Cannot extract number" << ia.what() << std::endl;
                testResult = TEST_FAIL;
        } catch (const std::out_of_range& oor) {
                std::cout << "Cannot extract number" << oor.what() << std::endl;
                testResult = TEST_FAIL;
        }

        if (abs(expectedMedian - sm.get_median()) < TEST_EPS) {
            testResult = TEST_PASSED;
        } else {
            testResult = TEST_FAIL;
        }

    } else {
        std::cout << "Unable to open file for test case.";
        testResult = TEST_FAIL;
    }

    testFile.close();

    return testResult;
}


int main(int argc, char** argv)  { 
    if (argc != 2) {
        std::cout << "Please provide filename for the test" << std::endl;
        return TEST_FAIL;
    }
    std::string filename = argv[1];
    std::cout << filename << std::endl;
    int result = runTest(filename);
    if (result == 0) {
        std::cout << "Test Passed." << std::endl;
    } else {
        std::cout << "Test Failed." << std::endl;
    }
    return result;
}
