#include <iostream>
using std::cout;
using std::cin;
using std::endl;
struct Sequence
{
    int size;    // количество чисел
    int* data;   // указатель на начало массива с числами
};
void separate_odd_even(const Sequence* input, Sequence** odd, Sequence** even){
    int k = 0, l = 0;
    for(int i = 0; i < input->size; i++){
        if (input->data[i] % 2 == 0)
            k++;
        else
            l++;
    }
    int* a = new int[k];
    int* b = new int[l];
    int c = 0, d = 0;
    for(int i = 0; i < input->size; i++){
        if (input->data[i] % 2 == 0){
            a[c] = input->data[i];
            c++;
        }
        else{
            b[d] = input->data[i];
            d++;
        }
    }
    Sequence* i = new Sequence;
    i->data = a;
    i->size = k;
    Sequence* j = new Sequence;
    j->data = b;
    j->size = l;
    *even = i;
    *odd = j;
}
void clear(Sequence* s){
    delete[] s->data;
    delete s;
}
int main()
{
    Sequence input;
    cin >> input.size;
    input.data = new int[input.size];
    for (int i = 0; i < input.size; i++)
        cin >> input.data[i];
    Sequence *odd, *even;
    separate_odd_even(&input, &odd, &even);
    for (int i = 0; i < odd->size; i++)
        cout << odd->data[i] << " ";
    cout << endl;
    for (int i = 0; i < even->size; i++)
        cout << even->data[i] << " ";
    cout << endl;
    clear(odd);
    clear(even);
    delete[] input.data;
    return 0;
}
