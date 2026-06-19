#include <bits/stdc++.h>
using namespace std;

int recur(vector<int> vt){
    if(vt.size() == 2) return vt[0]+vt[1];
    vector<int> v1,v2;
    for(int i=0;i<vt.size()/2;i++){
        v1.push_back(vt[i]);
    }
    for(int i=vt.size()/2;i<vt.size();i++){
        v2.push_back(vt[i]);
    }
    int a = recur(v1), b = recur(v2);
    if(a == -1 || b == -1) return -1;
    else if(abs(a-b) <= 1){
        return a+b;
    }
    return -1;

}
int main(){
    int n,k; cin >> n >> k;
    
    for(int i=0;i<n;i++){
        vector<int> vt;
        int x;
        for(int j=0;j<pow(2,k);j++){
            cin >> x;
            vt.push_back(x);
        }
        if(recur(vt) != -1) cout << "yes\n";
        else cout << "no\n";
    }
}