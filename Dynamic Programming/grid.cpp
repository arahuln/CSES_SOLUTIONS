#include<bits/stdc++.h>
using namespace std;
int m=1000000007;

int f(int x,int y,vector<vector<char>>&v,vector<vector<int>>&dp){
    if(x==0 && y==0)return 1;
    if(x<0 || y<0)return 0;
    if(dp[x][y]!=-1)return dp[x][y];
    int ans=0;
    if(x-1>=0 && v[x-1][y]=='.'){
        ans+=f(x-1,y,v,dp);
        if(ans >= m) ans -= m;
    }
    if(y-1>=0 && v[x][y-1]=='.'){
        ans+=f(x,y-1,v,dp);
        if(ans >= m) ans -= m;
    }
    dp[x][y]=ans;
    return dp[x][y];
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<char>>v(n,vector<char>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>v[i][j];
            }
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        dp[0][0]=1;
        if(v[0][0]=='*' || v[n-1][n-1]=='*')cout<<"0"<<"\n";
        else{
            cout<<f(n-1,n-1,v,dp)<<"\n";
        } 
    }
}