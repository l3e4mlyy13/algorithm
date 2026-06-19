#include <bits/stdc++.h>
using namespace std;

int mp[12][12];

int cheak(int n,int x,int y){
    for(int i=0;i<n;i++){
        if(mp[i][y] && i != x) return 0;
    }
    for(int i=0;i<n;i++){
        if(mp[x][i] && i != y) return 0;
    }
    int a = x,b = y;
    while(a != 0 && b != 0){
        if(mp[--a][--b]) return 0;
    }
    a = x,b = y;
    while(a != n-1 && b != 0){
        if(mp[++a][--b]) return 0;
    }
    
    a = x,b = y;
    while(a != n-1 && b != n-1){
        if(mp[++a][++b]) return 0;
    }
    a = x,b = y;
    while(a != 0 && b != n-1){
        if(mp[--a][++b]) return 0;
    }
    return 1;
}

int sol(int n,int y){
    int sum = 0;
    if(y == n) return 1;
    for(int i=0;i<n;i++){
        mp[i][y] = 1;
        if(cheak(n,i,y)){
            sum += sol(n,y+1);
        }
        mp[i][y] = 0;
    }
    return sum;
}

int main(){
    int n; cin >> n;
    cout << sol(n,0);
}