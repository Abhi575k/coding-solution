#include <bits/stdc++.h>
 
using namespace std;
 
#define INF (ll)(1e17)
#define MX (int)2e5 + 5
#define ll long long int
#define MOD (ll)(1e8)
#define PRIME 13
#define N (int)(2e5+5)
#define M (int)(1e9+7)

struct trie{
    int val;
    trie* children[26];
    trie(){
        val=0;
        for(int i=0;i<26;i++) children[i]=NULL;
    }
};

trie *parent=NULL;

void insert(string s){
    if(parent==NULL) parent = new trie();
    int n=(int)s.length();
    trie *cur = parent;
    for(int i=0;i<n;i++){
        if(cur->children[(s[i]-'a')]==NULL) cur->children[(s[i]-'a')]=new trie();
        cur=cur->children[(s[i]-'a')];
    }
    cur->val=1;
    return;
}

void createGraph(string &s,int n,vector<int> adj[]){
    int m=(int)s.length();
    for(int i=0;i<m;i++){
        trie* cur=parent;
        for(int j=i;j<m;j++){
            if(cur->children[(s[j]-'a')]==NULL) break;
            cur=cur->children[(s[j]-'a')];
            if(cur->val==1){
                adj[i].push_back(j+1);
            }
        }
    }
    return;
}

int countPaths(int u,vector<int> adj[],vector<int> &cnt){
    if(cnt[u]!=-1) return cnt[u];
    int res=0;
    for(auto v:adj[u]){
        res=(res%M+countPaths(v,adj,cnt)%M)%M;
    }
    return cnt[u]=res;
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
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            string t;
            cin>>t;
            insert(t);
        }
        int m=(int)s.length();
        vector<int> adj[m+1];
        createGraph(s,n,adj);
        vector<int> cnt(m+1,-1);
        cnt[m]=1;
        cout<<countPaths(0,adj,cnt)<<"\n";
    }
    return 0;
}
