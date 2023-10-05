#include <iostream>
using namespace std;
class Node
{
    public: 
     int data;
     Node *next;
     Node()
     {}
};

void Push(Node * &top , int x)
{
    Node * ptr = new Node();
    if(ptr == NULL)
    {
        cout << "Stack Overflow" << endl;
        return;
    }

    ptr -> data = x;
    ptr -> next = top;
    top = ptr;

}
void Pop(Node * &top)
{   if(top == NULL)
    {
        cout << "Stack Underflow" << endl;
        return ;
    }
    Node * ptr = top;
    top = top -> next;
    cout << "Value Deleted successfully " << ptr -> data << endl;
    free(ptr);
}


void Display(Node * & top)
{
    Node * ptr = top;
    while(ptr)
    {
        cout << ptr -> data <<  " ";
        ptr = ptr-> next; 
    }
    cout << endl;
}


int main()
{
    Node * top = NULL;
    Push(top , 5);
    Push(top , 6);
    Push(top , 7);
    Push(top , 8);
    Display(top);
    Pop(top);
    Pop(top);
    Display(top);
    return 0;
}