#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<vector<pair<int,int>>> vt(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x; cin >> x;
            if(x == -1 || x == 0) continue;
            vt[i].push_back({x,j});
        }
    }

    int sol[n];
    for(int i=0;i<n;i++) sol[i] = INT_MAX;
    
    sol[0] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        auto [val,node] = pq.top(); pq.pop();
        if(val > sol[node]) continue;

        for(auto i : vt[node]){
            auto [v,nd] = i;
            if(v+val < sol[nd]){
                sol[nd] = v+val;
                pq.push({v+val,nd});
            }
        }
    }

    int mx = 0;
    for(int i=0;i<n;i++){
        mx = max(mx,sol[i]);
    }
    cout << mx;
}