#include "TreeNode_class.h"

int getLeafNodeCount(TreeNode<int>* root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root -> children.size() == 0)
    {
        return 1;
    }
    int sum = 0;
    for (int i = 0; i < root -> children.size(); i++)
    {
        sum += getLeafNodeCount(root -> children[i]);
    }
    return sum;
}