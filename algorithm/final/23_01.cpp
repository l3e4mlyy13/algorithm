#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e; cin >> n >> e;
    int ci[n],co[n];
    for(int i=0;i<n;i++) cin >> ci[i];
    for(int i=0;i<n;i++) cin >> co[i];
    vector<vector<int>> vt(n);
    for(int i=0;i<e;i++){
        int a,b; cin >> a >> b;
        vt[a].push_back(b);
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> sol(n,INT_MAX);
    sol[0] = 0;
    pq.push({0,0});
    while(!pq.empty()){
        auto [w,node] = pq.top(); pq.pop();
        if(w > sol[node]) continue;
        for(auto i : vt[node]){
            int fee = w+co[node]+ci[i];
            if(fee < sol[i]){
                sol[i] = fee;
                pq.push({fee,i});
            }
        }
    }
    for(int i : sol){
        if(i == INT_MAX) cout << -1 << ' ';
        else cout << i << ' ';
    }
}