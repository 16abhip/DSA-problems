#include "TreeNode_class.h"

void Print(TreeNode<int>* root)
{
    // this is not a base case, it's a edge case... as if the Node has no child.. we'll not enter in the loop...
    if (root == NULL)
    {
        return;
    }
    cout << root -> data << ": ";
    for (int i = 0; i < root -> children.size(); i++)
    {
        cout << root -> children[i] -> data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        Print(root->children[i]);
    }
}

void print(TreeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root -> data << endl;
    for (int i = 0; root->children.size(); i++)
    {
        print(root->children[i]);
    }
}

int main()
{
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* c1 = new TreeNode<int>(2);
    TreeNode<int>* c2 = new TreeNode<int>(3);
    root -> children.push_back(c1);
    root -> children.push_back(c2);
    Print(root);  
}