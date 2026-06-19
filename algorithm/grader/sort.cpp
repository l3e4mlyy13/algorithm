#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int dt[n];
    for(int i=0;i<n;i++) cin >> dt[i];
    int sol = 0;
    for(int i=0;i<n;i++){
        int mn = dt[i],ch = 0,idx;
        for(int j=i-1;j>=0;j--){
            if(mn < dt[j]){
                dt[j] = dt[j+1];
                ch = 1;
                idx = j;
            }
        }
        if(ch){
            dt[idx] = mn;
            sol++;
        }
    }
    cout << sol;
}