// https://codeforces.com/contest/305/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
// #define cerr if(false) cerr
#define pii pair<int, int>
#define fi first
#define se second
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    map<int, int> m;
    for(int i = 1; i <= N; i++) {
        int a;
        cin >> a;

        m[a]++;
    }

    for(pii x: m) {
        if(x.se >= 2) {        
            int rem = x.se%2;

            m[x.fi+1] += (x.se-rem)/2;
            m[x.fi] = rem;
        }
    }

    int ma = 0;
    for(pii x: m) {
        ma = max(ma, x.fi);
    }

    vector<int> bits;
    for(pii x: m) {
        if(x.se != 0) {
            bits.emplace_back(x.fi);
        }
    }

    int ans = ma-bits.size()+1;

    cout << ans << endl;
}