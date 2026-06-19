#include <bits/stdc++.h>
using namespace std;

int grid[11][11],vs[11][11];
int r,c;

void recur(int x,int y,string sol){
    if(x == r && y == c){
        cout << sol << endl;
        return;
    }
    if(x == 0 || y == 0 || x == r+1 || y == c+1 || vs[x][y] || grid[x][y]) return;
    vs[x][y] = 1;
    recur(x,y+1,sol+'A');
    vs[x][y+1] = 0;
    recur(x+1,y,sol+'B');
    vs[x+1][y] = 0;
    recur(x-1,y,sol+'C');
    vs[x-1][y] = 0;
}

int main(){
    cin >> r >> c;
    for(int i=1;i<=r;i++) for(int j=1;j<=c;j++) cin >> grid[i][j];
    recur(1,1,"");
    cout << "DONE";
}