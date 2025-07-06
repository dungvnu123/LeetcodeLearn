#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>nums){
    int n = nums.size();
    for (int i = 0; i < n ; i++){
        for(int j = 1 ; j < n ;j++){
            for(int k = 2 ; k < n ; k++ ){
                if(nums[i] < nums[k] && nums[k] < nums[j]){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    vector<int>nums = {1, 4, 2, 5, 1, 3};
    bool result = check(nums);
    cout << result << endl;
    return 0;
}