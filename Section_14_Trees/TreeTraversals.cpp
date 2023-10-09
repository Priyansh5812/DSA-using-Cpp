#include <iostream>
#include <stack>
#include "BinaryTreeCreation.cpp"
using namespace std;


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

void LevelOrderTraversal(Node * root)
{
    if(!root)
        return;

    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {   
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";
        if(temp -> left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
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

void PreOrderTraversal_Itr(Node* root)
{
    Node* p = root;
    stack<Node*> st;

    while(p)
    {
        cout << p ->data << " ";
        if(p->right)
            st.push(p->right);
        if(p->left)
            p = p -> left;
        else if(!st.empty())
        { 
            
            p = st.top();
            st.pop();
        }
        else
        {
            p = NULL;
        }
               
    }
}

void InOrderTraversal(Node * root)
{
    if(root)
    {
        InOrderTraversal(root -> left);
        cout << root -> data << " ";
        InOrderTraversal(root -> right);

    }

}

void PostOrderTraversal(Node * root)
{
    if(root)
    {   
        PostOrderTraversal(root -> left);
        PostOrderTraversal(root -> right);
        cout << root -> data << " ";
    }

}

int main()
{
    Node* root = new Node();
    BuildTree(root);
    //LevelOrderTraversal_Beautiful(root);
    cout << endl;
    cout << "Preorder : " << endl;
    PreOrderTraversal_Itr(root);
    cout << endl << "InOrder : " << endl;
    InOrderTraversal(root);
    cout << endl << "PostOrder : " << endl;
    PostOrderTraversal(root);
    
    return 0;
}