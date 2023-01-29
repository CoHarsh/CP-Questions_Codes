#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define ll long long
const long long inf = INT_MAX;
const long long ninf = INT_MIN;
const int MOD = 1e9+7;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int dp[1000005]={0};
void solve(){
    
    int n,x; cin>>n>>x;
    vector<int>v(n);
    rep(i,0,n+1)cin>>v[i];
    sort(all(v));
    dp[0]=1;
    rep(i,0,n){
        rep(j,1,x+1){
            if (j-v[i]>=0)dp[j]+= dp[j-v[i]];
            dp[j]%=MOD;
        }
    }
    cout<<dp[x]<<endl;

}
    
int main(){
    IOS;
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}
