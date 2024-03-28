#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
using namespace std;

int main()
{
    int n;
    srand(time(NULL));

    //Сортировка пузырьком
    int masiv[10000], time1[10000], time_st = 0, time_end = 0, r = 0;

    for (int n = 1000; n < 10001; n+=100){
        for(int j = 0; j < n; j++){
            int num =  rand()%90+10;
            masiv[j] = num;
        }
        auto start = std::chrono::high_resolution_clock::now();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if (masiv[i] > masiv[j]){
                    int k = masiv[j];
                    masiv[j] = masiv[i];
                    masiv[i] = k;
                }
            }
        }
        auto en = std::chrono::high_resolution_clock::now();
        auto nsec = en - start;
        time1[r] = nsec.count();
        r+=1;
    }
    cout << endl;
    for(int i = 0; i <= r-1; i++){
        cout << time1[i] << ", ";
    }
    return 0;
}
