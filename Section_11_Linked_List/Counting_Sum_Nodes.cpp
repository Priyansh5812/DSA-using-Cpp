#include <iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node* next;
};



void Append(Node * head , int x)
{
    Node* ptr = head;
    while(ptr->next !=NULL)
    {
        ptr= ptr->next;
    }
    ptr->next = new Node;
    ptr=ptr->next;
    ptr->data = x;
    ptr->next = NULL;
}

void Display(Node * head)
{   cout << "Displaying Linked List" << endl;
    while(head!=NULL)
    {
        cout << head -> data << "   ";
        head = head -> next;
    }
    cout << endl;   
}

int Counting(Node * head)
{   int c = 0;
    while(head!=NULL)
    {
        c++;
        head = head -> next;
    }
    return c;
}

int Sum(Node * head)
{   
    int sum = 0;
    while(head!=NULL)
    {
        sum+= head -> data;
        head = head -> next;
    }
    return sum;
}

int main()
{  Node * head = new Node;
    cout << "Enter the data element of the head node" << endl;
    cin >> head -> data;
    head -> next = NULL;
    int n;
    cout <<"How many nodes you want to append with Head node ?" << endl;
    cin >> n;
    for(int i =1; i <= n ; i++)
    {
        Append(head , i);
    }

    Node * ptr = head;
    Display(ptr);
    ptr = head;
    cout << "Total No. of nodes are  : " << Counting(ptr) << endl;
    ptr = head;
    cout << "Sum of the data elements in the Linked List : " << Sum(ptr) << endl;

    return 0;
}