#include "TreeNode_class.h"

void deleteTree(TreeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < root -> children.size(); i++)
    {
        deleteTree(root -> children[i]);
    }
    delete root;
}