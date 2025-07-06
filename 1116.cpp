#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode *right;
    TreeNode(int x) :val(x) , left(nullptr) , right(nullptr) {};
};
class Solution{
    public:
     TreeNode * prev; // lu bien trc 
     void flatten(TreeNode *root){
        if(root = nullptr){
            return;
        }
        // vi no yeu cau la duyet theo thu tu  N - L  - R 
        flatten(root -> right);
        flatten(root -> left);
        root -> right = prev;
        root -> left = nullptr;
        prev = root;
     }
};
void printFlattenedList(TreeNode * root){
    while(root){
        cout << root -> val << " ";
    }
    return;
}

int main() {
    // Tạo cây ví dụ:
    //       1
    //      / \
    //     2   5
    //    / \   \
    //   3   4   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution sol;
    sol.flatten(root);

    // In ra kết quả sau khi flatten:
    printFlattenedList(root);  // Kỳ vọng: 1 2 3 4 5 6

    return 0;
}