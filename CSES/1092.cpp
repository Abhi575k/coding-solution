#include<bits/stdc++.h>

using namespace std;

#define int64 long long int

void solve();

int main(){
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}

void solve(){
    int64 n;
    cin>>n;
    int64 sum=(n*(n+1))/2;
    if(sum%2==1){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    vector<int> res[2];
    int64 s1=sum/2;
    for(int i=n;i>=1;i--){
        if(s1-i>=(int64)0){
            res[0].push_back(i);
            s1-=i;
        }else{
            res[1].push_back(i);
        }
    }
    cout<<res[0].size()<<"\n";
    for(auto u:res[0]) cout<<u<<" ";
    cout<<"\n";
    cout<<res[1].size()<<"\n";
    for(auto u:res[1]) cout<<u<<" ";
    cout<<"\n";
    return; 
}