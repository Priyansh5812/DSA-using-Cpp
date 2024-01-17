#include <iostream>
#include <queue>
using namespace std;



class Node
{
    public:
        int data;
        Node* left , *right;

        Node() : data(-1) , left(NULL) , right(NULL)
        {}
        Node(int x) : data(x) , left(NULL) , right(NULL)
        {}
        Node(int x, Node* left) : data(x) , left(left) , right(NULL)
        {}

        Node(int x , Node* left , Node* right) : data(x) , left(left) , right(right)
        {}
};

struct SearchData
{
    Node* curr , *prev;
    SearchData() : curr(NULL) , prev(NULL)
    {}
    SearchData(Node*trail , Node* target) : curr(target) , prev(trail)
    {}
};



Node* BuildTree(Node* &root)
{
    if(root == NULL)
    {
        root = new Node();
        cout << "Enter the value of the root Node " << endl;
        cin >> root -> data;
    }

    int d;
    cout << "Enter the value of the left Node of " << root -> data << endl;
    cin >> d;

    if(d != -1)
    {
        root -> left = new Node(d);
        BuildTree(root -> left);
    }

    cout << "Enter the value of the right Node of " << root -> data << endl;
    cin >> d;
    if(d != -1)
    {
        root -> right = new Node(d);
        BuildTree(root -> right);
    }
    return root;

}


void LevelOrderTraversal(Node*& root)
{   
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node * ptr = q.front();
        q.pop();

        if(ptr == NULL)
        {   
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {   
            cout << ptr -> data << " ";
            if(ptr -> left != NULL)
                {q.push(ptr->left);}
            if(ptr -> right != NULL)
                {q.push(ptr -> right);}
        }
    }


}


bool SearchInBST(Node*& root , int x)
{   
    if(root == NULL)
    {
        return false;
    }
    else if(root -> data == x)
    {
        return true;
    }
    else if(root -> data < x)
    {
        return SearchInBST(root -> right , x);
    }
    else
    {
        return SearchInBST(root -> left , x);
    }

}
Node* InOrderSucessor(Node* root)
{
    Node* ptr = root->right;
    while(ptr -> left)
    {
        ptr = ptr -> left;
    }
    return ptr;

}





Node* Deletion(Node*& root , int x)
{   
    if(root == NULL)
    {
        return root;
    }

    if(root -> data == x)
    {
        // 3 cases will be required
        // 0 children
        if(root -> left == NULL && root -> right == NULL)
        {
            free(root);
            return nullptr;
        }
        //1 child
        else if(root -> left == NULL && root -> right != NULL)
        {
            Node* temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> left != NULL && root -> right == NULL)
        {
            Node* temp = root -> left;
            free(root);
            return temp;
        }
        // 2 children
        else
        {
            Node* ptr = InOrderSucessor(root);
            root->data = ptr -> data;
            root->right = Deletion(root->right , ptr->data);
            return root;
        }
    }

    else if(root -> data < x) // go to the right
    {
        root -> right = Deletion(root -> right , x);
        return root;
    }
    else // go to the left
    {
        root -> left = Deletion(root -> left , x);
        return root;
    }
}


int main()
{   
    Node* root = NULL;
    root = BuildTree(root);
    LevelOrderTraversal(root);
    cout << endl;
    if(SearchInBST(root , 15))
    {
        Deletion(root , 15);
    }
    else 
    {
        std :: cout << "Node not present" << std :: endl;
    }

    LevelOrderTraversal(root);
    return 0;
}