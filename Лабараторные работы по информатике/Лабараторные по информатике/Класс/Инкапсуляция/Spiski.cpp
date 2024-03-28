#include <iostream>
#include <string>
using namespace std;

class List
{
public:
    List();
    ~List();

    void push_back(int data);
    int pop_back();
    void push_front(int data);
    int pop_front();
    void clear();
    int GetSize(){return Size;}
private:

    class Node
    {
    public:
        Node* pNext;
        int data;

        Node(int data, Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node* head;

};

List::List()
{
    Size = 0;
    head = nullptr;
}

List::~List()
{

}

void List::push_back(int data)
{
    if(head == nullptr)
    {
        head = new Node(data);
    }
    else
    {
        Node* current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node(data);
    }

    Size++;
}
int List::pop_back()
{
    if(head->pNext == nullptr)
    {
        int p = head->data;
        this->head = nullptr;
        Size--;
        return p;
    }
    Node* current = this->head;
    while(current->pNext->pNext != nullptr)
    {
        current = current->pNext;
    }
    int k = current->pNext->data;
    delete current->pNext;
    current->pNext = nullptr;
    Size--;
    return k;
}
void List::push_front(int data)
{
    Node* current = new Node(head->data, head->pNext);
    head = new Node(data, current);
    Size++;
}
int List::pop_front()
{
    if(head->pNext == nullptr)
    {
        int p = head->data;
        delete head;
        Size--;
        return p;
    }
    Node* current = this->head;
    head = new Node(head->pNext->data, head->pNext);
    int l = current->data;
    delete current;
    Size--;
    return l;
}
void List::clear()
{
    while(this->head != nullptr)
    {
        int k = pop_back();
    }
    Size = 0;
}
int main(){
    List lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(22);
    lst.push_back(10);
    lst.push_front(90);
    lst.push_front(100);

    /*cout << lst.GetSize() << endl;
    cout << lst.pop_back() << endl;
    cout << lst.GetSize() << endl;
    cout << endl;

    cout << lst.GetSize() << endl;
    cout << lst.pop_back() << endl;
    cout << lst.GetSize() << endl;
    cout << endl;

    cout << lst.GetSize() << endl;
    cout << lst.pop_back() << endl;
    cout << lst.GetSize() << endl;
    cout << endl;

    cout << lst.GetSize() << endl;
    cout << lst.pop_back() << endl;
    cout << lst.GetSize() << endl;
    cout << endl;

    cout << lst.GetSize() << endl;
    cout << lst.pop_back() << endl;
    cout << lst.GetSize() << endl;
    cout << endl;*/

    cout << lst.pop_front() << endl;
    cout << lst.pop_front() << endl;
    cout << lst.GetSize() << endl;
    lst.clear();
    cout << lst.GetSize() << endl;
    lst.push_back(5);
    cout << lst.GetSize() << endl;
    lst.push_back(10);
    cout << lst.GetSize() << endl;
    cout << lst.pop_front() << endl;
    cout << lst.GetSize() << endl;
    return 0;
}
