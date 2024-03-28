#include <iostream>
#include <math.h>
using std::cout;
using std::endl;
using std::cin;

bool prime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int x;
    cin >> x;
    cout << prime(x);
}
