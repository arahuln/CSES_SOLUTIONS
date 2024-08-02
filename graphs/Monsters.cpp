#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int,int>>p={{-1,0},{1,0},{0,1},{0,-1}};
vector<char>s={'U', 'D', 'R', 'L'};
 
void m_bfs(vector<vector<char>>&v,vector<pair<int,int>>&monsters,vector<vector<ll>>&dist1){
    queue<pair<int,int>>q;
    for(int i=0;i<monsters.size();i++){
        q.push({monsters[i].first,monsters[i].second});
        dist1[monsters[i].first][monsters[i].second]=0;
    }
    while(!q.empty()){
        int qx=q.front().first,qy=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int x=qx+p[i].first,y=qy+p[i].second;
            if(x>=0 && x<v.size() && y>=0 && y<v[0].size() && dist1[qx][qy]+1<dist1[x][y] && (v[x][y]=='.' || v[x][y]=='A')){
                dist1[x][y]=dist1[qx][qy]+1;
                q.push({x,y});
            }
        }
    }
}
 
void bfs(int x_start,int y_start,vector<vector<char>>&v,vector<vector<pair<int,int>>>&back_track,vector<vector<ll>>&dist2){
    queue<pair<int,int>>q;
    dist2[x_start][y_start]=0;
    q.push({x_start,y_start});
    while(!q.empty()){
        int qx=q.front().first,qy=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int x=qx+p[i].first,y=qy+p[i].second;
            if(x>=0 && x<v.size() && y>=0 && y<v[0].size() && dist2[qx][qy]+1<dist2[x][y] && (v[x][y]=='.')){
                dist2[x][y]=dist2[qx][qy]+1;
                back_track[x][y]={qx,qy};
                q.push({x,y});
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
    cout<<"YES"<<"\n";
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
        vector<vector<char>>v(n,vector<char>(m));
        vector<pair<int,int>>monsters;//monsters location...
        pair<int,int>A;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
                if(v[i][j]=='M'){
                    monsters.push_back({i,j});
                }else if(v[i][j]=='A'){
                    A.first=i;
                    A.second=j;
                }
            }
        }
        vector<vector<ll>>dist1(n,vector<ll>(m,1e15));
        m_bfs(v,monsters,dist1);
        vector<vector<ll>>dist2(n,vector<ll>(m,1e15));
        vector<vector<pair<int,int>>>back_track(n,vector<pair<int,int>>(m,{-1,-1}));
        bfs(A.first,A.second,v,back_track,dist2);
        int cur_x,cur_y;
        bool found=false;
        for (int i = 0; i < n; i++){
            if (dist2[i][0] < dist1[i][0]){
                found = true;
                cur_x=i;cur_y=0;
                break;
            }
            if (dist2[i][m - 1] < dist1[i][m - 1]){
                found = true;
                cur_x=i;cur_y=m-1;
                break;
            }
        }
 
    if (!found){
        for (int j = 0; j < m; j++){
            if (dist2[0][j] < dist1[0][j]){
                found = true;
                cur_x=0;cur_y=j;
                break;
            }
            if (dist2[n - 1][j] < dist1[n - 1][j]){
                found = true;
                cur_x=n-1;cur_y=j;
                break;
            }
        }
    }
    if(found){
        display_path(A.first,A.second,cur_x,cur_y,back_track);
    }else{
        cout<<"NO"<<"\n";
    }
    
    }
}