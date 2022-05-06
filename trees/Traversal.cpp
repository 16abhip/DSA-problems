#include "TreeNode_class.h"

// first root then child

void PreOrder(TreeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root -> data << " ";
    for (int i = 0; i < root -> children.size(); i++)
    {
        PreOrder(root -> children[i]);
    }
}

// first child then root

void PostOrder(TreeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < root -> children.size(); i++)
    {
        PostOrder(root -> children[i]);
    }
    cout << root -> data << " ";
}