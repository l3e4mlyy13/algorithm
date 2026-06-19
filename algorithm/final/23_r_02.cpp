#include <bits/stdc++.h>
using namespace std;

int r,c,mp[505][505];
int mod = 100000007;
long long dp[505][505][4];

long long recur(int x, int y, int z){
    
    if(x == r || x == -1 || y == c || mp[x][y]) return 0;
    if(y == c-1) return 1;
    if(dp[x][y][z]) return dp[x][y][z];

    long long sol = 0;
    if(z != 1) sol = (sol+recur(x-1,y+1,1))%mod;
    if(z != 2) sol = (sol+recur(x,y+1,2))%mod;
    if(z != 3) sol = (sol+recur(x+1,y+1,3))%mod;

    return dp[x][y][z] = sol;

}

int main(){

    cin >> r >> c;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin >> mp[i][j]; 
    
    long long sol = 0;
    for(int i=0;i<r;i++){
        sol = (sol+recur(i,0,0))%mod;
    }
    cout << sol;
    
}