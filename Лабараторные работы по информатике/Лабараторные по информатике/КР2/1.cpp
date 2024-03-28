#include <iostream>
using namespace std;
void change_array(int* a, int N){ // Вспомните, как массивы передаются в функцию, и замените вопросительный знак на корректный аргумент.
    for (int i = 0; i < N; i++){
        if(a[i]%2 == 0)
            a[i] = a[i]*2;
        else
            a[i] = a[i] + 2;
    }
}
int main()
{
    int N;
    cin >> N;
    int* a = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    change_array(a, N);
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    delete[] a;
    return 0;
}
