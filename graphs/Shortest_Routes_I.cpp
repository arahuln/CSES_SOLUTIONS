#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void bfs(vector<vector<pair<ll,ll>>>&v,vector<ll>&vis){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
    q.push({0,1});
    vis[1]=0;
    while(!q.empty()){
        ll dis=q.top().first,q_node=q.top().second;
        q.pop();
        if(dis>vis[q_node])continue;
        for(ll i=0;i<v[q_node].size();i++){
            ll weight=v[q_node][i].second,next_node=v[q_node][i].first;
            if(vis[q_node]+weight<vis[next_node]){
                q.push({vis[q_node]+weight,next_node});
                vis[next_node]=vis[q_node]+weight;
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
        vector<vector<pair<ll,ll>>>v(n+1);
        for(ll i=0;i<m;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            v[a].push_back({b,c});
        }
        vector<ll>vis(n+1,1e18);
        bfs(v,vis);
        for(ll i=1;i<=n;i++){
            cout<<vis[i]<<" ";
        }
        cout<<"\n";
    }
}