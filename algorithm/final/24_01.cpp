#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

void recur(int n,int a,int b,int c,string sol){
    if(sol.size() == n){
        ans.push_back(sol);
        return;
    }
    if(a > 0) recur(n,a-1,b,c,sol+'A');
    if(b > 0) recur(n,a,b-1,c,sol+'B');
    if(c > 0) recur(n,a,b,c-1,sol+'C');
}

int main(){
    int n,a,b,c; cin >> n >> a >> b >> c;
    recur(n,a,b,c,"");
    cout << ans.size() << endl;
    for(string i : ans) cout << i << endl;
}