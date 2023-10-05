#include <iostream>
using namespace std;
class Node
{   public:
        int data;
        Node * next , *prev;
        Node()
        {}

};

void Append(Node * &head , int size)
{   Node * ptr =head;
     if(size == 1)
     {
        ptr-> next = new Node();
        ptr=ptr-> next;
        ptr-> next = NULL;
        ptr-> prev = head;
        cout << "Enter the data element in the node" << endl;
        cin >> ptr -> data;
     }
     else if(size > 1)
     {
        Node * temp = NULL;
        for(int i =0;i < size;i++)
        {
            ptr -> next =new Node();
            temp = ptr;
            ptr = ptr-> next;
            ptr -> prev = temp;
            ptr -> next = NULL;
            cout << "Enter the data element in the node" << endl;
            cin >> ptr -> data;  
        }
     }
     else
     {
        cout << "Invalid Size" << endl;
     }
}


void Display(Node* & head)
{
    Node* ptr = head;
    while(ptr)
    {
        cout <<ptr-> data << " ";
        ptr = ptr-> next;
    }
    cout << endl;
}

void Intersect(Node * & head1 , Node* & head2 , int d)
{
    Node* ptr1 = head1;
    Node * ptr2 = head2;
    bool isthere = false;
    while(ptr1)
    {
        if(ptr1-> data == d)
        {
            isthere = true;
            break;
        }
        ptr1 = ptr1-> next;
    }
    if(isthere)
    {
    while(ptr2-> next)
        {
            ptr2 = ptr2 -> next;
        }
    ptr2 -> next = ptr1;
    cout << "Intersected Linked List :"<< endl;
    Display(head2);
    Display(head1);
    }
    else
    {
        cout << "Data element not found for intersection" << endl;
    }
}

void isIntersect(Node* & head1 , Node* & head2)
{
    Node* ptr1 = head1;
    Node * ptr2 = head2;
    while(ptr1-> next || ptr2 -> next)
    {
        if(ptr1-> next)
        {
            ptr1 = ptr1-> next;
        }

        if(ptr2-> next)
        {
            ptr2 = ptr2-> next;
        }
    }

    Node* temp = ptr2;
    while(ptr1-> prev!= NULL || ptr2-> prev != NULL)
    {
        if(ptr1-> data != ptr2-> data)
        {
            cout << "Intersected Node is " << temp << " with the data element " << temp -> data << endl;
            return;
        }
        else
        {   cout << "ptr1 "<< ptr1-> data << endl <<"ptr2 " << ptr2-> data << endl;
            temp = ptr2;
            
        }
        ptr1 = ptr1-> prev;
        ptr2 = ptr2-> prev;
    }
    cout <<"No Intersection found" << endl;
    
    
}

int main()
{   Node * head1 = new Node();
    Node * head2 = new Node();
    int s1 , s2 ,d;
    cout << "Enter the data value for the head node in first Linked List" << endl;
    cin >> head1 -> data;
    head1-> next = NULL;
    head1-> prev = NULL;
    cout << "Enter the data value for the head node in Second Linked List" << endl;
    cin >> head2 -> data;
    head2-> next = NULL;
    head2-> prev = NULL;
    cout << "Enter the no. of nodes you want to append in first Linked List" << endl;
    cin >> s1;
    cout << "Enter the no. of nodes you want to append in Second Lined List" << endl;
    cin >> s2;
    cout <<"For the First Linked List" << endl;
    Append(head1 , s1);
    s1++;
    cout <<"For the Second Linked List" << endl;
    Append(head2 , s2);
    s2++;
    cout << "First Linked List" << endl;
    Display(head1);
    cout << "Second Linked List" << endl;
    Display(head2);
    cout << "Enter the data element of from first Linked List for intersection" << endl;
    cin >> d;
    Intersect(head1 , head2 , d);
    isIntersect(head1 , head2);
    return 0;
}

// Program is Incorrect nee dto learn Stack first