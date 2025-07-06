#include <bits/stdc++.h>
using namespace std;

using ll = long long;
typedef priority_queue<ll>ps; 
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef pair<ll, pair<int, int>>Node;
#define faster() ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

class Solution{
    public:
      ll kthSmallestProduct(vector<int>&nums1, vector<int>&nums2, ll k){
        int n = nums1.size();
        int m = nums2.size();
        priority_queue<Node, vector<Node>, greater<Node>> heap;
        // khoi tao hang dau tien la gia tri nho nhat 
        for(int j = 0;  j < m ;j++){
            ll tich = 1LL* nums1[0] * nums2[j];
            heap.push(make_pair(tich, make_pair(0, j)));
        }

        ll result = 0;
        while(k--){
            Node top = heap.top();
            heap.pop();
            ll val = top.first;
            int i = top.second.first;
            int j = top.second.second;
            result = val;
            if ( i + 1 < n){
                ll new_val = 1LL * nums1[i + 1] * nums2[j];
                heap.push(make_pair(new_val, make_pair(i + 1, j)));
            }
        }
        return result;
      }
};
int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {4, 5, 6};
    int k = 5;

    cout << "Tich nho thu " << k << " la: " << sol.kthSmallestProduct(nums1, nums2, k) << endl;

    return 0;
}