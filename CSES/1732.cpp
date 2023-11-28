#include <bits/stdc++.h>
 
using namespace std;
 
#define INF (ll)(1e17)
#define MX (int)2e5 + 5
#define ll long long int
#define MOD (ll)(1e8)
#define PRIME 13
#define N (int)(2e5+5)
#define M (int)(1e9+7)

vector<int> KMP(string s) {
    int n = (int)s.length();
    vector<int> pi(n,0);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--){
        string s;
        cin>>s;
        vector<int> pi=KMP(s);
        vector<int> res;
        int idx=pi.size()-1;
        while(pi[idx]!=0){
            res.push_back(pi[idx]);
            idx=pi[idx-1];
        }
        reverse(res.begin(),res.end());
        for(auto u:res) cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
