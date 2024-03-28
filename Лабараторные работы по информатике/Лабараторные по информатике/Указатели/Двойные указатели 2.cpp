#include <iostream>
using namespace std;
int** transpose(int** matrix, unsigned int N, unsigned int M){
    int** matrix2;
    matrix2 = new int*[M];
    for(unsigned int i = 0; i < M; i++) {
        matrix2[i] = new int[N];
        for(unsigned int j = 0; j < N; j++) {
            matrix2[i][j] = matrix[j][i];
        }
    }
    return matrix2;}
int main()
{
    int** matrix;
    unsigned int N, M;
    cin >> N >> M;
    matrix = new int*[N];
    for(unsigned int i = 0; i < N; i++) {
        matrix[i] = new int[M];
        for(unsigned int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
    for(unsigned int i = 0; i < N; i++) {
        for(unsigned int j = 0; j < M; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    for(unsigned int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
