#include<bits/stdc++.h>
using namespace std;

void dfs(int level,vector<vector<int>>&edges,vector<int>&vis,vector<int>&temp){
    temp.push_back(level);
    vis[level]=1;
    for(int i=0;i<edges[level].size();i++){
        if(!vis[edges[level][i]]){
            vis[edges[level][i]]=1;
            dfs(edges[level][i],edges,vis,temp);
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
        int cnt=0;
        vector<vector<int>>v;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vector<int>temp;
                dfs(i,edges,vis,temp);
                cnt++;
                v.push_back(temp);
            }
        }
        cout<<cnt-1<<"\n";
        for(int i=0;i<v.size();i++){
            if(i+1<v.size()){
                cout<<v[i][0]<<" "<<v[i+1][0]<<"\n";
            }
        }
    }
}