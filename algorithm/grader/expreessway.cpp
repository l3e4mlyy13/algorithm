#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,x; cin >> n >> x;
    vector<vector<pair<int,int>>> vt(n+1);
    vt[1].push_back({x,2});
    vt[2].push_back({x,1});
    int sol[n+1];
    for(int i=1;i<=n;i++) sol[i] = INT_MAX;
    sol[1] = 0;
    for(int i=3;i<=n;i++){
        int c; cin >> c;
        for(int j=0;j<c;j++){
            int node,val; cin >> node >> val;
            vt[i].push_back({val,node});
            vt[node].push_back({val,i});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        while(!pq.empty()){
            auto [val,node] = pq.top(); pq.pop();
            if(val > sol[node]) continue;
            for(auto j : vt[node]){
                if(j.first+val < sol[j.second]){
                    sol[j.second] = j.first+val;
                    pq.push({sol[j.second],j.second});
                }
            }
        }
        cout << sol[2] << ' ';
    }
}