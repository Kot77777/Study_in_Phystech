#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
using namespace std;
void Bump(int* masiv, int n){
    for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if (masiv[i] > masiv[j]){
                    int k = masiv[j];
                    masiv[j] = masiv[i];
                    masiv[i] = k;
                }
            }
        }
}
void Vstavka(int* masiv1, int n, int* sort_masiv){
    sort_masiv[0] = masiv1[0];
        for(int i = 1; i < n; i++){
            sort_masiv[i] = masiv1[i];
            for(int j = i; j > 0; j--){
                if (sort_masiv[j] < sort_masiv[j-1]){
                    int k = sort_masiv[j];
                    sort_masiv[j] = sort_masiv[j-1];
                    sort_masiv[j-1] = k;
                }
                else{
                    break;
                }
            }
        }
}
void Sheiker(int* masiv2, int n){
        int l = 0;
        while (l != (n-1)/2){
            for (int i = l; i < (n-l-1); i++){
                if (masiv2[i] > masiv2[i+1]){
                    int k = masiv2[i+1];
                    masiv2[i+1] = masiv2[i];
                    masiv2[i] = k;
                }
            }
            for (int j = (n-l)-2; j >= l; j--){
                if (masiv2[j] < masiv2[j-1]){
                    int p = masiv2[j-1];
                    masiv2[j-1] = masiv2[j];
                    masiv2[j] = p;
                }
            }
            l+=1;}}
int main()
{
    int n;
    srand(time(NULL));

    //Сортировка пузырьком
    int masiv[10000], masiv_ob[10000], time11[10000], time12[10000], time13[10000], time_st = 0, time_end = 0, r = 0;
    for (int n = 1000; n < 10001; n+=100){
        for(int j = 0; j < n; j++){
            int num =  rand()%90+10;
            masiv[j] = num;
        }
    }

    //Сортировка вставкой
    int masiv1[10000], sort_masiv[10000], time21[10000],  masiv_ob1[10000], time23[10000], sort1_masiv[10000];
    r = 0;
    for (int n = 1000; n < 10001; n+=100){
        for(int i = 0; i < n; i++){
            int num1 =  rand()%90+10;
            masiv1[i] = num1;
        }
        Vstavka(masiv1, n, sort_masiv);
        for (int i = n-1; i >= 0; i--){
            masiv_ob1[i-n-1] = masiv1[i];
        }
        auto start5 = std::chrono::high_resolution_clock::now();
        Vstavka(masiv_ob1, n, sort1_masiv);
        auto en5 = std::chrono::high_resolution_clock::now();
        auto nsec5 = en5 - start5;
        time23[r] = nsec5.count();
        r+=1;
    }


    //Шейкер
    int masiv2[10000], time3[10000], masiv_ob2[10000];
    r = 0;
    for (int n = 1000; n < 10001; n+=100){
        for(int i = 0; i < n; i++){
            int num1 =  rand()%90+10;
            masiv2[i] = num1;
        }
        Sheiker(masiv2, n);
        for (int i = n-1; i >= 0; i--){
            masiv_ob2[i-n-1] = masiv2[i];
        }
        auto start = std::chrono::high_resolution_clock::now();
        Sheiker(masiv_ob2, n);
        auto en = std::chrono::high_resolution_clock::now();
        auto nsec = en - start;
        time3[r] = nsec.count();
        r+=1;}
        for(int i = 0; i <= r-1; i++){
        cout << time3[i] << ", ";}
    return 0;
}
