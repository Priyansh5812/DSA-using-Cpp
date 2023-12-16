#include <iostream>
#include <queue>
using namespace std;

class Node
{
    public:
        int data;
        Node* left , *right;
        Node(int x) : data(x)  , left(NULL) , right(NULL)
        {}
};

struct SearchData
{
    Node* t_ptr , *ptr;
};

void BuildTree(Node* root)
{
    if(root->data == -1)
    {
        cout << "Enter the data for the root Node" << endl;
        cin >> root -> data ;
    }

    int t;
    cout << "Enter the data for the left node of " << root -> data << endl;
    cin >> t;
    if(t != -1)
    {
        root ->left = new Node(t);
        BuildTree(root ->left);
    }

    cout << "Enter the data for the right Node of " << root -> data << endl;
    cin >> t;
    if(t != -1)
    {
        root ->right =  new Node(t);
        BuildTree(root -> right);
    }
}

void LevelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* ptr = q.front();
        q.pop();
        if(ptr == NULL)
        {   cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }

        }
        else
        {
            cout << ptr-> data << " ";
            if(ptr -> left)
            {
                q.push(ptr -> left);
            }

            if(ptr -> right)
            {   
                q.push(ptr -> right);
            }

        }

    }


}


SearchData SearchTree(Node* root , int Target)
{   
    Node* t_ptr = nullptr;
    Node* ptr = root;
    while(ptr && ptr -> data != Target)
    {   
        if(ptr -> data < Target)
        {   
            t_ptr = ptr;  
            ptr = ptr -> right;
        }
        else if(ptr -> data > Target)
        {   t_ptr = ptr;
            ptr = ptr -> left;
        }
        else
        {
            return {t_ptr , ptr};
        }
    }
    return {t_ptr , ptr};

}

SearchData GetInorderSucc(Node* root)
{

}

SearchData GetInorderPred(Node* root)
{

}

void DeleteNode(Node* root , int Target)
{
    SearchData Sdata = SearchTree(root , Target);
    if(Sdata.ptr  == nullptr)
    {   cout << "Node not found for deletion" << endl;
        return;
    }
    else
    {   
        SearchData newNodes;
        if(Sdata.ptr->left)
        {
            newNodes = GetInorderPred(Sdata.ptr);
            newNodes.t_ptr->right = NULL;


        }
        else if(Sdata.ptr ->right)
        {
            newNodes = GetInorderSucc(Sdata.ptr);
            newNodes.t_ptr->left = NULL;
        }


        

        free(Sdata.ptr);
    }

}

int main()
{
    Node* root = new Node(-1);
    BuildTree(root);
    cout << endl;
    LevelOrderTraversal(root);
    cout << endl;
    DeleteNode(root , 20);
    LevelOrderTraversal(root);
    return 0;
}
