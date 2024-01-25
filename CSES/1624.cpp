#include<bits/stdc++.h>

using namespace std;

void solve();

bool isPossible(int x,int y,int n,vector<vector<int>> &grid){
    if(grid[x][y]==1) return false;
    for(int i=0;i<n;i++) if(grid[x][i]==2) return false;
    for(int i=0;i<n;i++) if(grid[i][y]==2) return false;
    for(int i=0;x>=i&&y>=i;i++) if(grid[x-i][y-i]==2) return false;
    for(int i=0;x>=i&&y+i<n;i++) if(grid[x-i][y+i]==2) return false;
    for(int i=0;x+i<n&&y+i<n;i++) if(grid[x+i][y+i]==2) return false;
    for(int i=0;x+i<n&&y>=i;i++) if(grid[x+i][y-i]==2) return false;
    return true;
}

int chessboardAndQueens(int x,int n,vector<vector<int>> grid){
    if(x==n) return 1;
    int res=0;
    for(int i=0;i<n;i++){
        if(isPossible(x,i,n,grid)){
            grid[x][i]=2;
            res+=chessboardAndQueens(x+1,n,grid);
            grid[x][i]=0;
        }
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
    int n=8;
    vector<vector<int>> grid(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            if(s[j]=='*') grid[i][j]=1;
        }
    }
    cout<<chessboardAndQueens(0,n,grid)<<"\n";
    return;
}