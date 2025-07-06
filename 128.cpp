#include <bits/stdc++.h>
using namespace std;
class Solution{
    int longestConsecutive(vector<int>&nums){
        int n = nums.size();
        if(nums.empty()){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int longest = 1;
        int current = 1;
        for(int i = 1; i< n ;i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            if(nums[i] = nums[i-1] + 1 ){
                current++;
            }
            else{
                longest = max(longest, current);
                // dat lai current = 1
                current = 1;
            }
        }
        return max(longest, current);
    }
};