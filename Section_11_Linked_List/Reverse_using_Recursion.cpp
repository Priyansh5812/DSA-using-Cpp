#include <iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node * next;
};


void Append(Node * &head , int n)
{
    Node * ptr = head;
    for(int i =1 ; i < n ; i++)
    {
        ptr -> next = new Node;
        ptr = ptr-> next;
        cout << "Enter the data elemnt of the Node" << endl;
        cin >> ptr -> data ;
        ptr -> next = NULL;
    }
    ptr = NULL;
    free(ptr);
}


void Reverse(Node * &head , Node * ptr , Node * q)
{
    if(ptr!=NULL)
    {
        Reverse(head , ptr -> next , ptr);
        ptr->next = q;
    } 
    else
    {
        head = q;
    }
    
}

void Display(Node *&head)
{
    Node* ptr = head;
        while(ptr != NULL)
        {
            cout << ptr -> data << " ";
            ptr = ptr-> next;
        }
        cout << endl;
        free(ptr);
}


int main()
{   Node * head  = new Node;
    int n;
    cout << "Enter the no. of nodes to be created" << endl;
    cin >> n;
    cout << "Enter the data element of the head node" << endl;
    cin >> head -> data;
    head -> next = NULL;
    Append(head , n);
    Display(head);
    Reverse(head , head , NULL);
    Display(head);
    return 0;
}