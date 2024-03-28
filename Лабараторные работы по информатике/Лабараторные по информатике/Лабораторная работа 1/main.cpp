#include <iostream>

using namespace std;
void binary(unsigned int n)
{
    if (n != 0){
        binary(n >>= 1);
    }
    if (n!=0)
       cout << (n & 1);
}
union fu{
    float f;
    unsigned int u;
    };
int main()
{
    cout << fixed;
    cout.precision(2);
    fu k;
    k.f = 1;
    for(int i = 0; i < 100; i++){
        k.f *=10;
        cout << k.f << "    ";
        binary(k.u);
        cout << endl;
    }
    return 0;
}
