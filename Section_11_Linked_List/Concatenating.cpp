#include <iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node* next;
};

void Append(Node* &head , int n)
{
    Node* ptr = head;
    for(int i =1 ; i < n ; i++)
    {
        ptr->next = new Node;
        ptr = ptr->next;
        cout << "Enter the data element" << endl;
        cin >> ptr->data;
        ptr->next = NULL;
    }
    ptr = NULL;
    free(ptr);
}

void Display(Node* &head)
{
    Node*ptr = head;
    while(ptr!=NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
    delete ptr;
}
 
void Concat(Node*&head1 , Node*&head2)
{
    Node * ptr = head1;
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr -> next = head2;
    ptr= NULL;
    free(ptr);
}   

int main()
{
    Node * head1 = new Node , *head2 = new Node;
    int n;

   
    cout << "Enter the number of nodes to be created in first Linked List" << endl;
    cin >> n;
    cout << "Enter the data element of head node of first linked List" <<endl;
    cin >> head1-> data;
    head1->next = NULL;
    Append(head1 , n);
  



    cout << "Enter the number of nodes to be created in Second Linked List" << endl;
    cin >> n;
    cout << "Enter the data element of head node of Second linked List" <<endl;
    cin >> head2-> data;
    head2->next = NULL;
    Append(head2 , n);
    


    
    cout << "Displaying First linked List" << endl;
    Display(head1);
    cout << "Displaying Second linked List" << endl;
    Display(head2);
    

    //cout << "Concatenating both the linked lists" << endl;
    Concat(head1 , head2);

    cout << "Dislaying concatenated linked Lists" << endl;
    Display(head1);
    
    
}