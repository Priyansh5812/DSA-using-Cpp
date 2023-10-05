#include <iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};


void Append(Node * head , int x)
{
    Node* ptr = head;
    while(ptr -> next !=NULL)
    {
        ptr= ptr-> next;
    }
    ptr -> next = new Node;
    ptr = ptr->next;
    ptr->data =x;
    ptr->next = NULL;
}



void Rec_Display(Node *Thead)
{
    if(Thead !=NULL)
    {
        cout << Thead ->data << " ";
        Rec_Display(Thead->next);
    }
}

int Search(Node* thead , int x)
{
    int pos=0;
    while(thead !=NULL)
    {   pos++;
        if(x == thead -> data)
        {
            return pos;
        }
        thead = thead -> next;
    }
    return pos;
}

int main()
{   int n;
    Node* head = new Node;
    cout << "Enter the data element of the Head node" << endl;
    cin >> head -> data;
    head -> next = NULL;
    cout << "Enter the number of nodes to be appended" << endl;
    cin >> n;
    for(int i =1 ;i <= n ;i++)
    {
        Append(head , i);
    }
    Node * temp = head;
    Rec_Display(temp);
    cout << "Enter the element to be searched" << endl;
    cin >> n;
    n = Search(head  , n);
    if(n == 0)
    {
        cout << "Element not Found" << endl;
    }
    else
    {
        if(n == 1)
        {
            cout << "Data element found at Head Node" << endl;
        }
        else
        {
            cout << "Data element found at " << n << " th Node" << endl;
        }
        
    }
    return 0;

}