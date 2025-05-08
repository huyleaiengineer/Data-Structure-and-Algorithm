#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right): val(0), left(left), right(right) {}
};


void preOrderDFS(TreeNode *root)
{
    if (root == nullptr){
        return;
    }
    cout << root->val << " -> ";
    preOrderDFS(root->left);
    preOrderDFS(root->right);
}

void postOrderDFS(TreeNode *root)
{
    if (root == nullptr){
        return;
    }
    postOrderDFS(root->left);
    postOrderDFS(root->right);
    cout << root->val << " -> ";
}

void inOrderDFS(TreeNode *root)
{
    if (root == nullptr){
        return;
    }
    inOrderDFS(root->left);
    cout << root->val << " -> ";
    inOrderDFS(root->right);
}

void bfs(TreeNode *root)
{
    if (root == nullptr)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        cout << node->val << " -> ";
        if (node->left!=nullptr)
            q.push(node->left);
        if (node->right!=nullptr)
            q.push(node->right);
    }
}

void menu()
{
    /**
            1
        2       4
    3
    */

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(4);

    bool flag = true;
    int opt;

    while (flag)
    {
        cout << "MENU\n";
        cout << "1. PreoderDFS\n";
        cout << "2. InoerderDFS\n";
        cout << "3. PostoderDFS\n";
        cout << "4. BFS\n";
        cout << "Enter your option: "; cin >> opt;
        switch(opt)
        {
            case 1: {
                cout << "Using preorder DFS: root->left->right\n";
                preOrderDFS(root);
                cout << '\n';
                break;
            }
            case 2: {
                cout << "Using inorder DFS: left-> root ->right\n";
                inOrderDFS(root);
                cout << '\n';
                break;
            }
            case 3: {
                cout << "Using postorder DFS: left->right->root\n";
                postOrderDFS(root);
                cout << '\n';
                break;
            }
            case 4: {
                cout << "BFS\n";
                bfs(root);
                cout << '\n';
                break;
            }
        }

    }
}

int main()
{
    menu();
    return 0;
}
