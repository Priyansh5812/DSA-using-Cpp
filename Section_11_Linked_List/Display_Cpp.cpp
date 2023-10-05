#include <iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};


void Append(Node * head , int x)
{
    Node* ptr = head;
    while(ptr -> next !=NULL)
    {
        ptr= ptr-> next;
    }
    ptr -> next = new Node;
    ptr = ptr->next;
    ptr->data =x;
    ptr->next = NULL;
}

void Display(Node * head)
{
    Node * ptr = head;
    while(ptr!= NULL)
    {
         cout << ptr->data << " ";
        ptr=ptr->next;
    }
    cout << endl;
}

void Rec_Display(struct Node *Thead)
{
    if(Thead !=NULL)
    {
        cout << Thead ->data << " ";
        Rec_Display(Thead->next);
    }
}


int main()
{   int n;
    Node* head = new Node;
    cout << "Enter the data element of the Head node" << endl;
    cin >> head -> data;
    head -> next = NULL;
    cout << "Enter the number of nodes to be appended" << endl;
    cin >> n;
    for(int i =1 ;i <= n ;i++)
    {
        Append(head , i);
    }
    Node * temp = head;
    Display(head);
    Rec_Display(temp);
    return 0;

}