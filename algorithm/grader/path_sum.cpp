#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin >> n >> m;
    int ans[8];
    for(int i=0;i<8;i++) cin >> ans[i];
    vector<vector<pair<int,int>>> vt(n);
    unordered_map<int,int> sol;
    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        vt[a].push_back({b,c});
        vt[b].push_back({a,c});
    }

    
    stack<pair<int,int>> sk;
    for(int i=0;i<n;i++){
        vector<int> vs(n,0);
        sk.push({i,0});
        while(!sk.empty()){
            auto [node,val] = sk.top(); sk.pop();
            if(vs[node]) continue;
            vs[node] = 1;
            for(auto [v,w] : vt[node]){
                if(vs[v]) continue;
                int sum = w+val;
                sol[sum] = 1;
                sk.push({v,sum});
            }
        }
    }
    
    


    for(int i=0;i<8;i++){
        if(sol[ans[i]]) cout << "YES\n";
        else cout << "NO\n"; 
    }
}