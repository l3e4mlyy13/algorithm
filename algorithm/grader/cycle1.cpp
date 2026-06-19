#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<vector<int>> vt(n);
    stack<pair<int,int>> sk;
    int vs[n],sum[n];
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        vt[a].push_back(b);
        vt[b].push_back(a);
        vs[i] = 0;
        sum[i] = 0;
    }

    sk.push({0,0});
    while(!sk.empty()){
        auto [node,par] = sk.top(); sk.pop();
        vs[node] = 1;
        for(int i : vt[node]){
            if(i == par) continue;
            if(vs[i]){
                cout << sum[node]-sum[i]+1;
                return 0;
            }
            sum[i] = sum[node]+1;
            sk.push({i,node});
        }
    }
}