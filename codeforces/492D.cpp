// https://codeforces.com/contest/492/problem/D

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

const int maxn = 100500;
const ld eps = 1e-100;

string ans[maxn];

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cerr << fixed << setprecision(10);
    cout << fixed << setprecision(10);

    int n, x, y;
    cin >> n >> x >> y;

    deque<pii> v;    
    for(int i = 1; i <= n; i++) {
        int el;
        cin >> el;

        int em = el%(x+y);

        if(em == 0) {
            ans[i] = "Both";
        } else {
            v.emplace_back(em, i);
        }
    }

    sort(all(v));

    deque<int> a, b;

    int l = lcm(x, y);
    for(int i = 1; i <= x; i++) {
        a.emplace_back(i*(l/x));
    }

    for(int i = 1; i <= y; i++) {
        b.emplace_back(i*(l/y));
    }



    string cur = "hugs";
    int h = 0;

    while(sz(v)) {
        if(sz(a) and sz(b) and abs(a.front()-b.front()) < eps) {
            cur = "Both";
            h += 2;
            a.pop_front();
            b.pop_front();
        } else if(sz(a) and (a.front() < b.front() or b.empty())) {
            cur = "Vanya";
            h++;
            a.pop_front();
        } else if(sz(b) and (b.front() < a.front() or a.empty())) {
            cur = "Vova";
            h++;
            b.pop_front();
        }

        while(sz(v) and h >= v.front().fi) {
            ans[v.front().se] = cur;
            v.pop_front();
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
}

/*

we can mod by x+y

offline 

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
