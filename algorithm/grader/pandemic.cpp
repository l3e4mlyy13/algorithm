#include <bits/stdc++.h>
using namespace std;


int main(){
    int c,r,t; cin >> c >> r >> t;
    int mp[c][r],vs[c][r],dx[] = {-1,0,1,0},dy[] = {0,1,0,-1};
    queue<pair<int,int>> q;
    for(int i=0;i<c;i++) for(int j=0;j<r;j++){
        cin >> mp[i][j];
        vs[i][j] = 0;
        if(mp[i][j] == 1){
            q.push({i,j});
            vs[i][j] = 1;
        }
    }

    int sol = 0, x = q.size();

    while(!q.empty()){
        if(x == 0){
            x = q.size();
            if(t == 0) break;
            t--;
        }
        auto [cc,rr] = q.front(); q.pop();
        x--;
        sol++;
        for(int i=0;i<4;i++){
            int xx = cc+dx[i];
            int yy = rr+dy[i];
            if(xx == -1 || xx == c || yy == -1 || yy == r) continue;
            else if(mp[xx][yy] == 2 || vs[xx][yy]) continue;
            else{
                q.push({xx,yy});
                vs[xx][yy] = 1;
            }
        }
    }
    cout << sol;
}