#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n; cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    vector<vector<pair<int,ll>>> vt(n);

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            ll w = arr[i] ^ arr[j];
            vt[i].push_back({j,w});
            vt[j].push_back({i,w});
        }
    }

    priority_queue<pair<ll,int>> pq;
    pq.push({0,0});
    vector<int> vs(n,0);
    int sol = 0;

    while(!pq.empty()){
        auto [w,node] = pq.top(); pq.pop();
        if(vs[node]) continue;
        vs[node] = 1;
        sol += w;
        for(auto [nextnode,nextw] : vt[node]){
            if(!vs[nextnode]) pq.push({nextw,nextnode});
        }
    }
    cout << sol;
}