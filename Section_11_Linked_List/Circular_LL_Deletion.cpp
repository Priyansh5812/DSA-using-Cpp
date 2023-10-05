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

void Delete(Node * & head , int x)
{
    Node*ptr = head , *q = NULL;
    if(head-> data == x)
    {  Node * t = NULL;
        t = head;
        head  = head->next;
        while(ptr->next!=t)
        {
            ptr = ptr->next;
        }
        ptr ->next = head;
        t = NULL;
        free(t);

    }
    
    else
    {   
        q = ptr;
        ptr = ptr->next;
        while(ptr!=head)
        {
            if(ptr-> data == x)
            {
                q->next = ptr->next;
                Node* temp = ptr;
                ptr = ptr->next;
                temp -> data = 0;
                free(temp);
            }
            q = ptr;
            ptr=ptr->next;
        }
    }   


}

void Insert(Node* &head , int pos , int x)
{
    Node * ptr = head  , *q = NULL;

    if(pos == 1)
    {
        q= new Node ;
        q-> data = x;
        q-> next = head;
        head = q;
        while(ptr->next!= head-> next)
        {
            ptr = ptr-> next;
        }
        ptr->next = head;
    }
    else
    {
        for(int i =1 ;i < pos ; i++)
        {
            q = ptr;
            ptr = ptr -> next;
        }
        q-> next = new Node;
        q = q->next;
        q-> data = x;
        q->next = ptr;  
    }
    
    q = NULL;
    ptr = NULL;
    free(q);
    free(ptr);
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
    int n , pos;
    cout << "Enter the data element of the head node" << endl;
    cin >> head -> data;
    head->next = head;
    cout << "Enter the number of nodes to be appended" << endl;
    cin >> n;
    Append(head , n);
    Display(head);
    cout << "Enter the data element to be removed" << endl;
    cin >> n ;
    Delete(head, n);
    Display(head);
    return 0;
}