#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dp[1001];
int main(){
    int n ;
    int S ; // so tien muon doi 
    cin >> S;
    cin >> n;
    int a[n];
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }
    memset(dp[1001] )
    for(int i = 1; i <= S ; i++ ){
        dp[i] = 1e9;
        for(int e : a){
            if (i >= e){ // neu so tien can doi lon hon so tien trong mang 
                dp[i] =(dp[i] + dp[i - e]);
            }
        }
    }
    if(dp[S] == 1e9){
        cout << "-1\n";
    }
    else{
        cout << dp[S] << endl;
    }
    return 0;
}