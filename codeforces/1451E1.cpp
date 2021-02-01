// https://codeforces.com/contest/1451/problem/E1

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 68536;

int pre[maxn];
signed main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cout << "XOR " << 1 << " " << i << endl;
        cin >> pre[i];
    }

    
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
