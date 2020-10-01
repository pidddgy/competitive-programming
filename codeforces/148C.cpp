// https://codeforces.com/contest/148/problem/C

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
    cout << -1 << endl;
    exit(0);
}

vector<int> ans;
int sum = 0, ma = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    if(b == 0 and a) {
        ans.emplace_back(1);
        sum++;
    }

    ans.emplace_back(1);
    sum = 1, ma = 1;
    for(int i = 1; i <= b; i++) {
        ans.emplace_back(sum+1);
        ma = max(ma, sum+1);
        sum += sum+1;
    }

    for(int i = 1; i <= a; i++) {
        ans.emplace_back(ma+1);
        ma = max(ma, ma+1);
    }

    while(sz(ans) < n) ans.emplace_back(1);

    if(sz(ans) > n) no();

    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;
}

/*

put as big of numbers as possible to maximize sum at the start, then put numbers barely big enough to satisfy all the "oh"s

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?