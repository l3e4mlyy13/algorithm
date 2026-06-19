#include <bits/stdc++.h>
using namespace std;

int main(){
    int k; cin >> k;
    for(int i=0;i<k;i++){
        int n,e; cin >> n >> e;
        vector<vector<int>> vt(n);
        stack<pair<int,int>> sk;
        int vs[n];
        for(int j=0;j<e;j++){
            int a,b; cin >> a >> b;
            vt[a].push_back(b);
            vt[b].push_back(a);
            vs[i] = 0;
        }

        sk.push({0,0});
        int ch = 0;
        while(!sk.empty()){
            auto [node,par] = sk.top(); sk.pop();
            vs[node] = 1;
            for(int j : vt[node]){
                if(j == par) continue;
                if(vs[j]){
                    cout << "YES\n";
                    while (!sk.empty()) sk.pop();
                    ch = 1;
                    break;
                }
                sk.push({j,node});
            }
        }
        if(!ch) cout << "NO\n";
    }
}