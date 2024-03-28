#include <iostream>
using namespace std;
int search_rec(int x, int* array, int n) {
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



int main()
{
    int n, a[100], x;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < 5; i++)
    {
        cin >> x;
        cout << search_rec(x, a, n) << " ";
    }
    cout << endl;
    return 0;
}