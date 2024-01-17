
// Is a tree a BST or not ?
#include <iostream>
#include <vector>
class Node
{
    public:
        int data;
        Node* left;
        Node* right;
        Node() : data(-1) , left(NULL) , right(NULL)
        {}
        Node(int x) : data(x) , left(NULL) , right(NULL)
        {}
        Node(int x, Node* left) : data(x) , left(left) , right(NULL)
        {}

        Node(int x , Node* left , Node* right) : data(x) , left(left) , right(right)
        {}
};

Node* BuildTree(Node* &root)
{
    if(root == NULL)
    {
        root = new Node();
        std :: cout << "Enter the value of the root Node " << std :: endl;
        std :: cin >> root -> data;
    }

    int d;
    std :: cout << "Enter the value of the left Node of " << root -> data << std :: endl;
    std :: cin >> d;

    if(d != -1)
    {
        root -> left = new Node(d);
        BuildTree(root -> left);
    }

    std :: cout << "Enter the value of the right Node of " << root -> data << std :: endl;
    std :: cin >> d;
    if(d != -1)
    {
        root -> right = new Node(d);
        BuildTree(root -> right);
    }
    return root;

}

void InorderTraversal(Node* root , std :: vector<int> & arr)
{   
    if(root)
    {
        InorderTraversal(root -> left , arr);
        arr.push_back(root->data);
        InorderTraversal(root->right , arr);
    }
}

 bool Approach1(Node* root)
 {
    
    std :: vector<int> arr;
    InorderTraversal(root , arr);

    std :: vector<int> :: iterator itprev , itcurr;

    itprev = arr.end()-2;
    itcurr = arr.end()-1;
    
    while(itprev != arr.begin())
    {
        if(*itprev > *itcurr)
        {
            return false;
        }
        itprev--;
        itcurr--;
    }

    return true;
 }

 bool Approach2(Node* root , int min , int max)
 {
    if(!root)
        return true;
    
    if(root -> data >= min && root -> data <= max)
        return (Approach2(root -> left , min , root -> data) && Approach2(root -> right , root -> data , max));
    
    else
        return false;

 }


int main()
{   
    Node* root = NULL;
    root = BuildTree(root);
   //std :: cout << ((Approach1(root)) ? ("BST"):("Just a Tree"));
    std :: cout << ((Approach2(root , INT_MIN , INT_MAX)) ? ("BST"):("Just a Tree"));
    return 0;
}