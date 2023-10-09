#include <iostream>
#include <queue>
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




// int main()
// {
//     Node* root = new Node();

//     cout << "Enter the value of the root node" << endl;
//     cin >> root -> data;
//     BuildTree(root);
//     LevelOrderTraversal(root);
//     // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
        //10 8 -1 -1 30 40 -1 -1 50 70 -1 -1 -1 
//     return 0;
// }