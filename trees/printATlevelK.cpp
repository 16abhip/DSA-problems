#include "TreeNode_class.h"

void printATlevelK(TreeNode<int>* root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root -> data << "";
        return; 
    }
    for (int i = 0; i < root -> children.size(); i++)
    {
        printATlevelK(root -> children[i], k - 1);
    }
}