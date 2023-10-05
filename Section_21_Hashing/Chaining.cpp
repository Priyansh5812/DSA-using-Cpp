#include <iostream>
using namespace std;

class Node 
{
    public:
        int data;
        Node * next;
    static Node * Insert(Node * & head , int x) // Standard Sort_insert Function for Linked List
    {
        
        if(head == NULL)
        {
            head = new Node();
            head -> data = x;
            head -> next =NULL;
            
        }

        else if(head-> data > x)
        {
            Node *t = new Node();
            t->data = x;
            t->next = head;
            head = t;
            
        }
        else
        {
            Node * p = head , * q = p;
            while(p && p->data < x)
            {
                q = p;
                p = p->next;
            }
            Node * t = new Node();
            t->data = x;
            t->next = p;
            q->next = t;
            
        }
        return head;
        
        
    }

    static void Display(Node * head)
    {
        Node * p = head;
        if(p == NULL)
        {
            cout << "NULL";
        }
        else
        {
            while(p)
            {
                cout << p->data << " ";
                p = p-> next;
            }
        }
        
        cout << endl;
    }
    static void Search(Node * head , int x)
    {
        Node * p = head;
        while(p)
        {
            if(p->data == x)
            {
                cout << "value Found" << endl;
                return;
            }
            p = p->next;
        } 
        cout << "Value not Found" << endl;
    }


};

class hashTable
{
  public:
    Node ** arr;
    int size;
    hashTable(int s) : size(s)
    {
        arr = new Node* [size] {NULL};
    }

     Node * Store(int x)
    {
        int result_ind = x%10; // hash Function
        arr[result_ind] = Node :: Insert(arr[result_ind] , x);
        return arr[result_ind];
    } 

    void Search(int x)
    {
        int result_ind = x%10;
        Node :: Search(arr[result_ind] , x);
    } 
};

int main()
{   hashTable h(10);
    int arr[9] = {16 , 12 , 25 , 39 , 6 , 122 , 5 , 68 , 75};
    Node * temp;
    for(int i = 0; i < 10 ;i++)
    {
        temp = h.Store(arr[i]);
    }
    
    for(int i = 0 ;i < h.size ; i++)
    {
        Node :: Display(h.arr[i]);
    }
    
    h.Search(265);
    return 0;
}