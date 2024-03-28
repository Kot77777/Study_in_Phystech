#include <iostream>
using std::cout;
using std::endl;
int main()
{
    int a[4] = {1, 2, 3, 4};
    int* p = a+1;
    cout << *(p+1) << endl;
    cout << (int)(*(p)) << endl;
    cout << (int)(*(p + 7) - *p) << endl;
    return 0;
}
