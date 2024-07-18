#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>p={{0,1},{1,0},{-1,0},{0,-1}};
void bfs(int x,int y,vector<vector<char>>&v,vector<vector<int>>&vis){
    vis[x][y]=1;
    queue<pair<int,int>>q;
    q.push({x,y});
    while(!q.empty()){
        auto node=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int X=node.first+p[i].first;
            int Y=node.second+p[i].second;
            if(X>=0 && X<static_cast<int>(v.size()) && Y>=0 && Y< static_cast<int>(v[0].size())){
                if(v[X][Y]=='.' && !vis[X][Y]){
                    vis[X][Y]=1;
                    q.push({X,Y});
                }
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t = 1;
    // cin >> t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>>v(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
        }
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && v[i][j]=='.'){
                    bfs(i,j,v,vis);
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }
    
    return 0;
}