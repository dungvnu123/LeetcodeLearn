#include <bits/stdc++.h>
using namespace std;
using b = bool;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        if(s3.length() != m + n){
            return false;
        }   
        // lu bang phuong an su dung quy hoach dong 
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        // khoi tao hang dau chi dung s2
        // s3 [i + j -1] 
        for(int j = 1; j <= n ; j++){
            dp[0][j] = dp[0][j -1]  && s2[j-1] == s3[0];
        }
        for(int i = 1 ; i <= m ; i++){
            dp[i][0] = dp[i - 1][0] && s1[i-1] == s3[0];
        }
        for(int i = 1 ; i <= m ; i++){
            for(int j = 1; j <= n ; j++){
                char c = s3[i + j -1];
                dp[i][j] = (dp[i- 1][j] && s1[i-1] == c || dp[i][j -1] && s2[j-1] == c);
            }
        }
        return dp[m][n];
    }
};
int main(){
    Solution sol;
    string s1, s2;
    cout << "Nhap vao s1" << endl;
    cin >> s1;
    cout << "NHAP VAO S2" << endl;
    cin >> s2;
    string s3;
    cin >> s3;
    if(sol.isInterleave(s1, s2, s3)){
        cout << "Khop" << endl;
    }
    else{
        cout <<"NO" << endl;
    }
    return 0;
}