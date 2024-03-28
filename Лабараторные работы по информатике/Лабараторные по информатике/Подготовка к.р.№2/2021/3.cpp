#include <iostream>
using namespace std;

void separate_rgba(unsigned int *data, unsigned int n){
    unsigned int* a = new unsigned int[4*n];
    unsigned int k = 0;
    for(unsigned int i = 0; i < 4; i++){
        for(unsigned int j = i; j < 4*n; j+=4){
            a[k] = data[j];
            k++;
        }
    }
    for(unsigned int i = 0; i < 4*n; i++){
        data[i] = a[i];
    }
    delete [] a;
}
int main()
{
    unsigned int n;
    cin >> n;
    unsigned int* data = new unsigned int[4*n];
    for (unsigned int i = 0; i < 4*n; i++)
        cin >> data[i];
    separate_rgba(data, n);
    for (unsigned int i = 0; i < 4*n; i++)
        cout << data[i] << " ";
    cout << endl;
    delete[] data;
    return 0;
}
