#include <bits/stdc++.h>
using namespace std;

void recur(vector<vector<int>> &vt,int a, int bb,int top,int bottom,int left,int right){
    if(a == 0) vt[top][left] = b;
    recur(vt,a-1,b);
    recur(vt,a-1,b-1);
    recur(vt,a-1,b+1);
    recur(vt,a-1,b);
}

int main(){
    int a,b; cin >> a >> b;
    vector<vector<int>> vt;
    recur(vt,a,b,0,1 << a ,0,1 << a)
}