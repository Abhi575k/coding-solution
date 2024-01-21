#include<bits/stdc++.h>

using namespace std;

int findNextIdx(vector<pair<int,int>> &a,int l,int r,int k){
    int res=r+1;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid].first>=k){
            res=mid,r=mid-1;
        }else l=mid+1;
    }
    return res;
}

int movieFestival(vector<pair<int,int>> &a,int n,int x,vector<int> &dp){
    if(x>=n) return 0;
    if(dp[x]!=-1) return dp[x];
    return dp[x]=max(1+movieFestival(a,n,findNextIdx(a,x+1,n-1,a[x].second),dp), movieFestival(a,n,x+1,dp));
}

void solve();

int main(){
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        a.push_back({u,v});
    }
    sort(a.begin(),a.end());
    vector<int> dp(n,-1);
    cout<<movieFestival(a,n,0,dp)<<"\n";
    // for(auto x:dp) cout<<x<<" ";
    // cout<<"\n";
    return;
}