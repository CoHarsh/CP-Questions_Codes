#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define ll long long
const long long inf = INT_MAX;
const long long ninf = INT_MIN;
const int MOD = 1e9+7;

// https://cses.fi/problemset/task/1746/

int dp[100005][105];
void solve(){
    
    int n,m;
    cin>>n>>m;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    if(a[0]) dp[0][a[0]] = 1;
    else{
        rep(i,1,m+1){
            dp[0][i] = 1;
        }
    }

    rep(i,1,n){
        if(a[i]){
            rep(j,-1,2){
                if(a[i] + j >= 1 && a[i] + j <= m){
                    (dp[i][a[i]] += dp[i-1][a[i]+j])%=MOD;
                }
            }
        }
        else{
            rep(k,1,m+1){
                rep(j,-1,2){
                    if(k+j>=1 && k+j<=m) 
                        (dp[i][k] += dp[i-1][k+j])%=MOD;
                }
            }
        }
    }


    int sum=0;
    rep(i,1,m+1){
        (sum += dp[n-1][i])%=MOD;
    }
    cout<<sum<<endl;




}
    
int main(){

    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}
