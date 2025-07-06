#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1001;
int n, a[maxn], dp[maxn];
void solve(){
    int ans = 1;
    for(int i = 0; i < n ;i++){
        for(int j = 0 ; j <= i ; j++){
            if(a[i] > a[j]){
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }
    cout << ans << endl;
}