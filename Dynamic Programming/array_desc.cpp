#include<bits/stdc++.h>
using namespace std;
#define int long long
int m=1000000007;
bool check(int index,int j,vector<int>&v,int m){
    // if(j<1 || j>m)return false;
    if(index-1 >= 0 && abs(v[index-1]-j)>1)return false;
    if(index+1 <v.size() && abs(v[index+1]-j)>1)return false;
    return true;
}

int f(int n,vector<int>&v,int m){//level
    if(n==v.size())return 1;//base case
    int ans=0;
        if(v[n]==0){
            for(int j=0;j<=m;j++){//choices
                if(check(n,j,v,m)){
                    v[n]=j;
                    ans+=f(n+1,v,m);
                    ans%=m;
                    v[n]=0;
                }
            }
    }else{
        ans=f(n+1,v,m);
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        cout<<f(0,v,m)<<"\n";
    }
}