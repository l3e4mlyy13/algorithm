#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n,a; cin >> n >> a;
    int cf[n];
    for(int i=0;i<n;i++) cin >> cf[i];

    while(a--){
        ll q; cin >> q;
        ll l=0,r=1e15,x,ans = r;
        while(l <= r){
            x = (r+l)/2;
            ll sum = 0;
            for(int i=0;i<n;i++){
                sum += floor(x/cf[i])+1;
                if(sum > q) break;
            }
            if(sum < q) l = x+1;
            else{
                ans = x;
                r = x-1;
            }
            
        }
        cout << ans << endl;
    }
}