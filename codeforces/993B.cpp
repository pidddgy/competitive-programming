// https://codeforces.com/contest/993/problem/B

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
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

const int maxn = 15;

int shared(pii x, pii y) {
    map<int, int> cnt;
    cnt[x.fi]++;
    cnt[x.se]++;
    cnt[y.fi]++;
    cnt[y.se]++;

    for(pii x: cnt) {
        if(x.se == 2) return x.fi;
    }

    return -1;
}


int n, m;
// number of valid outcomes
map<pii, set<int>> cnta, cntb;
vector<pii> a, b;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        pii x;
        cin >> x.fi >> x.se;

        a.emplace_back(x);
    }

    for(int i = 1; i <= m; i++) {
        pii x;
        cin >> x.fi >> x.se;

        b.emplace_back(x);
    }

    set<int> S;
    for(pii x: a) {
        for(pii y: b) {
            if(shared(x, y) == -1) continue; // 0 shared
            if(x == y) continue; // 2 shared

            int s = shared(x, y);

            cerr << x.fi << "," << x.se << " " << y.fi << "," << y.se << endl;
            watch(s)
            cerr << endl;

            cnta[x].emplace(s);
            cntb[y].emplace(s);

            S.emplace(s);
        }
    }

    if(sz(S) == 1) {
        cout << *S.begin() << endl;
    } else {
        bool ok = true;
        for(pii x: a) {
            if(sz(cnta[x]) > 1) ok = false;
        }

        for(pii x: b) {
            if(sz(cntb[x]) > 1) ok = false;
        }

        if(ok) {
            cout << 0 << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

/*

i n t e n s e brute force

maintain set of possible shared numbers

for each pair calculate number of possible outcomes



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
