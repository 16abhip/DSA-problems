#include "TreeNode_class.h"


TreeNode<int>* maxDataNode(TreeNode<int>* root)
{
    if (root == NULL)
    {
        return root;
    }
    TreeNode<int>* maxNode = root;
    for (int i = 0; i < root -> children.size(); i++)
    {
        TreeNode<int>* small = maxDataNode(root -> children[i]);
        if (maxNode -> data < small -> data)
        {
            maxNode = small;
        }
    }
    return maxNode;
}