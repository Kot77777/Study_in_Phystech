#include <iostream>
using namespace std;

int main()
{
    int n;
    unsigned long int a[51];
    cin >> n;
    a[1] = 2;
    a[2] = 3;
    for (int i = 3; i <= n; i++){
        a[i] = a[i-2] + a[i-1];
    }
    for (int i = 0; i <= n; i++){
        cout << a[i] << " ";
    }

    return 0;
}
