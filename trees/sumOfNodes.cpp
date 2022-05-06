#include "TreeNode_class.h"

int sumOfNodes(TreeNode<int>* root)
{
    if (root == NULL)
    {
        return -1;
    }
    int sum = root -> data;
    for (int i = 0; i < root -> children.size(); i++)
    {
        sum += sumOfNodes(root -> children[i]);
    }
    return sum;
}