#include <bits/stdc++.h>
using namespace std;
using ll =long long;
class Solution {
public:
    vector<int>nodes;
    void DFS(int curr , int n ){
        if (curr > n){
            return;
        }
        nodes.push_back(curr);
        for(int i = 1 ; i <= 9; i++){
          int next = curr *  10 + i;
          if(next > n){
            break;
          }
          DFS(next, n);
        }
    }
    int findKthNumber(int n, int k) {
        for(int i = 1; i <= 9; i++){
           DFS(i, k);
        }
        return nodes[k-1];
    }
};