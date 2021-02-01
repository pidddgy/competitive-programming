// https://codeforces.com/problemset/problem/110/E

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

int car[maxn];
int disj[maxn];

int findp(int n) {
    if(disj[n] == n) return n;
    else return disj[n] = findp(disj[n]);
}

void merge(int a, int b) {
    int c = findp(a), d = findp(b);
    if(c == d) return;

    disj[c] = d;
    car[d] += car[c];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        disj[i] = i;
        car[i] = 1;
    }

    int n;
    cin >> n;

    for(int i = 1; i <= n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        bool lucky = true;
        for(char x: to_string(w)) {
            if(x != '4' and x != '7') lucky = false;
        }

        if(lucky) continue;

        merge(u, v);
    }

    int ans = 0;    
    for(int i = 1; i <= n; i++) {
        int o = n-car[findp(i)];

        cerr << i << " contributes " << o*(o-1) << endl;
        watch(o)
        ans += o*(o-1);
    }

    cout << ans << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
