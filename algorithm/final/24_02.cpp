#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,c,k; cin >> r >> c >> k;
    int mp[r][c];
    queue<tuple<int,int,int>> q;
    int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> mp[i][j];
            if(mp[i][j]) q.push({i,j,0});
        }
    }

    while(!q.empty()){
        auto [x,y,z] = q.front(); q.pop();
        if(z == k) continue;
        for(int i=0;i<4;i++){
            int xn = x+dx[i], yn = y+dy[i];
            if(xn == -1 || yn == -1 || xn == r || yn == c || mp[xn][yn]) continue;
            q.push({xn,yn,z+1});
            mp[xn][yn] = 2;
        } 
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << mp[i][j] << ' ';
        }
        cout << endl;
    }    
}