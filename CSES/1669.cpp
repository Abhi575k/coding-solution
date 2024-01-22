#include<bits/stdc++.h>

using namespace std;

void solve();

bool isLoop(int p,int s,vector<int> adj[],vector<int> &vis,vector<int> &res){
    if(vis[s]==1){
        res.push_back(s);
        return true;
    }
    bool stat=false;
    vis[s]=1;
    for(auto u:adj[s]){
        if(u!=p) stat|=isLoop(s,u,adj,vis,res);
        if(stat){
            res.push_back(s);
            break;
        }
    }
    return stat;
}

vector<int> roundTrip(int n,int m,vector<int> adj[]){
    vector<int> res;
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(isLoop(0,i,adj,vis,res)){
            vector<int> path;
            path.push_back(res[0]);
            for(int i=1;i<res.size();i++){
                path.push_back(res[i]);
                if(res[i]==path[0]) break;
            }
            return path;
        }
    }
    return {};
}

int main(){
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> res=roundTrip(n,m,adj);
    if(res.size()==0){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    cout<<res.size()<<"\n";
    for(auto u:res) cout<<u<<" ";
    cout<<"\n";
    return;
}