#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <cmath>
#include <algorithm>

using namespace std::chrono;
using namespace std;

void readAndParseFile(float* p);
void writeOutput(float* p);
void quickSort(float* p);
void recQuickSort(float* p, int left, int right);
float medianOfThree(float* p, int left, int right);
void swap(float* p, int dex1, int dex2);
int partitionIt(float* p, int left, int right, double pivot);
void manualSort(float*p, int left, int right);
void printArray(float* p);
void generateFiles(int num_files, int floats);

string in_file_name = "";
string out_file_name = "";
int array_size = 10;
float* arr_ptr;

int main(int argc, char **argv)
{
    in_file_name = argv[1];
    out_file_name = argv[2];
    cout << "Input File Name: " << endl;
    cout << in_file_name << endl;;
    //cin >> in_file_name;
    cout << "Output File Name: " << endl;
    //cin >> out_file_name;
    cout << out_file_name << endl;
    //array_size = 10;
    if(array_size <= 0) {
        cout << "Invalid Size" << endl;
        exit(0);
    }

    float arr[array_size];
    arr_ptr = arr;
    
    auto start = high_resolution_clock::now();
    
    readAndParseFile(arr_ptr);
    cout << "Unsorted Array: " << endl;
    printArray(arr_ptr);
    quickSort(arr_ptr);
    writeOutput(arr_ptr);
    cout << "Sorted Array: " << endl;
    printArray(arr_ptr);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop-start);
    cout << "Execution Time: " << duration.count() << " milliseconds" << endl;
    return 0;
}

void readAndParseFile(float* p) {
    fstream newFile;
    string str;
    newFile.open(in_file_name,ios::in);
    if(newFile.is_open())
    {
        getline(newFile, str);
        newFile.close();
    }

    string delimiter = " ";
    size_t pos = 0;
    string token;
    int index = 0;
    while((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0,pos);
        float token_float = stof(token);
        p[index] = token_float;
        index++;
        str.erase(0, pos + delimiter.length());
    }
}

void writeOutput(float* p) {
    ofstream myfile (out_file_name);
    if (myfile.is_open())
    {
        for(int i = 0; i < array_size; i++){
            myfile << p[i] << " " ;
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

void quickSort(float* p) {
    recQuickSort(p, 0, array_size-1);
}

void recQuickSort(float* p, int left, int right) {
    int size = right - left + 1;
    if(size <= 3)
        manualSort(p, left, right);
    else {
        double median = medianOfThree(p, left, right);
        int partition = partitionIt(p, left, right, median);
        recQuickSort(p, left, partition-1);
        recQuickSort(p, partition+1, right);
    }
}

float medianOfThree(float* p, int left, int right) {
    int center = round((left + right) / 2);
    if(p[left] > p[center]){
        swap(p, left, center);
    }
    if(p[left] > p[right]) {
        swap(p, left, right);
    }
    if(p[center] > p[right]) {
        swap(p, center, right);
    }
    swap(p, center, right-1);
    return p[right-1];
}

void swap(float* p, int dex1, int dex2) {
    float temp = p[dex1];
    p[dex1] = p[dex2];
    p[dex2] = temp;
}

int partitionIt(float* p, int left, int right, double pivot) {
    int leftPtr = left;
    int rightPtr = right-1;
    while(true) {
        while(p[++leftPtr] < pivot)
            ;
        while(p[--rightPtr] > pivot)
            ;
        if(leftPtr >= rightPtr)
            break;
        else
            swap(p, leftPtr, rightPtr);
    }
    swap(p, leftPtr, right-1);
    return leftPtr;
}

void manualSort(float*p, int left, int right) {
    int size = right - left + 1;
    if(size <= 1)
        return;
    if(size == 2) {
        if(p[left] > p[right])
            swap(p, left, right);
        return;
    }
    else {
        if(p[left] > p[right-1])
            swap(p, left, right);
        if(p[left] > p[right])
            swap(p, left, right);
        if(p[right-1] > p[right])
            swap(p, right-1, right);
    }
}

void printArray(float* p) {
    for(int i = 0; i < array_size; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

void generateFiles(int num_files, int floats) {

}




