#include <iostream>
#include <chrono>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--)
    {

        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void merge(int array[], int const left,
           int const mid, int const right){
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
    auto indexOfSubArrayOne = 0,
         indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne &&
           indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <=
            rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] =
            leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] =
            rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] =
        leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] =
        rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
void mergeSort(int array[],
               int const begin,
               int const end){
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
void combSort(int* arr, int len) {
    int gap = len;
    bool swapped = true;
    int temp;
    while (gap != 1 || swapped) {
        gap *= 10 / 13;
        if (gap < 1) {
            gap = 1;
        }
        cout << ".";
        swapped = false;
        for (int i = 0; i < len - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = true;
            }
        }
    }
}
int main(){
    srand(time(NULL));
    //Сортировка кучей
    int masiv[10000], time1[10000], time_st = 0, time_end = 0, r = 0, masiv_ob1[10000];
    for (int n = 1000; n < 10001; n+=100){
        for(int j = 0; j < n; j++){
            int num =  rand()%90+10;
            masiv[j] = num;
        }
        heapSort(masiv, n);
        for (int i = n-1; i >= 0; i--){
            masiv_ob1[i-n-1] = masiv[i];
        }
        auto start = std::chrono::high_resolution_clock::now();
        heapSort(masiv_ob1, n);
        auto en = std::chrono::high_resolution_clock::now();
        auto nsec = en - start;
        time1[r] = nsec.count();
        r+=1;
    }


    //Сортировка слиянием
    int masiv1[10000], sort_masiv[10000], time2[10000], masiv_ob2[10000];
    r = 0;
    for (int n = 1000; n < 10001; n+=100){
        for(int i = 0; i < n; i++){
            int num1 =  rand()%90+10;
            masiv1[i] = num1;
        }
        mergeSort(masiv1, 0, n-1);
        for (int i = n-1; i >= 0; i--){
            masiv_ob2[i-n-1] = masiv1[i];
        }
        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(masiv_ob2, 0, n-1);
        auto en = std::chrono::high_resolution_clock::now();
        auto nsec = en - start;
        time2[r] = nsec.count();
        r+=1;
    }

    //Сортировка расческой
    int masiv2[10000], time3[10000], masiv_ob3[10000];
    r = 0;
    for (int n = 1000; n < 10001; n+=100){
        for(int i = 0; i < n; i++){
            int num1 =  rand()%90+10;
            masiv2[i] = num1;
        }
        combSort(masiv2, n);
        for (int i = n-1; i >= 0; i--){
            masiv_ob3[i-n-1] = masiv2[i];
        }
        auto start = std::chrono::high_resolution_clock::now();
        combSort(masiv2, n);
        auto en = std::chrono::high_resolution_clock::now();
        auto nsec = en - start;
        time3[r] = nsec.count();
        r+=1;
    }
        for(int i = 0; i <= r-1; i++){
        cout << time3[i] << ", ";
    }

    return 0;
}
