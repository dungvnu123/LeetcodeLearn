#include <bits/stdc++.h>
using namespace std;
// duyet theo dfs tim kiem duong fi sau nhat cay nhi phan 
// ket hop quay lui
using ll = long long;
struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

void DFS(TreeNode * root, vector<int>&path, vector<vector<int>>&result){
    if(root == NULL){
        return;
    }

    path.push_back(root -> val);
    // luu chi so duong di hien tai
    if(root -> left == NULL || root -> right == NULL){
        result.push_back(path);
    }
    // goi de quy sang hai ben 
    DFS(root -> left, path, result);
    DFS(root -> right, path, result);
    path.pop_back(); // backtrack
}

vector<vector<int>> Tree(TreeNode * root){
    vector<vector<int>>result;
    vector<int>path;
    DFS(root, path, result);
    return result;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<vector<int>>paths = Tree(root);
    for(auto & path : paths ){
        for(int val : path){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}