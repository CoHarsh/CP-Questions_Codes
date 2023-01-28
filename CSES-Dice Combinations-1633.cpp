#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;



int helper(int n,vector<long long>&dp){
    if(n == 0 || n == 1)return 1;
    if(n < 0)return 0;

    if(dp[n] != 0)return dp[n];

    long long posibilties = 0;
    for(int i=1;i<=6;i++){
        if(n-i >= 0)
            posibilties += (helper(n-i,dp));
        else break;
    }

    dp[n] = posibilties%MOD;
    return dp[n];
}


void solve(){
    
    int n;
    cin>>n;
    vector<long long>dp(n+1,0);

    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=6 && i-j >= 0;j++){
            dp[i] += (dp[i-j]);
        }
        dp[i] = dp[i]%MOD;
    }
    cout<<dp[n]<<endl;

    // cout<<helper(n,dp)<<endl;

}

// Max Time Complexity = O(n * 6)
// Space complexity O(n+1)

int main(){

    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}
