#include<bits/stdc++.h>
using namespace std;
const long long inf = INT_MAX;
const int MOD = 1e9+7;

// Question : https://cses.fi/problemset/task/1637/

int dp[1000005];

void solve(){

    int n;
    cin>>n;
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        string str = to_string(i);
        set<int>s;
        for(auto ch : str){
            s.insert(ch-'0');
        }
        dp[i] = inf;

        for(auto j : s){
            if(j != 0)
            dp[i] = min(dp[i], 1 + dp[i - j]);
        }
    }
    cout<<dp[n]<<endl;
}
/*

Note : Use array instead of vector and use set for not repeating the numbers like 1112 call only : 2!  for 1 and 2
Time : O(n * 6)
Space : O(6 + n) 6 for set 

*/
int main(){

    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}
