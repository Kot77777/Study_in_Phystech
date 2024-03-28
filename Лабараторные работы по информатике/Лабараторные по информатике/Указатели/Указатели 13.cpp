#include <iostream>
using namespace std;
int step(int m){
    int l =1;
    for (int i = 0; i < m; i++){
        l*=2;
    }
    return l;
}
int main()
{
    int n;
    int i = 7;
    cout << sizeof(i);
    unsigned long long int v;
    cin >> n;
    v = n*1024;
    cout << v;
    cout << step(i);
    while (step(i-20) < v){
        i+=8;
        cout << 9;
    }
    cout << (i+1)/4;
    return 0;
}
