#include<bits/stdc++.h>
using namespace std;
bool found=false;
void bfs(int n,vector<vector<int>>&v,vector<int>&vis,vector<int>&back_track){
    vis[1]=1;
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int i=0;i<v[node].size();i++){
            if(!vis[v[node][i]]){
                vis[v[node][i]]=1;
                q.push(v[node][i]);
                back_track[v[node][i]]=node;
                if(v[node][i]==n){
                    found=true;
                    return;
                }
            }
        }
    }
}
void display(int n,vector<int>&back_track){
    int cur=n;
    vector<int>ans;
    ans.push_back(cur);
    while(cur != 1){
        ans.push_back(back_track[cur]);
        int prev=back_track[cur];
        cur=prev;
    }
    cout<<ans.size()<<"\n";
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
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
        vector<int>back_track(n+1,-1);
        bfs(n,edges,vis,back_track);
        if(found){
            display(n,back_track);
        }else{
            cout<<"IMPOSSIBLE";
        }
        
    }
}