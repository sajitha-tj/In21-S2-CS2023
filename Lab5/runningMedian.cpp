#include <iostream>
#include <limits.h>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <vector>

using namespace std;


void printArray(vector<int> arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> sort(vector<int> arr, int size) {
    int i = 0;
    while (i < size) {
        int j = i + 1;
        while (j < size) {
            if (arr[i] > arr[j]) {
                int temp_value = arr[i];
                arr[i] = arr[j];
                arr[j] = temp_value;
            }
            j++;
        }
        i++;
    }
    return arr;
}

double GetMedian(vector<int> arr, int n) {
    double median = 0;
    if (n % 2 == 0) {
        median = (arr[n/2] + arr[n/2 - 1]) / 2;
    } else {
        median = arr[n/2];
    }
    return median;
}

int main(){
    vector<int> arr = {7,3,5,2};

    vector<int> newArr;
    
    for(int i = 0; i < 4; i++) {
        newArr.push_back(arr[i]);
        vector<int> sortedArr = sort(newArr, i+1);
        printArray(sortedArr, i+1);
        cout <<"Median: " <<std::fixed << std::setprecision(1)<< GetMedian(sortedArr, i+1) << endl;
    }

    return 0;
}