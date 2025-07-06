#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution{
    public:
      int Max_Sum = INT_MIN;
      int dfs(TreeNode * root){
        if (root == NULL){
            return 0;
        }
        int left = max(dfs(root -> left), 0);
        int right = max(dfs(root -> right), 0); // neu co gia tri am thi bo qua '
        int current_sum = root -> val + left + right;
        Max_Sum = max(Max_Sum, current_sum);
        return root ->val + max(left, right);
      }

      int max_post(TreeNode * root){
        dfs(root);
        return Max_Sum;
      }
};

int main(){
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Tong duong dan lon nhat la : " << sol.max_post(root) << endl;

    return 0;

}