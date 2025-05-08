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

void insertBSTreeUsingRecursion(TreeNode *&root, int key)
{
    if (root == nullptr)
        root = new TreeNode(key);
    else if (key < root->val)
        insertBSTreeUsingRecursion(root->left, key);
    else
        insertBSTreeUsingRecursion(root->right, key);

}

void insertUsingQueue(TreeNode *&root, int key)
{
    if (root == nullptr)
        root = new TreeNode(key);
    else{
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *tmp = q.front();
            q.pop();
            if (key <= tmp->val){
                if (tmp->left==nullptr)
                {
                    tmp->left = new TreeNode(key);
                    break;
                }
                else
                    q.push(tmp->left);
            }
            else{
                if (tmp->right == nullptr)
                {
                    tmp->right = new TreeNode(key);
                    break;
                }
                 else
                    q.push(tmp->right);
            }
        }
    }
}

void menu()
{
    /**
            1
              14
            5   21
               17  111

    */
    TreeNode *root;
    /*
    insertBSTreeUsingRecursion(root, 1);
    insertBSTreeUsingRecursion(root, 14);
    insertBSTreeUsingRecursion(root, 5);
    insertBSTreeUsingRecursion(root, 21);
    insertBSTreeUsingRecursion(root, 111);
    insertBSTreeUsingRecursion(root, 17);
    */
    insertUsingQueue(root, 1);
    insertUsingQueue(root, 14);
    insertUsingQueue(root, 5);
    insertUsingQueue(root, 21);
    insertUsingQueue(root, 111);
    insertUsingQueue(root, 17);

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
