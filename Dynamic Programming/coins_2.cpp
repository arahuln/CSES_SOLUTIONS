#include<bits/stdc++.h>
using namespace std;
int m=1000000007;
int f(int n,vector<int>&v){
    vector<int>dp(n+1,0);
    dp[0]=1;
    for(int i=0;i<v.size();i++){
        for(int j=1;j<=n;j++){
            if(j-v[i]>=0)dp[j]=(dp[j]+dp[j-v[i]])%m;
        }
    }
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
        
        cout<<f(x,v)<<"\n";
    }
}
