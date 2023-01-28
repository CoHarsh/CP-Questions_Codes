#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

// Question : https://cses.fi/problemset/task/1634

int helper(int reqsum,vector<int>&coins,vector<int>&dp){
    if(reqsum == 0)return 0;
    if(dp[reqsum] != -1){
        return dp[reqsum];
    }
    int mincoins = INT_MAX;
    for(int i = 0;i<coins.size() && reqsum - coins[i] >= 0;i++){
        mincoins = min(mincoins,1 + helper(reqsum - coins[i],coins,dp));
    }
    dp[reqsum] = mincoins;
    return dp[reqsum];
}


void solve(){
    
    int n,sum;
    cin>>n;
    cin>>sum;
    vector<int>coins(n);
    for(int i=0;i<n;i++)cin>>coins[i];
    vector<long long>dp(sum+1,100000000);

    dp[0] = 0;
    for(int i=1;i<=sum;i++){
        for(int j=0;j<n;j++){
            if(i - coins[j] >= 0){
                dp[i] = min(dp[i],1ll+dp[i-coins[j]]);
            }
        }
    }
    if(dp[sum] == 100000000){
        cout<<"-1"<<endl;
    }
    else
        cout<<dp[sum]<<endl;
    
    // cout<<helper(sum,coins,dp)<<endl;

}

/*
 O(sum * n)
 O(sum+1)
 
 Note : Take care for long long give me 2 WA for this.

*/

int main(){

    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}
