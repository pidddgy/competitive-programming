// https://atcoder.jp/contests/abc165/tasks/abc165_c

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

struct quad {
    int a, b, c, d;

    quad(int aa, int bb, int cc, int dd) {
        a = aa;
        b = bb;
        c = cc;
        d = dd;
    }
};

struct Compare {
    bool operator()(Quad &l, Quad &r) {
        return l.d > r.d;
    }
};
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> ans(n+5);
    vector<quad> quads;
    for(int i = 1; i <= q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        quads.emplace_back(a, b,c, d);
    }    

    sort(all(quads), Compare());

    for(auto q: quads) {
        if(ans[q.a] == 0) ans[q.a] = 1;

        
        ans[q.b] = ans[q.a]+q.c;


    }
}

/*

put to 1 whenever possible

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
