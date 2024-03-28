#include <iostream>
#include <math.h>
using namespace std;

void printArray(int* arr, int len){
    int i;
    for (i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void CombSort(int* arr, int len){
    double n = 1.2473309;
    int dif = len - 1;
    while(dif >= 1){
        for (int i = 0; i + dif < len; i++){
            if (arr[i] > arr[i + dif]){
                swap(arr[i], arr[i + dif]);
            }
        }
        dif /= n;
    }
}

int binSearch(int x, int* array, int n) {
    int begin = 0;
    int finish = n;

    while (n != 0) {
        int array1[1000];
        for (int begin1 = begin; begin1 < finish; begin1++) {
            array1[begin1] = array[begin1];
        }
        if (array1[n / 2 + 1] == x) {
            return n / 2 + 1;
        }
        else if (array1[n / 2 + 1] > x) {
            finish = n / 2;
            n /= 2;
        }
        else if (array1[n / 2 + 1] < x) {
            begin = n / 2 + 1;
            n /= 2 + 1;
        }
    }
    return -1;
}

bool isPrime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int decimalToBinary(int decimal) {
    int binary = 0, base = 1;
    while (decimal > 0) {
        binary += (decimal % 2) * base;
        decimal /= 2;
        base *= 10;
    }
    return binary;
}

int findMaxIndex(int* arr, int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    return 0;
}
