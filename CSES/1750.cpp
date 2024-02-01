#include<bits/stdc++.h>

using namespace std;

void solve();

vector<int> planetQueries1(int n,int q,vector<int> &a,vector<vector<int>> &queries){
    int MX=31;
    vector<vector<int>> dist_table(n+1,vector<int>(MX+1,-1));
    for(int i=1;i<=n;i++){
        dist_table[i][0]=a[i];
    }
    for(int i=1;i<=MX;i++){
        for(int j=1;j<=n;j++){
            int q_next=dist_table[j][i-1];
            dist_table[j][i]=dist_table[q_next][i-1];
        }
    }
    vector<bool> vis(n+1,false);
    vector<int> res;
    for(int i=0;i<q;i++){
        int x=queries[i][0];
        int k=queries[i][1];
        for(int j=0;j<=MX;j++){
            if((k&(1<<j))!=0){
                x=dist_table[x][j];
            }
        }
        res.push_back(x);
    }
    
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<int>> queries(q,vector<int>(2));
    for(int i=0;i<q;i++){
        cin>>queries[i][0]>>queries[i][1];
    }
    vector<int> res=planetQueries1(n,q,a,queries);
    for(auto u:res) cout<<u<<"\n";
    return;    
}