#include "TreeNode_class.h"
#include <queue>

void printLevelWise(TreeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int>*> pending;
    pending.push(root);
    while (!pending.empty())
    {
        TreeNode<int>* Node = pending.front();
        pending.pop();
        cout << Node -> data << ":";
        for (int i = 0; i < Node -> children.size(); i++)
        {
            cout << Node -> children[i] -> data;
            pending.push(Node -> children[i]);
            if (i != Node -> children.size() - 1)
            {
                cout << ",";
            }
        }
        cout << endl;
    }
}

void PrintTree(TreeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root -> data << ": ";
    for (int i = 0; i < root -> children.size(); i++)
    {
        cout << root -> children[i] -> data;
        if (i != root -> children.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
    for (int i = 0; i < root -> children.size(); i++)
    {
        PrintTree(root -> children[i]);
    }
}

TreeNode<int>* takeInput_levelWise()
{
    int rootData;
    cout << "Enter Root Data: ";
    cin >> rootData;
    queue<TreeNode<int>*> pending;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    pending.push(root);
    while (!pending.empty())
    {
        TreeNode<int>* Node = pending.front();
        pending.pop();
        int n;
        cout << "Enter Nums of child of " << Node -> data << ": ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter childs of " << Node -> data << ": ";
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            Node -> children.push_back(child);
            pending.push(child);
        }
    }
    return root;
}

TreeNode<int>* takeInput()
{
    int data;
    cout << "Enter data" << endl;
    cin >> data;
    TreeNode<int>* root = new TreeNode<int>(data);
    int num;
    cout << "Num of child of " << data << ": ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        root -> children.push_back(takeInput());
    }
    return root;
}

int main()
{
    TreeNode<int>* root = takeInput_levelWise();
    PrintTree(root);
}