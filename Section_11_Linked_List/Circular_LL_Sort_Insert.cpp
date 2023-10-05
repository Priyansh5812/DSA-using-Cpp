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

void Sort_Ins(Node* & head , int x)
{
    Node * ptr = head , *q = NULL;
    if(head-> data > x)
    {
        q = new Node;
        q-> data = x;
        q->next = head;
        head = q;
        while(ptr-> next !=head->next)
        {
            ptr=ptr->next; 
        }
        ptr->next = head;
        return;
    }
    else
    {
        q = ptr;
        ptr = ptr->next;
        while(ptr!=head)
        {
            if(ptr-> data >= x)
            {
                q->next = new Node;
                q= q->next;
                q-> data = x;
                q->next = ptr;
                return;
            }
            q = ptr;
            ptr= ptr->next;
        }
        
        q->next = new Node;
        q= q->next;
        q-> data = x;
        q->next = ptr;
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
    cout << "Enter the data element to insert" << endl;
    cin >> n;
    Sort_Ins(head , n);
    Display(head);
    
}