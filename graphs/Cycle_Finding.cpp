#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int INF=1000000000;
vector<int> ans;
 
void display_path(int x, vector<int>& par) {
    int cur = x;
    do {
        ans.push_back(cur);
        cur = par[cur];
    } while (cur != x);
    ans.push_back(x);
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            v.push_back({a, b, c});
        }
        vector<int> vis(n + 1, INF);
        vis[1] = 0;
        vector<int> par(n + 1, -1);
        int x = -1;
        for (int i = 0; i < n; i++) {
            x = -1;
            for (int j = 0; j < m; j++) {
                if (vis[v[j][0]] + v[j][2] < vis[v[j][1]]) {
                    vis[v[j][1]] = vis[v[j][0]] + v[j][2];
                    par[v[j][1]] = v[j][0];
                    x = v[j][1];
                }
            }
        }
        if (x == -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                x = par[x];
            }
            display_path(x, par);
        }
    }
}