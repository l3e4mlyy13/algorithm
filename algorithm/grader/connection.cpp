#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e,k; cin >> n >> e >> k;
    vector<vector<int>> vt(n);
    for(int i=0;i<e;i++){
        int a,b; cin >> a >> b;
        vt[a].push_back(b);
        vt[b].push_back(a);
    }
    int sol = 0;
    for(int i=0;i<n;i++){
        queue<pair<int,int>> q;
        vector<int> vs(n,0);
        q.push({i,0});
        int c = 0;
        while(!q.empty()){
            auto [node,d] = q.front(); q.pop();
            if(d > k || vs[node]) continue;;
            vs[node] = 1;
            c++;
            for(int n_node : vt[node]){
                if(vs[n_node]) continue;
                q.push({n_node,d+1});
            }
        }
        sol = max(sol,c);
    }
    cout << sol;
}