#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    unsigned int n;
    cin >> n;
    float** matrix;
    matrix = new float*[n];
    for(unsigned int i = 0; i < n; i++) {
        matrix[i] = new float[3];
        for(unsigned int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }
    float total = 0;
    for(unsigned int i = 0; i < n-1; i++) {
        if ((((matrix[i][1] - matrix[i+1][1])*(matrix[i][1] - matrix[i+1][1]) + (matrix[i][2] - matrix[i+1][2])*(matrix[i][2] - matrix[i+1][2]))/((matrix[i+1][0] - matrix[i][0])*(matrix[i+1][0] - matrix[i][0]))) <= 108900){
            total += sqrt((matrix[i][1] - matrix[i+1][1])*(matrix[i][1] - matrix[i+1][1]) + (matrix[i][2] - matrix[i+1][2])*(matrix[i][2] - matrix[i+1][2]));
        }
    }
    cout << setprecision(1) << fixed;
    cout << total;
    for(unsigned int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
