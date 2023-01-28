#include<bits/stdc++.h>
using namespace std;
const long long inf = INT_MAX;
const int MOD = 1e9+7;

// Question : https://cses.fi/problemset/task/1638/


int dp[1005][1005];

void solve(){
    
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            char ch;
            cin>>ch;
            if(ch == '*')dp[i][j] = 0;
            else if(i == 1 && j == 1)dp[i][j] = 1;
            else{
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
            }
        }
    }
    cout<<dp[n][n]<<endl;
}
    
int main(){

    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}
