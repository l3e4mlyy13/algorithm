#include <bits/stdc++.h>
using namespace std;

map<int,vector<int>> mp;
int n;

void recur(int c,vector<int> vt,int vs[]){
    if(c == n){
        for(int i : vt) cout << i << ' ';
        cout << endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(vs[i]) continue;
        int ch = 1;
        for(int j : mp[i]){
            if(vs[j]) ch = 0;
        }
        if(!ch) continue;
        vs[i] = 1;
        vt.push_back(i);
        recur(c+1,vt,vs);
        vs[i] = 0;
        vt.pop_back();
    }
}

int main(){
    int m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        mp[a].push_back(b);
    }
    int vs[n];
    for(int i=0;i<n;i++) vs[i] = 0;
    recur(0,{},vs);    
}