#include <iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node* next;

};

Node * head ;
void Append(int n)
{
    Node * ptr = head;
    for(int i = 1 ; i < n ; i++)
    {
        ptr -> next = new Node;
        ptr = ptr->next;
        cout << "Enter the data element" << endl;
        cin >> ptr -> data;
        ptr -> next = NULL;
    }
}

void Display()
{   Node * ptr = head;
    while(ptr!=NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void Delete(int x)
{   Node * ptr =NULL , *q = NULL;
    if(head-> data == x)
    {   ptr = head;
        head = head ->next;
        cout << ptr-> data << " Value deleted sucessfully" << endl;
        delete ptr;
        free(ptr);
    }
    else
    {   ptr = head;
        while(ptr!= NULL)
        {
            if(ptr-> data == x)
            {
                q->next = ptr->next;
                cout << ptr-> data << " Value deleted Successfully" << endl;
                delete ptr;
                free(ptr);
                break;
            }
                q= ptr;
                ptr = ptr->next;

        }
    }
}



int main()
{   Node *ptr;
    int n,d;
    cout << "Enter the total no. of nodes to be created" << endl;
    cin >> n;
    head = new Node;
    cout << "Enter the data element of the head node" << endl;
    cin >> head -> data;
    head -> next = NULL;
    Append(n);
    Display();
    cout << "Enter the data element to be deleted" << endl;
    cin >> d;
    Delete(d);
    Display();


}