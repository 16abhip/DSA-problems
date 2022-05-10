#include "../Binary Trees/BinaryTreeClass.h"


class BST{
    BinaryTreeNode<int>* root;
    public:

    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }
    private:
    BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* root)
    {
        if(root == NULL)
        {
            return NULL;
        }
        if(root -> data > data)
        {
            root -> left = deleteData(data, root -> left);
            return root;
        }
        if(root -> data < data)
        {
            root -> right = deleteData(data, root -> right);
            return root;
        }
        if(root -> left == NULL && root -> right == NULL)
        {
            delete root;
            return NULL;
        }
        if(root -> left == NULL)
        {
            BinaryTreeNode<int>* newRoot = root -> right;
            root -> right = NULL;
            delete root;
            return newRoot;
        }
        if(root -> right == NULL)
        {
            BinaryTreeNode<int>* newRoot = root -> left;
            root -> left = NULL;
            delete root;
            return newRoot;
        }
        BinaryTreeNode<int>* temp = root -> right;
        while(temp -> left != NULL)
        {
            temp = temp -> left;
        }
        root -> data = temp -> data;
        root -> right = deleteData(temp -> data, root -> right);
        return root;
    }
    public:
    void deleteData(int data)
    {
        root = deleteData(data, root);
    }
    private:

    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* root, int val)
    {
        if(root == NULL)
        {
            return new BinaryTreeNode<int>(val);
        }
        if(root -> data > val)
        {
            root -> left = insert(root -> left, val);
        }
        else
        {
            root -> right = insert(root -> right, val);
        }
        return root;
    }

    public:

    void insert(int data){
        root = insert(root, data);
    }
    private:

    bool hasData(int data, BinaryTreeNode<int>* node)
    {
        if(root == NULL)
        {
            return false;
        }
        if(root -> data == data)
        {
            return true;
        }
        if(root -> data < data)
        {
            return hasData(data, root -> right);
        }
        return hasData(data, root -> left);
    }

    public:

    bool hasData(int data)
    {
        return hasData(data, root);
    }


};