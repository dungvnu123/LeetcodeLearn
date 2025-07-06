#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
     vector<int>nodes;
     void dfs(int curr, int n){
        if(curr > n){
            return;
        }
        nodes.push_back(curr);
        for(int i = 0;  i<= 9; i++){
            int next = curr * 10 + i;
            dfs(next,  n);
        }
     }
     int index_card(int n , int k){
        for(int i = 1; i <= 9; i++){
            if()
        }
     }
};