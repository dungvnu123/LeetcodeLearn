#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int>&nums ){
    if(nums.empty()){
        return {}; 
    }
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int>dp(n, 1);
    vector<int>prev(n, -1);
    int max_index = 0;
    for(int i = 1 ;  i < n ; i++){
        for(int j = 1 ; j <= i ; j++){
            if(j < i ){
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j ] + 1;
                    prev[i] = j;
                }
            }
        }
        if(dp[i] > dp[max_index]){
            max_index = i;
        }
    }
    vector<int>result;
    if(max_index != -1){
        result.push_back(nums[max_index]);
        max_index = prev[max_index];
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    vector<int>nums = {1, 3, 4, 2, 8, 12};
    vector<int>res = solve(nums);
    for(int x : res){
        cout << x << " ";
    }
    cout << endl;
    return 0;

}