#include <iostream>
#include <cmath>
using namespace std;
struct parametres{
    int x;
    int y;
    int d;
};

int main(){
    unsigned int n, m, k;
    cin >> m >> n;
    int** matrix;
    matrix = new int*[n];
    for(unsigned int i = 0; i < n; i++) {
        matrix[i] = new int[m];
        for(unsigned int j = 0; j < m; j++) {
            matrix[i][j] = 0;
        }
    }
    cin >> k;
    parametres* a = new parametres[k];
    for (unsigned int i = 0; i < k; i++){
        cin >> a[i].x >> a[i].y >> a[i].d;
    }
    for(int e = 0; e < k; e++){
        int h = a[e].d;
        if (h==0){
            matrix[a[e].y][a[e].x] = 1;
        }
        else if(h > 0){
        for(int l = 0; l <= h; l++){
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if ((abs(a[e].x - j) <= l) && (abs(a[e].y - i) <= l)){
                        matrix[i][j] = 1;
                    }
                }
            }
        }
        }
    }
    unsigned int counter = 0;
    for(unsigned int i = 0; i < n; i++) {
        for(unsigned int j = 0; j < m; j++) {
            if(matrix[i][j] == 0)
                counter++;
        }
    }
    cout << counter;
    for(unsigned int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] a;
    return 0;
}
