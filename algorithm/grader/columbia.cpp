#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,c; cin >> r >> c;
    int mp[r][c],sol[r][c];
    for(int i=0;i<r;i++) for(int j=0;j<c;j++){
        cin >> mp[i][j];
        sol[i][j] = INT_MAX;
    }
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    sol[0][0] = 0;

    int dx[] = {0,1,0,-1},dy[] = {-1,0,1,0};

    while(!q.empty()){
        auto [x,y,val] = q.front(); q.pop();
        if(val > sol[x][y]) continue;

        for(int i=0;i<4;i++){
            int xx = x+dx[i], yy = y+dy[i];
            if(xx == -1 || yy == -1 || xx == r || yy == c) continue;
            if(val+mp[xx][yy] < sol[xx][yy]){
                sol[xx][yy] = val+mp[xx][yy];
                q.push({xx,yy,sol[xx][yy]});
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++) cout << sol[i][j] << ' ';
        cout << endl;
    }
    
}