/*
Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.
Note: Return NULL if no node is present with the value greater than n.
*/

#include "TreeNode_class.h"
#include <vector>

void helper(TreeNode<int>* root, int x, vector<TreeNode<int>*>* allNode)
{
    if (root -> data > x)
    {
        allNode -> push_back(root);
    }
    for (int i = 0; i < root -> children.size(); i++)
    {
        helper(root -> children[i], x, allNode);
    }
}

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x)
{
    if (root == NULL)
    {
        return root;
    }
    vector<TreeNode<int>*> *allNode = new vector<TreeNode<int>*>();
    helper(root, x, allNode);
    if (allNode -> size() == 0)
    {
        return NULL;
    }
    TreeNode<int>* ans = allNode -> at(0);
    for (int i = 1; i < allNode -> size(); i++)
    {
        if (ans -> data > allNode-> at(i) -> data)
        {
            ans = allNode -> at(i);
        }
    }
    delete allNode;
    return ans;
}

TreeNode<int>* getNextLargerElement_better(TreeNode<int>* root, int x)
{
    if (root == NULL)
    {
        return root;
    }
    TreeNode<int>* ans = NULL;
    for (int i = 0; i < root -> children.size(); i++)
    {
        TreeNode<int>* small = getNextLargerElement_better(root -> children[i], x);
        if (small != NULL && (ans == NULL || ans -> data > small -> data))
        {
            ans = small;
        }
    }
    if (root -> data > x)
    {
        if (ans == NULL || (root -> data < ans -> data))
        {
            return root;
        }
    }
    return ans;    
}