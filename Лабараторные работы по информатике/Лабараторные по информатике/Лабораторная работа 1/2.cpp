#include <iostream>

using namespace std;
    unsigned int pow(unsigned int n){
        unsigned int k = 0,l = 1;
        while(n!=0){
        k += (n & 1)*l;
        l*=10;
        n >>= 1;
    }
    return k;
    }
int main()
{
    float n;
    cin >> n;
    cout << (n & 1);
    n >>= 1;
    return 0;
}
