#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void copy_array_reverse(int n, char *array_source, char *array_destination){
    for (int i = 0; i < n; i++){
        *(array_destination + i) = *(array_source + n - i - 1);
    }
}
int main()
{
    char a[] = {"Hello there."}, b[] = {"General Kenobi..."};
    copy_array_reverse(6, a, b + 4);
    cout << b << endl;
    return 0;
}
