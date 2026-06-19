#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k; cin >> n >> m >> k;
    int sum_price[n],sum_grass[n];

    for(int i=0;i<n;i++) cin >> sum_grass[i];
    for(int i=1;i<n;i++) sum_grass[i] += sum_grass[i-1];
    sum_price[0] = sum_grass[0]+k;
    for(int i=1;i<n;i++) sum_price[i] = sum_price[i-1]+sum_grass[i]-sum_grass[i-1]+k;

    for(int i=0;i<m;i++){
        int a;
        ll b;
        cin >> a >> b;
        ll tb = (a == 0) ? b : (b+sum_price[a-1]);
        auto it = upper_bound(sum_price, sum_price+n, tb);
        int idx = (it-1)-sum_price;
        ll  e = (a == 0) ? 0 : sum_grass[a-1];
        if(it == sum_price) cout << 0 << '\n';
        else cout << sum_grass[idx]-e << '\n';
    }
}