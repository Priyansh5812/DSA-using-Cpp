#include <iostream>
using namespace std;
class Node
{
    public:
        int data ;
        Node * next , *prev;
};

void Append(Node * &head , int n)
{
    Node * ptr = head;
    for(int i =0; i < n; i++)
    {   Node * temp = ptr;
        ptr->next = new Node;
        ptr = ptr->next;
        ptr->prev = temp;
        cout << "Enter the data element "<< endl;
        cin >> ptr -> data;
        ptr-> next =NULL;
    }
}

void Display(Node* & head)
{
    Node * ptr = head;
    while(ptr!=NULL)
    {
        cout << ptr -> data <<  " ";
        if(ptr-> next == NULL)
        {
            break;
        }
        ptr = ptr-> next;
    }
    cout <<  endl << "Printing Reverse... " << endl;
    while(ptr !=NULL)
    {
        cout << ptr-> data << " ";
        ptr = ptr-> prev;

    }
    ptr = NULL;
    free(ptr);

}


int main()
{   Node * head = new Node;
    int n;
    cout << "Enter the data element of the head node" << endl;
    cin >> head -> data;
    cout << "Enter the number of nodes to be appended" << endl;
    cin >> n;
    head->next = NULL;
    head -> prev = NULL;
    Append(head , n);
    Display(head);
    return 0;
}