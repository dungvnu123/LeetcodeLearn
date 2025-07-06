#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node * next;
    Node(int x): val(x), next(nullptr) {};
};

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution{
    public:
     // tuim do dai cua danh sach lien ket 
     Node * current;
     int lenght(Node * head){
        int len = 0;
        while(head){
            len++;
            head = head -> next;
        }
        return len;
     }

     TreeNode * buidBst(int l, int r){
        if(l > r){
            return nullptr;
        }
        int mid = (l + r) / 2;
        TreeNode * Left = buidBst(l, mid - 1 );
        TreeNode * node = new TreeNode(current -> val);
        node -> left = Left;
        current = current -> next;
        // de quy sang ben phai cua Linkedlist
        TreeNode * Right = buidBst(mid + 1, r);
        node -> right = Right;
        return node;
     }
     // kiem tra so luong phan  tu buid up
     TreeNode*Kiemtra(Node * head){
        int lens = lenght(head);
        current = head;
        return buidBst(0, lens - 1);
     }
     void printf(TreeNode*root){
        if(!root){
            return;
        }
        printf(root -> left);
        cout << root -> val << " ";
        printf(root -> right);
     }

};
int main(){
    int t;
    cin >> t;
    while(t--){
        Node * head = new Node(-10);
        head -> next = new Node(-3);
        head -> next -> next = new Node(0);
        head -> next -> next -> next = new Node(5);
        head -> next -> next -> next -> next = new Node(9);
        Solution sol;
        TreeNode *output = sol.Kiemtra(head);
        cout << "Cout ra cay bst theo thu tu  BST" << endl;
        sol.printf(output);
        cout << endl; 
    }
}