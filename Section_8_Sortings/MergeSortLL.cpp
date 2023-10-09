#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(): data(-1) , next(NULL)
    {}
    Node(int x) : data(x) , next(NULL)
    {}
};

void BuildLL(Node*& head)
{   
    if(!head)
    {
        head = new Node();
        cout << "Enter the data of the head Node" << endl;
        int c;
        cin >> c;
        if(c!= -1)  
            head->data = c;
        else
            return;
    }

    Node* ptr = head;
    while(true)
    {   int c;
        cout << "Enter the data value" << endl;
        cin >> c;
        
        if(c!= -1)
        {
            ptr -> next= new Node(c);
            ptr = ptr->next;
        }
        else
        {
            return;
        }
    }
}

void Display(Node* head)
{   
    Node* ptr = head;
    while(ptr)
    {
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
}

Node* Merge(Node* head1 , Node*head2)
{
    Node* head = new Node(-1);
    Node* temp = head;
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while(ptr1 && ptr2)
    {
        if(ptr1->data < ptr2 -> data)
        {
            temp->next = new Node(ptr1->data);
            temp = temp -> next;
            ptr1 = ptr1 -> next;
        }

        else if(ptr1 -> data > ptr2 -> data)
        {
            temp -> next = new Node(ptr2->data);
            temp = temp->next;
            ptr2 = ptr2 -> next;
        }

        else
        {
            temp->next = new Node(ptr1->data);
            temp = temp -> next;
            ptr1 = ptr1 -> next;
            temp -> next = new Node(ptr2->data);
            temp = temp->next;
            ptr2 = ptr2 -> next;
        }

    }

    while(ptr1)
    {
            temp->next = new Node(ptr1->data);
            temp = temp -> next;
            ptr1 = ptr1 -> next;
    }
    while(ptr2)
    {
            temp -> next = new Node(ptr2->data);
            temp = temp->next;
            ptr2 = ptr2 -> next;        
    }

    return head->next;
}


Node*FindMid(Node * head)
{
    Node* ptr1 = head;
    Node * ptr2 = head -> next;

    while(ptr2 && ptr2->next)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    }
    return ptr1;

}

Node* MergeSort(Node*& head)
{
    if(!head || !head -> next)
    {
        return head;
    }

    Node* mid = FindMid(head);
    Node*ptr1 = head;
    Node*ptr2 = mid->next;
    mid -> next = NULL;
    MergeSort(ptr1);
    MergeSort(ptr2);
    head = Merge(ptr1 , ptr2);
    Display(head); cout << endl;
    return head;
    
}

int main()
{   
    Node* head = NULL;
    BuildLL(head);
    MergeSort(head);
    Display(head);

    return 0;
}