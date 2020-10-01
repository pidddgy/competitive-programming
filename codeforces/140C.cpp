// https://codeforces.com/problemset/problem/140/C

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 100500;

int a[maxn];
map<int, int> cnt;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    // binary search on answer
    int l = 1, r = 1e5;
    int lgood = 0;
    
    while(l <= r) { 
        int md = (l+r)/2;

        int have = 0;
        for(pii x: cnt) {
            have += min(md, x.se);
        }

        if(have >= 3*md) {
            l = md+1;
            lgood = md;
        } else {
            r = md-1;
        }
    }

    vector<int> v;

    for(pii x: cnt) {
        for(int i = 1; i <= min(lgood, x.se); i++) v.emplace_back(x.fi);
    }

    reverse(all(v));

    cout << lgood << endl;
    for(int j = 0; j < lgood; j++) {
        cout << v[j] << " " << v[lgood+j] << " " << v[lgood*2+j] << endl;
    }
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
