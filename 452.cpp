#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef ll = long long;
using db = double;
int result(vector<int>&nums1, vector<int>&nums2, vector<int>&nums3, vector<int>&nums4){
    if (nums1.empty() && nums2.empty() && nums3.empty() && nums4.empty()){
        return 1;
    }
    int count = 0;
    unordered_map<int, int>abc;
    for(int a : nums1){
        for(int b : nums2){
            abc[a+b]++;
        }
    }

    for(int c : nums3){
        for(int d : nums4){
            int target = -(c + d);
            if(abc.find(target) != abc.end()){
                count += abc[target];
            }
        }
    }
    return count;
}
int main() {
    // Nhập ví dụ cụ thể
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};

    // Gọi hàm và in kết quả
    int result1 = result(nums1, nums2, nums3, nums4);
    cout << "So bo 4 chi so co tong = 0: " << result1 << endl;

    return 0;
}
