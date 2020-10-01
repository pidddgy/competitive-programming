// https://codeforces.com/contest/827/problem/B

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

const int maxn = 200500;

// A = node, b = count
int a[maxn], b[maxn];
int cur = 2;
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    
    for(int i = 1; i <= k; i++) {
        a[i] = 1;
    }

    n--;
    vector<pii> edges;
    while(n) {
        for(int i = 1; i <= k; i++) {
            if(n) {
                edges.emplace_back(a[i], cur);
                a[i] = cur;
                b[i]++;
                cur++;
                n--;
            }
        }
    }

    sort(b+1, b+k+1, greater<int>());

    cout << b[1] + b[2] << endl;
    for(pii x: edges) {
        cout << x.fi << " " << x.se << endl;
    }
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