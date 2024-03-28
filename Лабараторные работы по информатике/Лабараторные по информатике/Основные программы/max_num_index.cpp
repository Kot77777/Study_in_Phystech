#include <iostream>
#include <math.h>
using namespace std;

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
