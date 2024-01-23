#include<bits/stdc++.h>

using namespace std;

#define int64 long long int

void solve();

int64 roadReparation(int n,int m,vector<pair<int,int>> adj[]){
    priority_queue<pair<int,int>> pq;
    vector<bool> vis(n+1,false);
    pq.push({0, 1});
    int64 res=0;
    while(!pq.empty()){
        int x=pq.top().second;
        int c=pq.top().first;
        pq.pop();
        if(vis[x]) continue;
        vis[x]=true;
        res-=c;
        for(auto u:adj[x]) if(!vis[u.first]) pq.push({-u.second,u.first});
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) return -1;;
    }
    return res;
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
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    int64 res=roadReparation(n,m,adj);
    if(res==-1) cout<<"IMPOSSIBLE\n";
    else cout<<res<<"\n";
    return;    
}