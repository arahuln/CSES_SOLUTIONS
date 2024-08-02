#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void bell(ll n,vector<vector<ll>>&v,vector<ll>&vis,vector<ll>&isPart){
    for(ll i=0;i<n;i++){
        for(ll j=0;j<v.size();j++){
            ll a=v[j][0],b=v[j][1],c=v[j][2];
            if(vis[a]!=1e15 && vis[a]+c<vis[b]){
                vis[b]=vis[a]+c;
            }
        }
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<v.size();j++){
            ll a=v[j][0],b=v[j][1],c=v[j][2];
            if(vis[a]!=1e15 && vis[a]+c<vis[b] ||isPart[a]){
                isPart[a]=isPart[b]=1;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>>v;
        for(ll i=0;i<m;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            v.push_back({a,b,(-1)*c});
        }
        vector<ll>vis(n+1,1e15);
        vector<ll>isPart(n+1,0);
        vis[1]=0;
        bell(n,v,vis,isPart);
        if(isPart[n]){
            cout<<"-1\n";
        }else{
            cout<<vis[n]*(-1)<<"\n";
        }
    }
}