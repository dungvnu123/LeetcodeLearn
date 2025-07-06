#include <bits/stdc++.h>
using namespace std;
const long long  AMan = 1e9 + 10007;
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        // n la so keo 
        // limit la soi luong keo toi da phat cho tre em 
        vector<vector<int>> dp(4, vector<int>(n + 1, 0));
        dp[0][0] = 1; // vi bao gioi cung co cach phat 0 cai keo dau tien choi 
        for(int i = 1; i<= 3; i++){
            for(int j = 0; j <= n ; j++){
                for(int k = 0 ; k <= limit  && k <=j ; ++k ){
                    // xac dinh cong thuc chung nho nhat 
                    dp[i][j] = (dp[i][j] + dp[i-1][j-k] ) % AMan;
                }
            }
        }
        return dp[3][n];
    }
};
int main(){
    int n;
    cin >> n;
    int limit;
    cin >> limit;
    Solution sol;
    long long key = sol.distributeCandies(n , limit);
    cout << key  << " ";
    cout << endl;
    return 0;
}