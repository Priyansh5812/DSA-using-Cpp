// find Middle Element of the linked list
#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * next;
        Node()
        {}
};


void Append(Node * &head , int &size)
{
    Node * ptr = head;
    for(int i =0;i < size-1;i++)
    {
        ptr-> next =new Node();
        ptr = ptr-> next;
        cout << "Enter the data element" << endl;
        cin >> ptr -> data;
        ptr->next = NULL;
    }
    
}

void Display(Node * &head)
{   Node* ptr = head;
    while(ptr)
    {
        cout << ptr-> data << " ";
        ptr = ptr-> next;
    }
    cout << endl;
}

void Middle(Node * &head , int &size)
{   Node * ptr = head;
    for(int i= 0; i < size/2; i++)  
    {
        ptr = ptr-> next;
    }

    cout << "Middle data element = " << ptr -> data << endl;
    
}

int main()
{   Node * head = new Node();
    int size = 1;
    cout << "Enter the data element of the head Node" << endl;
    cin >> head -> data;
    head-> next = NULL;
    cout << "Enter no. of nodes to append with head node" << endl;
    cin >> size;
    size++;
    Append(head , size);
    Display(head);
    Middle(head , size);
    Display(head);
    return 0;
}