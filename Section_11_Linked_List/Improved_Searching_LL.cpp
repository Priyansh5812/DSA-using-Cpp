#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

};
Node* head;
void Append(Node* head , int n)
{
    Node * ptr = head;
    for(int i =0;i < n-1 ; i++)
        {
         ptr->next = new Node;
         ptr=ptr->next;
         cout << "Enter the data node" << endl;
         cin >> ptr->data;
         ptr->next=NULL;
        }
}


void Display(Node* head)
{
    while(head!=NULL)
    {
        cout << head->data << " ";
        head=head-> next;
    }

    
}

void Imp_Search(Node* ptr , int x)
{   
   Node*q = ptr;
   while(ptr!=NULL)
   {
         if(ptr->data == x)
        {
            q->next = ptr->next;
            ptr->next = head;
            head = ptr;

        }
        q = ptr;
        ptr = ptr-> next;
   }
}


int main()
{
    Node *ptr;
    int n;
    cout << "Enter the how many nodes you want to create" << endl;
    cin >> n;
    head = new Node;
    cout << "Enter the data of the head node" << endl;
    cin >> head -> data;
    head -> next = NULL;
    ptr = head;
    Append(ptr , n);
    ptr = head;
    Display(ptr);
    ptr = head;
    cout << "Enter a data element to be searched" << endl;
    cin >> n;
    ptr = head;
    Imp_Search(ptr , n);
    ptr = head;
    Display(ptr);
    return 0;
}

// Make the head node global but ut is not worth it due to privacy issues