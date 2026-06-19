#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(0);
    int r,c; cin >> r >> c;
    queue<tuple<int,int,int>> q;
    int mp[r][c];
    int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> mp[i][j];
            if(mp[i][j] == 1) q.push({i,j,1});
        }
    }

    while(!q.empty()){
        auto [x,y,sol] = q.front(); q.pop();
        if(mp[x][y] == 2){
            cout << sol;
            return 0;
        }
        for(int i=0;i<4;i++){
            int xn = x+dx[i], yn = y+dy[i];
            if(xn == -1 || xn == r || yn == -1 || yn == c || mp[xn][yn] == 3 || mp[xn][yn] == 1) continue;
            if(mp[xn][yn] == 0) mp[xn][yn] = 1;
            q.push({xn,yn,sol+1});
            
        }
    }

}