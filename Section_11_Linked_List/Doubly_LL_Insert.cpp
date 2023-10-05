#include <iostream>
using namespace std;
class Node
{
    public:
        int data ;
        Node * next , *prev;
};

void Append(Node * &head , int n) // for appending the dynamically created nodes with head and others
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
{   cout << endl;
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
    cout << endl;
    ptr = NULL;
    free(ptr);

}

void Insert(Node * &head, int pos , int x)
{
    Node * ptr = head;
    // if position is 1 , operation on head node
    if(pos == 1)
    {
        ptr -> prev = new Node;
        ptr = ptr-> prev;
        ptr -> data = x;
        ptr-> next = head;
        head = ptr;
        ptr -> prev = NULL;
    }
    // for insertion at somewhere mid and last position 
    else if(pos > 1)
    {   Node* q = NULL;
        for(int i =1 ;i < pos  && ptr!=NULL; i++)
        {   
            q = ptr;
            ptr = ptr-> next;
        }
        Node *temp = q;
        q-> next = new Node;
        q= q->next;
        q-> data = x;
        q-> next = ptr;
        ptr-> prev = q;
        q-> prev = temp;
        temp -> next = q;
        //temp =NULL;
        //free(temp);
    }
    else // for Invalid positions like 0 , -1 and etc
    {
        cout << "Invalid position" << endl;
    }

}

int main()
{   Node * head = new Node;
    int n , pos;
    cout << "Enter the data element of the head node" << endl;
    cin >> head -> data;
    cout << "Enter the number of nodes to be appended" << endl;
    cin >> n;
    head->next = NULL;
    head -> prev = NULL;
    Append(head , n);
    Display(head);
    cout << "Enter the position and data element to be inserted" << endl;
    cin >> pos >> n;
    Insert(head , pos , n);
    Display(head);
    return 0;
}