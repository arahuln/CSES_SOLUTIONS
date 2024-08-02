#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin>>t;
    while(t--){
        ll n,m,q;
        cin>>n>>m>>q;
        vector<vector<ll>>v(n+1,vector<ll>(n+1,1e15));
        for(ll i=0;i<m;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            v[a][b]=min(v[a][b],c);
            v[b][a]=min(v[b][a],c);
        }
        for(ll i=1;i<=n;i++){
            v[i][i]=0;
        }

        for(ll via=1;via<=n;via++){
            for(ll i=1;i<=n;i++){
                for(ll j=1;j<=n;j++){
                    if(v[via][j]==1e15||v[i][via]==1e15)continue;
                    v[i][j]=min(v[i][j],v[i][via]+v[via][j]);
                }
            }
        }

        for(ll i=0;i<q;i++){
            ll a,b;
            cin>>a>>b;
            if(v[a][b]==1e15){
                cout<<"-1\n";
            }else{
                cout<<v[a][b]<<"\n";
            }
        }
    }
}