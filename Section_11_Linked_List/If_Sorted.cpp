#include <iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node * next;
};

Node * head;

void Append(int n)
{   Node* ptr = head;
    for(int i =1 ;i < n ;i++)
    {
        ptr -> next = new Node;
        ptr = ptr-> next;
        cout << "Enter the data element" << endl;
        cin >> ptr-> data;
        ptr-> next = NULL;
    }
    
}

void Display()
{
    Node * ptr = head;
    while(ptr!=NULL)
    {
        cout << ptr -> data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

bool ifSorted()
{
    Node * ptr = head , *q =ptr;
    while(ptr !=NULL)
    {
        if(q-> data > ptr -> data)
        {
            return false;
        }
        q = ptr;
        ptr = ptr -> next;
    }

    return true;
}



int main()
{   int n;
    cout << "Enter how many nodes you want to create" << endl;
    cin >> n;
    head = new Node;
    cout << "Enter the data element of the head Node" << endl;
    cin >> head -> data;
    head -> next = NULL;
    Append(n);
    Display();

    if(ifSorted())
    {
        cout << "Linked List is sorted" << endl;
    }
    else
    {
        cout << "Linked List is not sorted" << endl;
    }

    return 0;
}