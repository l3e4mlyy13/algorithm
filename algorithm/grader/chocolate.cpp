#include <bits/stdc++.h>
using namespace std;

int main(){
    int k,n; cin >> k >> n;
    long long dt[n],dp[k+5];
    for(int i=0;i<n;i++) cin >> dt[i];

    for(int i=1;i<=k;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            if(i-dt[j] < 0) continue;
            else if(i-dt[j] == 0) sum++;
            else sum += dp[i-dt[j]];
        }
        dp[i] = sum%1000003;
    }
    cout << dp[k];
}