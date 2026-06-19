#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin >> n >> m;
    vector<int> vt;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        vt.push_back(a);
    }
    sort(vt.begin(),vt.end());
    for(int i=0;i<m;i++){
        int a; cin >> a;
        int l=0,r=n-1,mid,ans=-1;
        while(l <= r){
            mid = l+(r-l)/2;
            if(vt[mid] <= a){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        cout << r << endl;
    }
}
