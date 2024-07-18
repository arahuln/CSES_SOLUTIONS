#include<bits/stdc++.h>
using namespace std;
bool ans=true;
bool check(vector<vector<int>>&v,vector<int>&vis,int color,int node){
    for(int i=0;i<v[node].size();i++){
        if(vis[v[node][i]]==color){
            return false;
        }
    }
    return true;
}

void bfs(int n,vector<vector<int>>&v,vector<int>&vis){
    vis[n]=1;
    queue<int>q;
    q.push(n);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        int cur_color=vis[node];
        for(int i=0;i<v[node].size();i++){
                if(!vis[v[node][i]] && check(v,vis,3-cur_color,v[node][i])){
                    q.push(v[node][i]);
                    vis[v[node][i]]=3-cur_color;
                }else if(!(check(v,vis,3-cur_color,v[node][i]))){
                    ans=false;
                    return;
                }
        }
    }
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
        vector<vector<int>>edges(n+1);
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        vector<int>vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                bfs(i,edges,vis);
            }
        }
        if(!ans){
            cout<<"IMPOSSIBLE"<<"\n";
        }else{
            for(int i=1;i<=n;i++){
                cout<<vis[i]<<" ";
            }
            cout<<"\n";
        }
    }
}