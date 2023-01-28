#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
// question : https://cses.fi/problemset/task/1635/
long long helper(int sum,vector<int>&coins,vector<long long>&dp){

    if(sum == 0)return 1;

    if(dp[sum] != -1)return dp[sum];
    int take = 0;
    for(auto coin : coins){
        if(sum - coin >= 0){
            take += helper(sum-coin,coins,dp);
        }
    }
    dp[sum] = take;
    return dp[sum];
}   


void solve(){
    int n,sum;
    cin>>n>>sum;
    vector<int>coins(n);
    for(int i=0;i<n;i++)cin>>coins[i];

    vector<long long>dp(sum+1,0);

    dp[0] = 1;
    for(int i = 1;i<=sum;i++){
        for(auto coin : coins){
            if(i - coin >= 0)
                dp[i] = (dp[i] + dp[i - coin])%MOD;
        }
    }
    cout<<dp[sum]<<endl;

    // cout<<helper(sum,coins,dp)<<endl;
   

}

/*
Time : O(sum * n)
Space : O(sum+1)


*/
    
int main(){

    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}
