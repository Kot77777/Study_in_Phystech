#include <iostream>
using namespace std;

struct List{
    struct Node{
        int value;
        Node* next;
    };
    Node* head = NULL;
    Node* ass = NULL;
    Node* len;
};
void pus_back(List* l, int value){
    if(len!=0){
        Node* new_node = new Node;
        new_node->value = value;//эквивалентн *new_node.value = value;
        new_node->next = NULL;
        l->ass->next = new_node;//add to List
        l->ass = new_node;//new node is new ass
        l->len++;
    }
    else{
         Node* new_node = new Node;
        new_node->value = value;//эквивалентн *new_node.value = value;
        new_node->next = NULL;
        l->ass = new_node;//add to List
        l->ass = new_node;//new node is new ass
        l->len++;
    }
}


int main()
{
    List l;
    pus_back(&1, 7);
    pus_back(&1, 3);
    cout << l.head->value << endl;
    cout << l.head->next->value << endl;
    return 0;
}
