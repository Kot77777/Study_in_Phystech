#include <iostream>
using std::cout;
using std::cin;
using std::endl;
struct sr{
    unsigned int index;
    float value;
};
void bump_sort(sr* sr_zn, unsigned int n){
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = i+1; j < n; j++){
            if (sr_zn[i].value > (sr_zn[j].value + 0.1)){
                sr* k = new sr;
                *k = (sr_zn[j]);
                sr_zn[j] = sr_zn[i];
                sr_zn[i] = *k;
                delete[] k;
            }
        }
    }

}
void sort_errors(unsigned int** errors, unsigned int n, unsigned int m){
    sr* sr_zn = new sr[n];
    float total = 0;
    for(unsigned int i = 0; i < n; i++){
        sr_zn[i].index = i;
        for(unsigned int j = 0; j < m; j++){
            total+=errors[i][j];
        }
        sr_zn[i].value = (total/m);
        total = 0;
    }
    bump_sort(sr_zn, n);
    unsigned int** data1 = new unsigned int*[n];
    for (unsigned int i = 0; i < n; i++){
        data1[i] = errors[sr_zn[i].index];
    }
    for (unsigned int i = 0; i < n; i++){
        errors[i] = data1[i];
    }
    delete[] sr_zn;
    delete[] data1;

}
int main()
{
    unsigned int n, m;
    cin >> n >> m;
    unsigned int** data = new unsigned int*[n];
    for (unsigned int i = 0; i < n; i++)
        data[i] = new unsigned int[m];
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = 0; j < m; j++)
            cin >> data[i][j];
    sort_errors(data, n, m);
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < m; j++)
           cout << data[i][j] << " ";
        cout << endl;
    }
    for (unsigned int i = 0; i < n; i++)
        delete[] data[i];
    delete[] data;
    return 0;
}
