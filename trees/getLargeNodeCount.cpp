#include "TreeNode_class.h"

int getLargeNodeCount(TreeNode<int>* root, int x)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 0;
    if (root -> data > x)
    {
        ans++;
    }
    for (int i = 0; i < root -> children.size(); i++)
    {
        ans += getLargeNodeCount(root -> children[i], x);
    }
    return ans;
}