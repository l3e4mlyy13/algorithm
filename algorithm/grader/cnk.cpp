#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k; cin >> n >> k;
    long long dp[n+1][k+1];

    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(j == 0 || i == j) dp[i][j] = 1;
            else if(i >= 2 && j >= 1)dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            else dp[i][j] = 0;
        }
    }
    cout << dp[n][k];
}