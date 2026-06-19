#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e; cin >> n >> e;
    vector<vector<int>> vt(n);
    vector<int> vs(n,0);
    for(int i=0;i<e;i++){
        int a,b; cin >> a >> b;
        vt[a].push_back(b);
        vt[b].push_back(a);
    }
    
    int sol = 0;
    for(int i=0;i<n;i++){
        if(vs[i]) continue;
        queue<int> q;
        int ch = 1;
        q.push(i);
        vs[i] = 1;
        int edge = 0, v = 0;
        while(!q.empty()){
            int node = q.front(); q.pop();
            v++;
            for(int j : vt[node]){
                edge++;
                if(vs[j]) continue;
                q.push(j);
                vs[j] = 1;
            }
        }
        if(v-edge/2 == 1) sol++;
    }
    cout << sol;
}