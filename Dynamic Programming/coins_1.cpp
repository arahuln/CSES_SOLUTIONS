#include<bits/stdc++.h>
using namespace std;
int m=1000000007;
int f(int n,vector<int>&v,vector<int>&dp){
    if(n==0)return 1;
    if(n<0)return 0;
    if(dp[n]!=-1)return dp[n];
    int ans=0;
    for(int i=0;i<v.size();i++){
        ans=(ans+f(n-v[i],v,dp));
        if(ans >= m) ans -= m;
    }
    dp[n]=ans;
    return dp[n];
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<int>dp(x+1,-1);
        cout<<f(x,v,dp)<<"\n";
    }
}
