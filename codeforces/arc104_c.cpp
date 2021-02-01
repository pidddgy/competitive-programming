// https://atcoder.jp/contests/arc104/tasks/arc104_c

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

vector<pii> v;
int n;

void no() {
    cout << "No" << endl;
    exit(0);
}

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed);

void go(vector<pii> state) {
    int a[2*n+5];
    for(int i = 0; i < 2*n+5; i++) {
        a[i] = -1;
    }

    // check that the state works right now
    for(pii x: state) {
        if(x.fi == -1 or x.se == -1) continue;

        int c = x.se-x.fi-1;

        for(int i = x.fi; i <= x.se; i++) {
            if(a[i] != -1 and a[i] != c) return;

            a[i] = c;
        }

        // if(x.fi >= x.se) return;
    }

    // fill in any people that are guaranteed
    for(pii x: state) {
        if(x.se == -1) {
            if(a[x.fi] != -1) {
                int c = a[x.fi];
                x.se = x.fi+c+1;
            }
        }

        if(x.fi == -1) {
            if(a[x.se] != -1) {
                int c = a[x.fi];
                x.fi = x.se-c-1;
            }
        }
    }

    bool ok = true;

    // check again
    for(pii x: state) {
        if(x.fi == -1 or x.se == -1) {
            ok = false;
            continue;
        }

        int c = x.se-x.fi-1;

        for(int i = x.fi; i <= x.se; i++) {
            if(a[i] != -1 and a[i] != c) {
                return;
            }
        }
    }

    if(ok) {
        cout << "Yes" << endl;
        exit(0);
    }


    for(int i = 0; i < sz(state); i++) {
        vector<pii> cpy = state;
        bool change = false;
        if(cpy[i].fi == -1) {
            cpy[i].fi = (mt()%(2*n))+1;
            change = true;
        }

        if(change) {
            go(cpy);
        }
    }

    for(int i = 0; i < sz(state); i++) {
        vector<pii> cpy = state;
        bool change = false;
        if(cpy[i].se == -1) {
            cpy[i].se = (mt()%(2*n))+1;
            change = true;
        }

        if(change) {
            go(cpy);
        }
    }


}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        pii x;
        cin >> x.fi >> x.se;

        v.emplace_back(x);
        if(x.fi > x.se and x.fi != -1 and x.se != -1) no();
    }

    go(v);
    no();
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
