#include "TreeNode_class.h"

/*
Given a generic tree, find and return the node for which sum of its data and data of all its 
child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.
*/


pair<TreeNode<int>*, int> helper(TreeNode<int>* root)
{
    pair<TreeNode<int>*, int> ans;
    ans.first = root;
    int sum = root -> data;
    for (int i = 0; i < root -> children.size(); i++)
    {
        sum += root -> children[i] -> data;
    }
    ans.second = sum;
    for (int i = 0; i < root -> children.size(); i++)
    {
        pair<TreeNode<int>*, int> small = helper(root -> children[i]);
        if (ans.second < small.second)
        {
            ans = small;
        }
    }
    return ans;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root)
{
    if (root == NULL)
    {
        return root;
    }
    return helper(root).first;
}