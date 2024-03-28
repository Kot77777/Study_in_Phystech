#include <iostream>
using namespace std;

struct subset_node {
    int key;
    subset_node *left;
    subset_node *right;
};
bool init(subset_node **sn){
    *sn = NULL;
    return true;
}
bool insert(subset_node **sn, int k){
    if(*sn==NULL){
        subset_node* new_subset_node = new subset_node;
        new_subset_node->key = k;
        new_subset_node->left = NULL;
        new_subset_node->right = NULL;
        *sn = new_subset_node;
    }
    else{
        if(k == (*sn)->key){
            return false;
        }
        if(k > (*sn)->key){
            insert(&((*sn)->right), k);
            return true;
        }
        if(k < (*sn)->key){
            insert(&((*sn)->left), k);
            return true;
        }
    }
}

int main(){
    subset_node* sn;
    init(&sn);
    insert(&sn, 5);
    insert(&sn, 9);
    insert(&sn, 6);
    insert(&sn, 4);
    cout << sn->left->key << endl;
    cout << sn->key;
    cout << sn->right->key;
    cout << sn->right->left->key;
    return 0;
}
