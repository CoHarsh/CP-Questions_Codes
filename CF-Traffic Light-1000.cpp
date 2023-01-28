#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
const long long inf = INT_MAX;
const long long ninf = INT_MIN;
const int MOD = 1e9+7;
 // Question : https://codeforces.com/problemset/problem/1744/C

void solve(){
    int n;
    char ch;
    string str;
    cin>>n>>ch>>str;
    str = str + str;
    vector<int>a;
    for(int i=0;i<2*n;i++){
        if(str[i] == 'g'){
            a.push_back(i);
        }
    }
    int maxans = ninf;
    for(int i=0;i<n;i++){
        if(str[i] == ch){
            // find the lower bound and update the max
            maxans = max(maxans,*lower_bound(all(a),i) - i);
        }
    }
    cout<<maxans<<endl;

}
    
int main(){

    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}
