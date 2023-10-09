#include <iostream>
#include <queue>
#include <map>
using namespace std;


class Node
{
    public:
        int data;
        Node* left;
        Node* right;

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

void LevelOrderTraversal(Node* root)
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

void BottomView(Node* root , int x , map<int , pair<int , int>>& m)
{
    if(!root)
    {
        return;
    }

    if(m.count(x))
    {
        if(m[x].second == -1)
        {
            m[x].second = root->data;
        }
        else
        {
            m[x] = {root -> data , -1};
        }

    }
    else
    {
        m[x] = {root -> data , -1};
    }

    BottomView(root->left , x-1, m);
    BottomView(root->right , x+1 , m);
}

int main()
{    Node* root = new Node();
    cout << "Enter the value of the root node" << endl;
    cin >> root -> data;
    BuildTree(root);
    LevelOrderTraversal(root);
    cout << endl;
    map<int , pair<int , int>> m;
    BottomView(root , 0 , m);
    map<int , pair<int , int>> :: iterator it = m.begin();
    while(it != m.end())
    {
        cout << (*it).second.first << " ";
        if((*it).second.second != -1)
        {
            cout << (*it).second.second << " ";
        } 

        it++;
    }
    //5 10 -1 20  -1 30 35 -1 -1 40 -1 -1 15 20 -1 30 45 -1 -1 50 -1 -1 -1 
    
    return 0; 
}