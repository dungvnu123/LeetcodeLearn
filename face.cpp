#include <bits/stdc++.h>
using namespace std;
void check(int N , int k , int Max_bac , vector<int>&result){
    if(N == 0){
        return ;
    }
    for(int i = Max_bac; i >= 0; i--){
        int x = pow(k, i);
        while(x <= N){
            result.push_back(i);
            check(N - x , k , i-1 , result); // goi de quy
            return; 
        }
    }
}
int main(){
    int N ; int k; cin>> N >> k;
}