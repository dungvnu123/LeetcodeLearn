#include <bits/stdc++.h>
using namespace std;
using ll =long long;
// gia tri index di chuyen bool kiem tra chi co buy or dsell 
// Ngày i, canBuy=1
//        ┌───────────────┐
//        │  Quyết định   │
//        │    mua?       │
//        └──────┬────────┘
//               │
//         ┌─────┴─────┐
//         │           │
//       Mua          Không mua
//       (buy)         (skip)
//         │             │
// - prices[i] +    maxProfit(i+1, 0, k)
// maxProfit(i+1,0,k)   

//         │             │
//         └──────┬──────┘
//                │
//       max(buy, skip)  
//                │
//           Lợi nhuận tối đa

class Solution{

    public:
     int dp[1001][2][1001];  
     int max_profit(int i , bool can_buy , int k , vector<int>&prices){
        if(i == prices.size() || k == 0){
            return 0;
        }
        if(dp[i][can_buy][k] != -1){
            return dp[i][can_buy][k];
        }

        // vong lap su ly mua hay khoiing mua
        int profits = 0;
        if(can_buy){
            int mua = -prices[i] + max_profit(i +1 , false, k , prices); // mua mat tien 
            int skip = max_profit( i+1 , true, k , prices); // khog mua 
            profits = max(mua, skip);
        }
        else{
            int ban = prices[i] + max_profit(i + 1, true, k , prices); //ban 
            int skip = max_profit( i +1 , false, k , prices);
            profits = max(ban , skip);
        }
        return dp[i][can_buy][k] = profits;
     } 
     int de_quy(int k , vector<int>&prices){
        memset(dp, -1, sizeof(dp));
        return max_profit(0, true, k , prices);
     }
};