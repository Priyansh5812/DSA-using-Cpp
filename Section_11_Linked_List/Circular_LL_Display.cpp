#include <iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node* next;
};

void Append(Node *&head , int n)
{
    Node*ptr = head;
    for(int i =1 ; i <= n ; i++)
    {
        ptr -> next = new Node;
        ptr = ptr-> next;
        cout << "Enter the data element of the node " << endl;
        cin >> ptr -> data;
        ptr-> next = head;
    }

}


void Display(Node * &head)
{
    Node* ptr = head;
    if(ptr->next == head)
    {
        cout << head-> data << " ";
        cout << endl;
    }
    else
    {   cout << ptr -> data << " ";
        ptr = ptr-> next;
        while(ptr!=head)
        {
            cout << ptr -> data << " ";
            ptr = ptr-> next;
        }

    }
    ptr = NULL;
    free(ptr);
}
int main()
{
    Node * head = new Node;
    int n;
    cout << "Enter the data element of the head node" << endl;
    cin >> head -> data;
    head->next = head;
    cout << "Enter the number of nodes to be appended" << endl;
    cin >> n;
    Append(head , n);
    Display(head);
}