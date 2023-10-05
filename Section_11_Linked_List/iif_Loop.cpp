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



void Rec_Display(Node *Thead)
{
    if(Thead !=NULL)
    {
        cout << Thead ->data << " ";
        Rec_Display(Thead->next);
    }
}

bool ifLoop(Node* thead)
{
    Node *p = NULL, * q = NULL;
     p = q = thead;
     while(p && q)
     {
        p =p-> next;
        q= q->next;
        q = q!=NULL ? q->next : NULL;

     }
     return p==q ? true : false;

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
    Rec_Display(temp);
    temp = head;
    cout << endl;
    cout << ifLoop(temp);
    return 0;

}