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

    void deleteData(int data)
    {

    }

    void insert(int data){

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