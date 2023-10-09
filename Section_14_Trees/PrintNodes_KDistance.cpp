#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node
{
    public:
        int data;
        Node* left, *right;
        Node() : data(-1) , left(nullptr) , right(nullptr)
        {}
        Node(int data) : data(data) , left(nullptr) , right(nullptr)
        {}
};

void BuildTree(Node* root)
{
    if(!root)
    {
        root = new Node();
    }

    if(root -> data == -1)
    {
        cout << "Enter the value of root Node" << endl;
        cin >> root ->data;
    }

    int temp;
    cout << "Enter the left root of " << root -> data << endl;
    cin >> temp;
    if(temp != -1)
    {
        root -> left = new Node(temp);
        BuildTree(root->left);
    }
    cout << "Enter the right root of" << root -> data << endl;
    cin >> temp;
    if(temp != -1)
    {
        root -> right = new Node(temp);
        BuildTree(root -> right);
    }

}

void DisplayDistK(Node* root , int k)
{
    int c = 0;
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node*ptr = q.front();
        q.pop();

        if(!ptr)
        {
            c++;
            if(!q.empty())
            {
                q.push(NULL);
            }
            if(c > k)
            {
                return;
            }
        }
        else
        {
            if(c==k)
            {
                cout << ptr -> data << " ";
            }
            if(ptr->left){q.push(ptr->left);}
            if(ptr->right){q.push(ptr->right);}
        }
    }

}   

void InOrder(Node* root)
{
    if(root)
    {
        InOrder(root -> left);
        cout << root -> data << " ";
        InOrder(root -> right);
    }
}

int main()
{   

    Node* root = new Node();
    BuildTree(root);
    DisplayDistK(root , 2);
    return 0;
}