#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin >> n >> m;
    vector<vector<int>> vt(n+1);
    int vs[n+1],sol = 0;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        vt[a].push_back(b);
    }
    for(int i=1;i<=n;i++) vs[i] = 0;

    for(int i=1;i<=n;i++){
        if(vs[i]) continue;
        sol++;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int node = q.front(); q.pop();
            for(int j : vt[node]){
                if(!vs[j]){
                    vs[j] = 1;
                    q.push(j);
                }
            }
        }
    }
    cout << sol;
}