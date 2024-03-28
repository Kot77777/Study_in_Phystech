#include <iostream>

using namespace std;

int main()
{
    int f[1000];
    int n, m, k = -1, total = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> f[i];
    }
    while (((k+1)!=(n-1)) && (k!=(n-1))){
        if (f[k+1] <= f[k+2]){
            total+=f[k+1];
            k+=1;
        }
        else{
            total+=f[k+2];
            k+=2;
        }
    }
    cout << total;
    return 0;
}
