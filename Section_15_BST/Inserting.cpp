#include <iostream>
#include <queue>
using namespace std;

/*
Search for element
if found, no need of Insertion.
if not found, Insert
*/


class Node
{
    public:
        int data;
        Node* left;
        Node* right;
        Node()
        {
            data = 0;
            left = right = NULL;
        }
        Node(int x)
        {
            data = x;
            left = right = NULL;
        }
};


void BuildTree(Node* root)
{
    if(root -> data == -1)
    {   
        cout << "Enter the data for the root Node" << endl;
        cin >> root ->data ;
    }

    
    int t;
    cout << "Enter the value of left Node of " << root -> data << endl;
    cin >> t;
    if(t != -1)
    {
        root -> left = new Node();
        root -> left -> data = t;
        BuildTree(root -> left);
    }
    
    cout << "Enter the value of right Node of " << root -> data << endl;
    cin >> t;
    if(t != -1)
    {
        root -> right = new Node();
        root -> right -> data = t;
        BuildTree(root -> right);
    }

   

}
void LevelOrderTraversal_Beautiful(Node* root)
{
    queue <Node*> q;
    if(!root)
        return;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node * temp = q.front();
        q.pop();

        if(q.size() == 0)
        {
            break;
        }

        if(temp == NULL)
        {   
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp -> data << " ";
        if(temp->left)
        {
            q.push(temp->left);
            
        }

        if(temp -> right)
        {
            q.push(temp->right);
            
        }
        }
    }
}

void Insert_Itr(Node* head , int x)
{
    Node* t = NULL;
    while(head)
    {
        t = head;

        if(head->data < x)
        {
            head = head -> right;
        }
        else if(head -> data > x)
        {
            head = head -> left;
        }
        else
        {   
            cout << "value already present" << endl;
            return;
        }
    }
    
    if(t -> data < x)
    {
        t -> right = new Node(x);
    }
    else
    {
        t->left = new Node(x);
    }
}

void Insert_Rec(Node* head , Node* t , int x)
{
    if(!head)
    {
            if(t)
            {
                if(t->data < x)
                {
                    t -> right = new Node(x);
                }
                else
                {
                    t -> left = new Node(x);
                }
            }
            else
            {
                head = new Node(x);
            }
    }
    else
    {
        if(head->data < x)
        {
            Insert_Rec(head->right , head , x);
        }
        else if(head -> data > x)
        {
            Insert_Rec(head->left , head , x);
        }
        else
        {   
            cout << "Value already Present" << endl;
            return;
        }
    }

}

int main()
{   
    Node * root = new Node(-1);
    BuildTree(root);
    LevelOrderTraversal_Beautiful(root);
    cout << endl;
    
    //30 15 10 -1 -1 20 -1 -1 50 40 -1 -1 60 -1 -1
    //30 15 10 -1 -1 20 19 -1 50 40 -1 -1 60 -1 -1
}