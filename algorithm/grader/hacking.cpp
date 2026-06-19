#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k; cin >> n >> m >> k;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int, int>>> pq;
    vector<vector<int>> vt(n);
    int hack[k],time[n],vs[n];
    for(int i=0;i<k;i++) cin >> hack[i];
    for(int i=0;i<n;i++){
        cin >> time[i];
        vs[i] = 0;
    }
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        vt[a].push_back(b);
        vt[b].push_back(a);
    }
    for(int i=0;i<k;i++){
        pq.push({time[hack[i]],hack[i]});
        vs[hack[i]] = 1;
    }
    int sol = 0;
    while(!pq.empty()){
        auto [t,node] = pq.top();
        pq.pop();
        for(auto i : vt[node]){
            if(!vs[i]){
                int x = t+time[i];
                pq.push({x,i});
                vs[i] = 1;
                sol = max(sol,x);
            }
        }
    }
    cout << sol;
}