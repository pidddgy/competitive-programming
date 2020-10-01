// https://codeforces.com/contest/1107/problem/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

int conv(char hex) {
    return isdigit(hex) ? hex - '0' : hex - 'A' + 10;
}

const int maxn = 5300;

int a[maxn][maxn];
int psa[maxn][maxn];

// i, j = top left, ii, jj = bottom right
int query(int i, int j, int ii, int jj) {
    return psa[ii][jj] - psa[ii][j-1] - psa[i-1][jj] + psa[i-1][j-1];
}

set<int> factors(int n) {
    set<int> res;
    for(int i = 2; i*i <= n; i++) {
        while(n % i == 0) {
            res.emplace(i);
            n /= i;
            // watch(n)
        }
    }

    if(n != 1) {
        res.emplace(n);
    }

    return res;
}

int n;
int ans = 1;

void go(int prime) {
    if(ans == n) return;
    watch(prime)
    int l = 1;
    int r = 5200;
    int lgood = -1;

    while(l <= r) {
        int m = (l + r) / 2;
        int sz = m*prime;

        if(n % sz) {
            r = m-1;
            continue;
        }

        cerr << "currently trying size " << sz << endl;

        bool ok = true;
        int x = 1;
        for(int i = 1; i <= n/sz; i++) {
            int y = 1;
            for(int j = 1; j <= n/sz; j++) {
                int sum = query(x, y, x+sz-1, y+sz-1);
                if(sum != sz*sz and sum != 0) {
                    ok = false;
                }
                if(!ok) break;
                y += sz;
            }
            if(!ok) break;
            x += sz;
        }

        if(ok) {
            ans = max(ans, sz);
            if(ans == n) return;
            l = m+1;
        } else {
            r = m-1;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        int ree = 1;
        for(int j = 1; j <= n/4; j++) {
            int val = conv(s[j-1]);

            for(int k = 0; k <= 3; k++) {
                a[i][ree+k] = (bool)((1 << (3-k))&val);
            }

            ree += 4;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + a[i][j];
            // cerr << a[i][j] << " ";
        }
        // cerr << endl;
    }

    for(int x: factors(n)) go(x);

    cout << ans << endl;
}

/*
11100111
11100111
11100111
00000000
00000000
11100111
11100111
11100111

observation: if a 2x-compression is possible then an x-compression is possible

do a sieve like thing where we bsearch on every prime number

time complexity: n^2 * 392 * log(n) or something
    - actual time complexity is a lot less because primes grow fast

wait no im actually retarded its like n^2 * 6 * logn
hope to god this doesnt tle
probably hard to make strong data for this anyway

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?