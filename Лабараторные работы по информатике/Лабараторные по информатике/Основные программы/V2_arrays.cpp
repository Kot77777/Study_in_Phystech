#include <iostream>
using namespace std;
int main()
{
    int n[100][100];
    int lenx;
    int leny;
    cin >> lenx;
    cin >> leny;


    for (int i = 0; i < lenx; i++){
        for (int j = 0; j < leny; j++){
            cin >> n[i][j];
        }
    }

    for (int i = 0; i < lenx; i++){
        for (int j = 0; j < leny; j++){
            cout << n[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
