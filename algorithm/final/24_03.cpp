#include <bits/stdc++.h>
using namespace std;

long long dp[1000005],dpE[1000005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    dp[1] = 3;
    dp[2] = 7;
    dpE[1] = 1;
    dpE[2] = 2;
    int mod = 100000007;
    for(int i=3;i<=n;i++){
        dpE[i] = ((dp[i-1]-(dpE[i-1]+dpE[i-2])%mod)+mod)%mod;
        dp[i] = (dp[i-1]+(2*dpE[i])%mod)%mod;
    }
    cout << dp[n];
}