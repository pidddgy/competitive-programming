// https://cses.fi/problemset/task/1618

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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, int> cnt;
    int tmp = n;

    while(tmp/2) {
        cnt[2] += tmp/2;
        tmp /= 2;
    }

    tmp = n;
    while(tmp/5) {
        cnt[5] += tmp/5;
        tmp /= 5;
    }

    cout << min(cnt[2], cnt[5]) << endl;
}

/*
5 10 15 20 25 30 35 40 45 50 55

5 25 75

2 4 6 8 10 12 14 16 18 20
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
