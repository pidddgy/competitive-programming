// https://codeforces.com/contest/1457/problem/E

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

const int maxn = 500500;

int n, k;
int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a+1, a+n+1, greater<int>());

    priority_queue<int> pq;

    for(int i = 1; i <= k+1; i++) {
        pq.push(0);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int x = pq.top();
        ans += x;

        pq.pop();
        pq.push(a[i]+x);
    }

    cout << ans << endl;
}

/*

subproblem where k = 1

brute force



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
