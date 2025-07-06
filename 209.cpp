#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int lenght = 0;
        int start = 0;
        int n = nums.size();
        for(int end = 0;  end < n ; end++){
            sum += nums[end];
            while(sum >= target){
                lenght = min(lenght, end - start + 1);
                sum -= nums[start];
                start++;
            }
        }    
        return lenght;

    }
};
int main(){
    Solution sol;
    int target;
    cin >> target;
    vector<int> nums = {1, 2, 3,1, 3, 4};
    cout << sol.minSubArrayLen(target, nums) << endl;
    return 0;
}