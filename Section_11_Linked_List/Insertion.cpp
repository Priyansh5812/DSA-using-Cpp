#include <iostream>
using namespace std;
class Node
{   public:
        int data;
        Node* next;
};
Node* head;

void Append(Node* head , int n)
{
    Node * ptr = head;
    for(int i =0;i < n-1 ; i++)
        {
         ptr->next = new Node;
         ptr=ptr->next;
         cout << "Enter the data node" << endl;
         cin >> ptr->data;
         ptr->next=NULL;
        }
}


void Display(Node* head , int &size)
{
    while(head!=NULL)
    {
        cout << head->data << " ";
        head=head-> next;
        size++;
    }

    
}

void Imp_Search(Node* ptr , int x)
{   
   Node*q = ptr;
   while(ptr!=NULL)
   {
         if(ptr->data == x)
        {
            q->next = ptr->next;
            ptr->next = head;
            head = ptr;

        }
        q = ptr;
        ptr = ptr-> next;
   }
}

void Bef_ins(Node* ptr , int pos, int x, int size)
{   Node * q = NULL;
    if(pos == 1)
    {
        q = new Node;
        q ->data = x;
        q->next = head;
        head = q;
        cout << "Insertion at the beggining" << endl;
    }
    else if(pos == size)
    {
        while(ptr->next !=NULL)
        {
            ptr=ptr->next;
        }
        q = new Node;
        q->data = x;
        q->next = NULL;
        ptr->next = q;
        cout << "Insertion at the end" << endl;
    }
    else if(pos < size && pos > 1)
    {
        for(int i =1;i < pos ; i++)
        {
            q = ptr;
            ptr = ptr->next;
        }
        q->next =new Node;
        q = q->next;
        q->data = x;
        q->next = ptr;
        cout << "Insertion at the middle" << endl;
    }
    else
    {
        cout << "Invalid position" << endl;
    }
    

}

int main()
{   
    Node *ptr;
    int n , size = 1;
    cout << "Enter the how many nodes you want to create" << endl;
    cin >> n;
    head = new Node;
    cout << "Enter the data of the head node" << endl;
    cin >> head -> data;
    head -> next = NULL;
    ptr = head;
    Append(ptr , n);
    ptr = head;
    Display(ptr , size);
    int e;
    cout << "Enter the position and data element of the new Node" << endl;
    cin >> e >> n;
    ptr =head;
    Bef_ins(ptr , e , n , size);
    ptr = head;
    Display(ptr , size);
    return 0;
}

// Insertion at the beggining ✔
// Insertion at the middle ✔
// Insertion at the end ✔