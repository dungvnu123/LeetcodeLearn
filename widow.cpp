#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n;
        int k;
        cin >> k;
        int a[n];
        for(int i = 0; i < n ; i++){
            cin >> a[i];
        }
        int d = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(a[i] <= k){
                d++;
            }
        }
        int count = 0;
        for(int i = 0 ; i < d ; i++){
            if(a[i] <= k ){
                count++;
            }
        }
        int ans = count;
        for(int i = d ; i < n ; i++){
            if(a[i- d] <= k){
                count--;
            }
            if(a[i] <= k ){
                count++;
                ans = max(ans, count);
            }
        }
        cout << d - ans << endl;
    }
    return 0;;
}