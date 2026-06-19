#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k,n; cin >> k >> n;
    int c[k+5],a[k],dp[n+5];
    for(int i=1;i<=k;i++) cin >> c[i];
    for(int i=0;i<k;i++){
        cin >> a[i];
        dp[i] = a[i];
    }

    for(int i=k;i<=n;i++){
        ll sum = 0;
        for(int j=1;j<=k;j++){
            sum += (c[j]*dp[i-j]%32717)%32717;
            sum %= 32717;
        }
        dp[i] = sum;
    }
    cout << dp[n];
}