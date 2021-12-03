#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <iomanip>
#include <chrono>
#include <cmath>
#include <algorithm>
using namespace std::chrono;
using namespace std;
using std::setprecision;
void generateFiles(int input);

int files_num = 10;
float input_nums[] = {10, 100, 1000, 10000, 100000};
float* arr_ptr = input_nums;
const int FLOAT_MIN = -100;
const int FLOAT_MAX = 100;

int main(int argc, char **argv) {
    for(int i = 0; i < 5; i++) {
        generateFiles(input_nums[i]);
    }
    return 0;
}

void generateFiles(int input) {
    for(int i = 0; i < 10; i++){
        string my_file = "input" +std::to_string(input) + "_" + std::to_string(i+1) + ".txt";
                ofstream myfile(my_file);
                if (myfile.is_open())
                {
                    std::random_device rd;
                    std::default_random_engine eng(rd());
                    std::uniform_real_distribution<> distr(FLOAT_MIN, FLOAT_MAX);

                    for(int i = 0; i < input; i++) {
                        myfile << setprecision(10) << distr(eng) << " " ;
                    }
                    myfile.close();
                }
                else cout << "Unable to open file";
    }
}
