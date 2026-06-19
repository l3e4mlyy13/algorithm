#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j) dp[j]++;
            else if(j >= i) dp[j] += dp[j-i];
        }
    }
    cout << dp[n];
}