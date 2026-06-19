#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> recur(int n,int k,vector<ll> M){
    if(n == 1){
        vector<ll> ret;
        for(int i=0;i<4;i++){
            ret.push_back(M[i]%k);
        }
        return ret;
    }

    if(n%2==0){
        vector<ll> tmp = recur(n/2,k,M);
    
        vector<ll> ret;
        ret.push_back((tmp[0]*tmp[0]+tmp[1]*tmp[2])%k);
        ret.push_back((tmp[0]*tmp[1]+tmp[1]*tmp[3])%k);
        ret.push_back((tmp[2]*tmp[0]+tmp[3]*tmp[2])%k);
        ret.push_back((tmp[2]*tmp[1]+tmp[3]*tmp[3])%k);
        return ret;
    }
    else{
        vector<ll> tmp = recur(n/2,k,M);
    
        vector<ll> ret;
        ret.push_back((tmp[0]*tmp[0]+tmp[1]*tmp[2])%k);
        ret.push_back((tmp[0]*tmp[1]+tmp[1]*tmp[3])%k);
        ret.push_back((tmp[2]*tmp[0]+tmp[3]*tmp[2])%k);
        ret.push_back((tmp[2]*tmp[1]+tmp[3]*tmp[3])%k);
        vector<ll> ret2;
        ret2.push_back((ret[0]*M[0]+ret[1]*M[2])%k);
        ret2.push_back((ret[0]*M[1]+ret[1]*M[3])%k);
        ret2.push_back((ret[2]*M[0]+ret[3]*M[2])%k);
        ret2.push_back((ret[2]*M[1]+ret[3]*M[3])%k);
        return ret2;
    }
}

int main(){
    int n,k; cin >> n >> k;
    vector<ll> vt;
    for(int i=0;i<4;i++){
        ll x; cin >> x;
        vt.push_back(x%k);
    }
    for(ll i : recur(n,k,vt)) cout << i << ' ';
}