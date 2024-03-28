#include <iostream>
using namespace std;

void printArray(int* arr, int len){ //array's print
    int i;
    for (i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void BubbleSort(int* arr, int len){ //O(n^2)
    for (int i = 0; i < len - 1; i++){
        for (int j = 0; j < len - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void ChoiceSort(int* arr, int len){ //O(n^2)
    for (int i = 0; i < len - 1; i++){
        int min = 10000;
        for (int j = i; j < len; j++){
            if (arr[j] < min){
                min = arr[j];
                swap(arr[j], arr[i]);
            }
        }
    }
}

void PutSort(int* arr, int len){ //O(n^2)
    int sortedArray[100];
    sortedArray[0] = arr[0];
    for (int i = 1; i < len; i++){
        for (int k = i - 1; k >= 0; k--){
            sortedArray[k + 1] = sortedArray[k];
        }
        sortedArray[0] = arr[i];
        for (int j = 0; j < i; j++){
            if (sortedArray[j] > sortedArray[j + 1]){
                swap(sortedArray[j], sortedArray[j + 1]);
            }
        }
    }
    for (int i = 0; i < len; i++){
        arr[i] = sortedArray[i];
    }
}

void CombSort(int* arr, int len){ //O(n log n)
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

int part(int* arr, int left, int right){ //partition for quick sort alg
    int pivot = arr[right];
    int pIndex = left;

    for (int i = left; i < right; i++){
        if (arr[i] <= pivot){
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap (arr[pIndex], arr[right]);
    return pIndex;
}

void QuickSort(int* arr, int left, int right){ //O(n log n)
    if (left >= right){
        return;
    }

    int pivot = part(arr, left, right);
    QuickSort(arr, left, pivot - 1);
    QuickSort(arr, pivot + 1, right);
}


int main()
{
    int arr1[1000], arr2[1000], arr3[1000], arr4[1000], arr5[1000];
    int len;
    cin >> len;

    for (int i = 0; i < len; i++){ //array1 input
        int n;
        cin >> n;
        arr1[i] = n;
    }
    for (int i = 0; i < len; i++){ //array2 input
        int n;
        cin >> n;
        arr2[i] = n;
    }
    for (int i = 0; i < len; i++){ //array3 input
        int n;
        cin >> n;
        arr3[i] = n;
    }
    for (int i = 0; i < len; i++){ //array4 input
        int n;
        cin >> n;
        arr4[i] = n;
    }
    for (int i = 0; i < len; i++){ //array5 input
        int n;
        cin >> n;
        arr5[i] = n;
    }

    BubbleSort(arr1, len);
    printArray(arr1, len);

    ChoiceSort(arr2, len);
    printArray(arr2, len);

    PutSort(arr3, len);
    printArray(arr3, len);

    CombSort(arr4, len);
    printArray(arr4, len);

    QuickSort(arr5, 0, len - 1);
    printArray(arr5, len);
}
