#include<bits/stdc++.h>
using namespace std;
bool ans=false;
int final;

void dfs(int level,int parent,vector<vector<int>>&v,vector<int>&vis,vector<int>&path,vector<int>&back_track){
    vis[level]=1;
    path[level]=1;
    for(int i=0;i<v[level].size();i++){
        if(!vis[v[level][i]]){
            back_track[v[level][i]]=level;
            dfs(v[level][i],level,v,vis,path,back_track);
            if (ans) return;
        }else if(path[v[level][i]] && v[level][i] != parent){
            ans=true;
            final=v[level][i];
            back_track[v[level][i]]=level;
            return;
        }
    }
    path[level]=0;
}

void display(int start, vector<int>& back_track) {
    vector<int> cycle;
    int cur = start;
    cycle.push_back(cur);
    
    while (true) {
        int prev = back_track[cur];
        cycle.push_back(prev);
        cur = prev;
        if (cur == start) break;
    }
    
    cout << cycle.size() << "\n";
    for (int i = cycle.size() - 1; i >= 0; i--) {
        cout << cycle[i] << " ";
    }
    cout << "\n";
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
        vector<int>path(n+1,0);
        vector<int>back_track(n+1,-1);

        for(int i=1;i<=n;i++){
            if(!vis[i] && !ans){
                dfs(i,-1,edges,vis,path,back_track);
            }
        }
        if(ans){
            display(final,back_track);
        }else{
            cout<<"IMPOSSIBLE";
        }
    }
}