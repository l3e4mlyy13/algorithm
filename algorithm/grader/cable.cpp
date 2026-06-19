#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<vector<pair<int,int>>> vt(n);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int x; cin >> x;
            vt[i].push_back({j,x});
            vt[j].push_back({i,x});
        }
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    int sol = 0;
    vector<int> vs(n,0);
    while(!pq.empty()){
        auto [w,node] = pq.top(); pq.pop();
        if(vs[node]) continue;
        vs[node] = 1;
        sol += w;
        for(auto [a,b] : vt[node]){
            if(!vs[a]) pq.push({b,a});
        }
    }
    cout << sol;
}