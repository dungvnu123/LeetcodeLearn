#include<bits/stdc++.h>
using namespace std;
// dung quy hoach dong 
class Solution{
    public:
     int Max_sum(vector<int>&nums){
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }
        vector<int>dp(n); // bang luu phuong an
        // kiem tra xem cai nao max trhi chon lam diem bat dau 
        dp[0] = 0;
        dp[1] = max(dp[0], dp[1]);
        for(int i = 2 ; i < n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[n-1];
     }
};