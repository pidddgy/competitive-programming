// https://codeforces.com/contest/1397/problem/B

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
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

const int maxn = 100500;

int a[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a+1, a+n+1);

    int ans = LLONG_MAX;
    // CHANGE WHEN SUBMITTING
    for(int i = 1; i <= 1e5; i++) {
        int p = 1;
        bool ok = true;
        int cost = 0;

        // check for overflow
        for(int j = 1; j <= n; j++) {
            watch(p)
            cost += abs(a[j]-p);

            if(j <= 1e18 / p) {
                p *= i;
            } else {
                ok = false;
                break;
            }
        }

        if(!ok) break;

        cerr << "trying " << i << endl;
        watch(cost);
        ans = min(ans, cost);
    }

    cout << ans << endl;
}

/*

implicit bound problem

obviously we can just reduce all of them to 1 for power of 1

if length is, say, 50 then there can only be 1 because 2 wouldnt work



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
