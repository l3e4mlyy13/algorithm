#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e,s; cin >> n >> e >> s;
    vector<tuple<int,int,int>> vt;
    for(int i=0;i<e;i++){
        int a,b,c; cin >> a >> b >> c;
        vt.push_back({a,b,c});
    }

    vector<int> dist(n,INT_MAX);
    dist[0] = 0;

    for(int i=1;i<n;i++){
        for(auto [a,b,w] : vt){
            dist[b] = min(dist[b],dist[a]+w);
        }
    }
    int ch = 0;
    for(auto [a,b,w] : vt){
        if(dist[b] > dist[a]+w){
            ch = 1;
            break;
        }
    }
    if(ch) cout << -1;
    else{
        for(int i : dist) cout << i << ' ';
    }
}