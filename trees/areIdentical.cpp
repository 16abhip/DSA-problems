/*
Given two generic trees, return true if they are structurally identical. Otherwise return false.
*/

#include "TreeNode_class.h"

bool areIdentical(TreeNode<int>* root1,TreeNode<int>* root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    if (root1 -> data != root2 -> data || (root1 -> children.size() != root2 -> children.size()))
    {
        return false;
    }
    for (int i = 0; i < root1 -> children.size(); i++)
    {
        if (!areIdentical(root1 -> children[i], root2 -> children[i]))
        {
            return false;
        }
    }
    return true;
}