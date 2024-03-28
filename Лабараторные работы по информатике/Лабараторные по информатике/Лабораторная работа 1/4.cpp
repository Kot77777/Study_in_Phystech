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
    float k = 1;
    while(true){
        k++;
        cout << k;
    }
    return 0;
}
