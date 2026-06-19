#include <bits/stdc++.h>
using namespace std;

int main(){
    double w;
    int n; 
    cin >> w >> n;
    double val[n],weight[n];
    vector<tuple<double,double,double>> total;
    for(int i=0;i<n;i++) cin >> val[i];
    for(int i=0;i<n;i++) cin >> weight[i];
    for(int i=0;i<n;i++) total.push_back({val[i]/weight[i],val[i],weight[i]});
    sort(total.begin(),total.end(),greater<>());

    double sol = 0;

    for(auto [a,b,c] : total){
        if(w >= c) sol += b;
        else{
            sol += w*a;
            break;
        }
        w -= c;
    }
    cout << fixed << setprecision(4) << sol;
}