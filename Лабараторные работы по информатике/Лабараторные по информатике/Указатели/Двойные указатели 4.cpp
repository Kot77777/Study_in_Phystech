#include <iostream>
using namespace std;
void doubling(int** arr, unsigned int N){
    int* new_arr = new int[2*N];
    for(unsigned int i = 0; i < N; i++){
        new_arr[i] = *(*(arr)+i);
    }
    delete [] *arr;
    *arr = new_arr;
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int up = 0; up < 5; up++)
    {
        for (int i = 0; i < n; i++)
            a[i] = n - i;
        doubling(&a, n);
        for (int i = 0; i < n; i++)
        {
            if (a[i] != n - i)
            {
                cout << "NOPE" << endl;
                return 0;
            }
        }
        n *= 2;
    }
    delete[] a;
    cout << "YEP" << endl;
    return 0;
}
