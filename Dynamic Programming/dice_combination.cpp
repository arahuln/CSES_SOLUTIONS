#include<bits/stdc++.h>
using namespace std;
int n;
int m=1000000007;
int f(int sum,vector<int>&dp){
    if(sum==0)return 1;
    if(sum<0)return 0;
    if(dp[sum]!=-1)return dp[sum];
    int ans=0;
    for(int i=1;i<=6;i++){
        if(sum-i >= 0){
            ans=ans%m;
            ans+=f(sum-i,dp);
            ans=ans%m;
        }
    }
    dp[sum]=ans%m;
    return dp[sum]%m;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        cin>>n;
        vector<int>dp(n+1,-1);
        dp[0]=0;
        cout<<f(n,dp)<<"\n";
    }
}