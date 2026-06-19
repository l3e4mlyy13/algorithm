#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    while(n--){
        int k; cin >> k;
        vector<tuple<int,int,double>> edge;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                double x; cin >> x;
                if(i == j) continue;
                edge.push_back({i,j,x});
                
            }
        }

        double dist[k];
        for(int i=0;i<k;i++) dist[i] = 1;
        for(int i=1;i<k;i++){
            for(auto [a,b,w] : edge){
                dist[b] = max(dist[b],dist[a]*w);
            }
        }
        
        int ch = 0;
        for(auto [a,b,w] : edge){
            if(dist[b] < dist[a]*w) ch = 1;
        }
        if(ch) cout << "YES\n";
        else cout << "NO\n";
    }
}