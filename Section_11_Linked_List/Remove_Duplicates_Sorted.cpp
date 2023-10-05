#include <iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node* next;
};


void Append(Node * & head , int n)
{
    Node * ptr = head;
    for(int i = 1 ; i < n ; i++)
    {
        ptr-> next = new Node;
        ptr = ptr-> next;
        cout << "Enter the data element" << endl;
        cin >> ptr -> data ;
        ptr -> next = NULL;
    }

}



void Rem_Dup(Node * &head)
{
    Node * ptr = head , *q = ptr;
    while(ptr!=NULL)
    {
        if(q-> data == ptr -> data)
        {
            q->next = ptr-> next;
            Node * temp = ptr;
            ptr = ptr-> next;
            delete temp;
            continue;
        }
        q = ptr;
        ptr = ptr-> next;
    }
    
    
}

void Display(Node * &head)
{
    Node* ptr = head;
    while(ptr!=NULL)
    {
        cout << ptr-> data << " ";
        ptr = ptr -> next;
    }
    cout << endl;
}



int main()
{   Node* head;
    int n;
    cout << "Enter the no. of nodes to be created" << endl;
    cin >> n;
    head = new Node;
    cout << "Enter the data element of the head node" << endl;
    cin >> head -> data;
    head -> next = NULL;
    Append(head , n);
    Display(head);
    cout << "Removing Duplicates from the Linked List" << endl;
    Rem_Dup(head);
    Display(head);
    return 0;
}