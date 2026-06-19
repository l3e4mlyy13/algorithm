#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<int,int>> vt(n);
    int s,f;
    for(int i=0;i<n;i++){
        cin >> s;
        vt[i].second = s;
    } 
    for(int i=0;i<n;i++){
        cin >> f;
        vt[i].first = f;
    } 
    sort(vt.begin(),vt.end());
    int sol = 0;
    int cl = 0;
    for(auto [fi,st] : vt){
        if(cl <= st){
            sol++;
            cl = fi;
        }
    }
    cout << sol;
}