// https://codeforces.com/problemset/problem/552/C

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

void no() {
    cout << "NO" << endl;
    exit(0);
}

int a[50];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int w, m;
    cin >> w >> m;

    int e = 0;
    while(m) {
        a[e++] = m%w;
        m /= w;
    }

    for(int i = 0; i <= 35; i++) {
        if(!set<int>({0, 1, w, w-1}).count(a[i])) {
            no();
        }

        if(set<int>({w, w-1}).count(a[i])) {
            a[i+1]++;
        }
    }

    cout << "YES" << endl;
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
