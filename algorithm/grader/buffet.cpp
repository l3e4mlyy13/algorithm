#include <bits/stdc++.h>
using namespace std;

int main(){
    int f,w,n; cin >> f >> w >> n;
    vector<int> dt;

    for(int i=0;i<f;i++){
        int x; cin >> x;
        dt.push_back(x);
    }

    sort(dt.begin(),dt.end());
    int sol = 0,x = 0;
    for(int i : dt){
        if(i <= x) continue;
        x = i+w*2;
        sol++;
    }
    cout << sol;
}