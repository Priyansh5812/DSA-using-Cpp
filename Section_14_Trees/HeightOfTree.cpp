#include <iostream>
#include <queue>
using namespace std;

class Node
{
    public:
        int data;
        Node* left , *right;
        Node() : data(-1), left(NULL) , right(NULL)
        {}

};

void BuildTree(Node* root)
{   
    if(!root)
    {
        root = new Node();
    }

    if(root->data == -1)
    {
            cout << "Enter the value of the root node" << endl;
            cin >> root -> data;
    }
    int temp;
    cout << "Enter the left node of the " << root -> data << endl;
    cin >> temp;
    if(temp != -1)
    {
    root -> left = new Node();
    root -> left -> data = temp;
    BuildTree(root->left);
    }


    cout << "Enter the right node of the " << root -> data << endl;
    cin >> temp;
    if(temp != -1)
    {
        root -> right = new Node();
        root -> right -> data = temp;
        BuildTree(root->right);
    }

}

void PreOrderTranversal_Rec(Node* root)
{
    if(root)
    {
        cout << root -> data << " ";
        PreOrderTranversal_Rec(root -> left);
        PreOrderTranversal_Rec(root -> right);
    }
}

int GetHeight(Node * root)
{   int c =0;
    if(!root)
    {
        return 0;
    }

    if(!root->left && !root -> right)
    {
        return 1;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node * ptr = q.front();
        q.pop();

        if(!ptr)
        {
            c++;
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {   
            cout << ptr -> data << " ";
            if(ptr ->left){q.push(ptr->left);}
            if(ptr -> right){q.push(ptr -> right);}
        }
    }
    return c;
}

int height(Node* root)
{
    if(!root)
    {
        return 0;
    }
    else
    {
        return max(height(root->left) , height(root->right)) + 1;
    }
}




int main()
{   
    Node* root = new Node();
    cout << "Enter the value of the root node" << endl;
    BuildTree(root);
    cout << height(root) << endl;
    return 0;
}