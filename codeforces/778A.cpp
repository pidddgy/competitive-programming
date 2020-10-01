// https://codeforces.com/contest/778/problem/A

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

const int maxn = 200500;
bool bad[maxn];
int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    int n = sz(s);
    s = "."+s;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int l = 0, r = n;
    int lgood = -1;
    while(l <= r) {
        int mid = (l+r)/2;
        for(int j = 1; j <= mid; j++) {
            bad[a[j]] = true;
        }

        queue<char> Q;
        for(char x: t) Q.push(x);

        for(int i = 1; i <= n; i++) {
            if(!bad[i] and s[i] == Q.front()) Q.pop();
            if(Q.empty()) break;
        }

        if(Q.empty()) {
            lgood = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }

        for(int j = 1; j <= mid; j++) {
            bad[a[j]] = false;
        }
    }

    assert(lgood != -1);
    cout << lgood << endl;
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
