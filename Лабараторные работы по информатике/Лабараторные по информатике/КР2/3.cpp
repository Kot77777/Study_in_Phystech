#include <iostream>
using namespace std;

struct Matrix
{
    int** data;
    int n, m;
};

void init(Matrix *matrix){
    matrix->data = new int*[matrix->n];
    for(unsigned int i = 0; i < matrix->n; i++) {
        matrix->data[i] = new int[matrix->m];
}
}
void clean(Matrix *matrix){
    for(unsigned int i = 0; i < matrix->n; i++) {
        delete[] matrix->data[i];
    }
    delete[] matrix;
}
void expand(Matrix* matrix, int n_minus, int n_plus, int m_minus, int m_plus){
    int new_n = matrix->n + n_minus + n_plus;
    int new_m = matrix->m + m_minus + m_plus;

    int** new_matrix = new int*[new_n];
    for (int i = 0; i < new_n; i++) {
        new_matrix[i] = new int[new_m]();
    }

    for (int i = 0; i < new_n; i++){
        for (int j = 0; j < new_m; j++){
            new_matrix[i][j] = 0;
        }
    }
    for (int i = n_minus; i < (matrix->n + n_minus); i++){
        for (int j = m_minus; j < (matrix->m + m_minus); j++){
            new_matrix[i][j] = matrix->data[i - n_minus][j - m_minus];
        }
    }
    for (int i = 0; i < matrix->n; i++) {
        delete[] matrix->data[i];
    }
    delete[] matrix->data;
    matrix->data = new_matrix;
    matrix->n = new_n;
    matrix->m = new_m;
}

int main()
{
    Matrix matrix;
    cin >> matrix.n >> matrix.m;
    init(&matrix);
    for (int i = 0; i < matrix.n; i++)
        for (int j = 0; j < matrix.m; j++)
            cin >> matrix.data[i][j];

    int n_minus, n_plus, m_minus, m_plus;
    cin >> n_minus >> n_plus >> m_minus >> m_plus;

    expand(&matrix, n_minus, n_plus, m_minus, m_plus);

    for (int i = 0; i < matrix.n; i++)
    {
        for (int j = 0; j < matrix.m; j++)
            cout << matrix.data[i][j];
        cout << endl;
    }

    clean(&matrix);
    return 0;
}
