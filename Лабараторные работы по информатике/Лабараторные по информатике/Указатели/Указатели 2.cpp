#include <iostream>
using namespace std;

int main(){
    unsigned int u, u2;
    cin >> u >> u2;
    int n = 3;
    int *b = &n;
    unsigned int *p = &u, *p2 = &u2;
    cout << *b;
    cout << *p + *p2;
    return 0;
}
