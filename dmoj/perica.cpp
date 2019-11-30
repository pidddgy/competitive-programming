// https://dmoj.ca/problem/coci15c5p3

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define MOD 1000000007 
#define maxn 100005
#define maxk 55
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define endl '\n'
using namespace std;


ll pascal[maxn][maxk];

ll choose(ll n, ll k) {
    if(k>n) return 0;
    else return pascal[n][k];
}

int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);


    ll N, K;
    cin >> N >> K;

    for(int line = 0; line <= N+3; line++) {
        for(int i = 0; i <= maxk; i++) {
            if(line == i or i == 0) {
                pascal[line][i] = 1;
            } else {
                pascal[line][i] = pascal[line-1][i-1] + pascal[line-1][i];
            }

            pascal[line][i] %= MOD;
        }
    }



    map<ll, ll> cnt;
    for(ll i = 0; i < N; i++) {
        ll a; cin >> a;
        cnt[a]++;
    }

    ll other = 0;
    ll ans = 0;
    for(auto x: cnt) {
        other += x.se;

        for(int i = 0; i < x.se; i++) {
            ans += (choose(other-1-i, K-1)) * x.fi;
            ans %= MOD;
        }
    }
    
    cout << ans << endl;
}