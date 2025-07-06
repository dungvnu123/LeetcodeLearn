#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n ; 
        int k;
        cout << "Nhap vao so phan tu cua cua so truot :" << endl;
        cin >> k;
        int a[n];
        for(int i = 0; i < n ; i++){
            cin >>a[i];
        }
        ll sum = 0;
        ll res = sum;
        int index = 0;
        for(int i = 0 ; i < k ;i++){
            sum += a[i];
            res = sum;
        }
        for(int i = k ; i < n ; i++){
            sum += sum - a[i - k ] + a[i];
            index = i - k +1; // vi tri bat dau cua cua so moi
            if(sum > res){
                res = sum; 
            } 
        }
        cout << res << endl;
        for(int j = 0 ; j< k ;j++){
            cout << a[index + j ] << " ";
        }
        cout << endl;
    }
    return 0;
}