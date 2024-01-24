#include<bits/stdc++.h>

using namespace std;

void solve();

int collectingNumbers(int n,vector<int> &a){
    vector<int> idx(n+1), itr(n+1);
    int res=0;
    for(int i=0;i<n;i++) idx[a[i]]=i;
    itr[1]=1;
    for(int i=2;i<=n;i++){
        if(idx[i]>idx[i-1]){
            itr[i]=itr[i-1];
        }else{
            itr[i]=itr[i-1]+1;
        }
    }
    for(int i=1;i<=n;i++) res=max(res,itr[i]);
    return res;
}

int main(){
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<collectingNumbers(n,a)<<"\n";
    return;
}