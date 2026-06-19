#include <bits/stdc++.h>
using namespace std;

int n,k;

void recur(int a,int cur,int mx,string sol){
    if(a == n && mx >= k){
        cout << sol << endl;
        return;
    }
    recur(a+1,0,mx,sol+'0');
    recur(a+1,cur+1,max(mx,cur+1),sol+'1');
}

int main(){
    cin >> n >> k;
    recur(0,0,0,"");
}