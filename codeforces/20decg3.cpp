#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
// #define cerr cout
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

const int maxn = 205;

int n;

const int seed = 696969697;
const int MOD = (int)1e9+7;
const int MOD2 = (int)1e9+9;

map<int, int> ac;

pii a[maxn];
set<pii> S;

set<int> masks;

void go(int i, int j, int ii, int jj) {
    pii f = {min(i, ii), min(j, jj)};
    pii s = {max(i, ii), max(j, jj)};

    vector<pii> v;
    int mask = 0;

    int h = 0;
    int h2 = 0;

    int spow = 1;
    int spow2 = 1;

    for(int k = 1; k <= n; k++) {
        int x = a[k].fi, y = a[k].se;

        if((f.fi <= x and x <= s.fi) and (f.se <= y and y <= s.se)) {
            mask |= (1LL << (k-1));
            h += k*spow;
            h2 += k*spow2;

            spow *= seed;
            spow %= MOD;

            spow2 *= seed;
            spow2 %= MOD;

            h %= MOD;
            h2 %= MOD2;

            h += k*spow;
            h2 += k*spow2;
            
            spow *= seed;
            spow %= MOD;

            spow2 *= seed;
            spow2 %= MOD;

            h %= MOD;
            h2 %= MOD2;
        }
    }

    masks.emplace(mask);
    S.emplace(h, h2);
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<int> cmp;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
        // cmp.emplace_back(a[i].fi, a[i].se);
        cmp.emplace_back(a[i].fi);
        cmp.emplace_back(a[i].se);
    }

    sort(all(cmp));

    int cur = 0;
    for(int i = 0; i < sz(cmp); i++) {
        if(i == 0 or cmp[i] != cmp[i-1]) {
            ac[cmp[i]] = ++cur;
        }
    }

    for(int i = 1; i <= n;i++) {
        for(int j = 1; j <= n; j++) {
            pii in = {min(a[i].fi, a[j].fi), min(a[i].se, a[j].se)};
            int ver = abs(a[i].fi-a[j].fi);
            int hor = abs(a[i].se-a[j].se);

            vector<int> v;
            for(int k = 1; k <= n; k++) {
                v.emplace_back(max(abs(a[k].fi-in.fi), abs(a[k].se-in.se)));
            }

            sort(all(v));

            for(pii p: {in, {in.fi+ver, in.se}, {in.fi, in.se+hor}, {in.fi+ver, in.se+hor}}) {
                for(int x: v) {
                    // top left
                    go(p.fi, p.se, p.fi-x, p.se-x);

                    // top right
                    go(p.fi, p.se, p.fi-x, p.se+x);

                    // bottom left
                    go(p.fi, p.se, p.fi+x, p.se-x);

                    // bottom right
                    go(p.fi, p.se, p.fi+x, p.se+x);
                }
            }

        }
    }

    S.emplace(pii(0, 0));
    cout << sz(S) << endl;

    watch(sz(masks))
    for(int x: masks) {
        cerr << "can take " << bitset<5>(x) << endl;
    }
}

/*

observation: the square for a subset must have at least two cows on the edges
otherwise you could reduce the square by 1

brute force on insection point
push into top left, top right, bottom left, bottom right queue 

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
