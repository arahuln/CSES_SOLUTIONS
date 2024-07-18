#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>p={{-1,0},{1,0},{0,1},{0,-1}};
vector<char>s={'U', 'D', 'R', 'L'};
bool found=false;

void bfs(int x_start,int y_start,vector<vector<char>>&v,vector<vector<int>>&vis,vector<vector<pair<int,int>>>&back_track){
    vis[x_start][y_start]=1;
    queue<pair<int,int>>q;
    q.push({x_start,y_start});
    while(!q.empty()){
            int qx_start=q.front().first;
            int qy_start=q.front().second;
            q.pop();
        for(int i=0;i<4;i++){
            int new_x=qx_start+p[i].first;
            int new_y=qy_start+p[i].second;
            if(new_x >=0 && new_x<v.size() && new_y>=0 && new_y<v[0].size()){
            if(!vis[new_x][new_y] && v[new_x][new_y]=='.'){
                q.push({new_x,new_y});
                vis[new_x][new_y]=1;
                back_track[new_x][new_y]={qx_start,qy_start};
            }else if(!vis[new_x][new_y] && v[new_x][new_y]=='B'){
                vis[new_x][new_y]=1;
                back_track[new_x][new_y]={qx_start,qy_start};
                found=true;
                return;
            }
            }
        }
    }
}

void display_path(int ax, int ay, int bx, int by, vector<vector<pair<int,int>>>& back_track) {
    string path;
    pair<int,int> cur = {bx, by};
    while (cur != make_pair(ax, ay)) {
        pair<int,int> prev = back_track[cur.first][cur.second];
        for (int i = 0; i < 4; i++) {
            if (prev.first + p[i].first == cur.first && prev.second + p[i].second == cur.second) {
                path.push_back(s[i]);
                break;
            }
        }
        cur = prev;
    }
    reverse(path.begin(), path.end());
    cout << path.length() << "\n";
    cout << path << "\n";
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
        int ax,ay;
        int bx,by;
        vector<vector<char>>v(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
                if(v[i][j]=='A'){
                    ax=i;
                    ay=j;
                }
                if(v[i][j]=='B'){
                    bx=i;
                    by=j;
                }
            }
        }
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<pair<int,int>>>back_track(n,vector<pair<int,int>>(m,{-1,-1}));
        bfs(ax,ay,v,vis,back_track);
        if(found){
            cout<<"YES"<<"\n";
            display_path(ax,ay,bx,by,back_track);
        }else{
            cout<<"NO"<<"\n";
        }
        
    }
}
