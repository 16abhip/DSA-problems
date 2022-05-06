#include "TreeNode_class.h"

int getHeight(TreeNode<int>* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < root -> children.size(); i++)
    {
        int small = getHeight(root -> children[i]);
        if (ans < small)
        {
            ans = small;
        }
    }
    return ans + 1;
}