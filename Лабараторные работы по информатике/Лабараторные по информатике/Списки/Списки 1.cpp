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
int pop_forward(Node **l){
    if(*l == NULL){
        return 0;
    }
    else{
    Node* tmp;
    tmp = *l;
    int h = tmp->value;
    *l = (*l)->next;
    delete tmp;
    return h;
    }
}
int pop_back(Node **l){
    if(*l == NULL){
        return 0;
    }
    if((*l)->next == NULL){
        int p = (*l)->value;
        delete *l;
        *l = NULL;
        return p;
    }
    Node* tmp;
    tmp = *l;
    while(tmp->next->next != NULL){
        tmp = tmp->next;
    }
    int k = tmp->next->value;
    delete tmp->next;
    tmp->next = NULL;
    return k;
}
int erase_where(Node **l, unsigned int where){
    if(*l == NULL){
        return 0;
    }
    else{
        if(where == 0){
            return pop_forward(l);
        }
        else{
        unsigned int counter = 0;
        Node* tmp;
        tmp = *l;
        while(counter!=(where-1)){
            tmp = tmp->next;
            counter++;
        }
        unsigned int k = tmp->next->value;
        Node* tmp1 = tmp->next;
        tmp->next = tmp->next->next;
        delete tmp1;
        return k;}
    }
}
void clear(Node  **l){
    while(*l!=NULL){
        int k = pop_back(l);
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
    cout << erase_where(&l, 1);
    clear(&l);
    return 0;
}
