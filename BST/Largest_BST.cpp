// Largest BST
// Send Feedback
// Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
// Input format :
// The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
// Output format:
// The first and only line of output contains the height of the largest BST.
// Constraints:
// Time Limit: 1 second
// Sample Input 1:
// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
// Sample Output 1:
// 2

#include "../Binary Trees/BinaryTreeClass.h"

class node{
    public:
    int maxHeight;
    int height;
    bool isBST;
    int minV;
    int maxV;
    node()
    {
        maxHeight = 0;
        isBST = true;
        height = 0;
        minV = INT_MAX;
        maxV = INT_MIN;
    }  
};

node helper(BinaryTreeNode<int>* root)
{
    node ans;
    if(root == NULL)
    {
        return ans;
    }
    if(root -> left == NULL && root -> right == NULL)
    {
        ans.isBST = true;
        ans.maxHeight = 1;
        ans.height = 1;
        ans.minV = root -> data;
        ans.maxV = root -> data;
        return ans;
    }
    node left = helper(root -> left);
    node right = helper(root -> right);
    ans.isBST = (left.isBST) && (right.isBST) && (root -> data > left.maxV) && (root -> data < right.minV);
    ans.minV = min(root -> data, min(left.minV, right.minV));
    ans.maxV = max(root -> data, max(left.maxV, right.maxV));
    ans.height = max(left.height, right.height) + 1;
    if(ans.isBST)
    {
        ans.maxHeight = max(ans.maxHeight,ans.height);
        return ans;
    }
    ans.maxHeight = max(ans.maxHeight, max(left.maxHeight, right.maxHeight));
    return ans;
    
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    return helper(root).maxHeight;
}