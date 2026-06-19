#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[n][n];

    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> arr[i][j];

    
    int sol = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int sum = 0,x = i,y = j;
            while(x != n && y != n){
                sum += arr[x++][y++];
            }
            sol = max(sol,sum);
        }
    }
    cout << sol;
}