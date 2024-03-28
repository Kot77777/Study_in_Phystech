#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
};
void init(Node** l){
    *l = NULL;
}
void push_back(Node** l, int value){
    if (*l != NULL){
        Node* new_node = new Node;
        new_node->value = value;
        new_node->next = NULL;
        Node* tmp;
        tmp = *l;
        while(tmp->next!=NULL){
            tmp =  tmp->next;
        }
        tmp->next = new_node;
    }
    else{
        Node* new_node = new Node;
        new_node->value = value;
        new_node->next = NULL;
        *l = new_node;
    }
}
int main () {
    Node* l;
    init(&l);
    push_back(&l, 1);
    push_back(&l, 2);
    push_back(&l, 3);
    cout << l->value<< endl;
    cout << l->next->value;
    cout << l->next->next->value;
    return 0;
}