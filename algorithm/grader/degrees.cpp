#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> vt(n,0);
    map<int,int> sol;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        int x;
        cin >> x;
        if(x) vt[i]++;
    }

    sort(vt.begin(),vt.end());

    for(int i=0;i<=vt[n-1];i++) sol[i] = 0;
    for(int i : vt) sol[i]++;
    for(int i=0;i<=vt[n-1];i++) cout << sol[i] << ' ';
}