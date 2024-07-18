#include<bits/stdc++.h>
using namespace std;

int f(int n,vector<int>&v,vector<int>&dp){
    if(n==0)return 0;
    if(n<0)return INT_MAX;
    if(dp[n]!=-1)return dp[n];
    int ans=INT_MAX;
    for(int i=0;i<v.size();i++){
        int res=f(n-v[i],v,dp);
        if(res!=INT_MAX){
            ans=min(ans,(res+1));
        }
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
       int n,sum;
       cin>>n>>sum;
       vector<int>v(n);
       for(int i=0;i<n;i++){
        cin>>v[i];
       }
       vector<int>dp(sum+1,-1);
       dp[0]=0;
       if(f(sum,v,dp)==INT_MAX){
        cout<<"-1"<<"\n";
       }else{
        cout<<f(sum,v,dp)<<"\n";
       }
    }
}