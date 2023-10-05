#include <iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node * next;
};

void Append(Node * &head , int n)
{
    Node * ptr = head;
    for(int i =1 ; i < n ; i++)
    {
        ptr -> next = new Node;
        ptr = ptr-> next;
        cout << "Enter the data elemnt of the Node" << endl;
        cin >> ptr -> data ;
        ptr -> next = NULL;
    }
}

void Display(Node *&head)
{
    Node* ptr = head;
        while(ptr != NULL)
        {
            cout << ptr -> data << " ";
            ptr = ptr-> next;
        }
        cout << endl;
}

void Reverse(Node * & head)
{
    Node * ptr = head;
    int i = 0;
    while(ptr != NULL) // calculating the size of Dynamic Array
    {
        ptr = ptr-> next;
        i++;
    }

    int * arr = new int[i+1];
    
    ptr = head;
    i = 0;
    while(ptr != NULL) // For storing the elements in the Dynamic array
    {   arr[i] = ptr-> data;
        ptr = ptr-> next;
        i++;
    }

    ptr = head;
    i--;
    while(ptr!=NULL)
    {
        ptr -> data = arr[i]; // for reversing the elements
        i--;
        ptr = ptr-> next;
    }
    delete [] arr;      // deallocating the array
}


int main()
{   Node* head = new Node;
    int n;
    cout << "Enter the number of nodes to be created" << endl;
    cin >> n;
    cout << "Enter the data element of the head node"<< endl;
    cin >> head -> data;
    head -> next =NULL;
    Append(head , n);
    Display(head);
    Reverse(head);
    Display(head);
    return 0;
}