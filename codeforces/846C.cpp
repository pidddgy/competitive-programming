// https://codeforces.com/problemset/problem/846/C

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
// #define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 5050;

int a[maxn];
int psa[maxn];
int ma = LLONG_MIN;

vector<int> v;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        psa[i] = psa[i-1] + a[i];
    }

    for(int j = 1; j <= n+1; j++) {
        int sum = 0, loc = LLONG_MIN;
        int l, r;
        for(int i = 1; i <= j; i++) {
            int val = psa[i-1] - (psa[j-1] - psa[i-1]);

            if(val > loc) {
                loc = val;
                l = i;
            }
        }

        sum += loc;
        loc = LLONG_MIN;

        for(int k = j; k <= n+1; k++) {
            int val = (psa[k-1] - psa[j-1]) - (psa[n] - psa[k-1]);
            if(val > loc) {
                loc = val;
                r = k;
            }
        }

        sum += loc;

        if(sum > ma) {
            ma = sum;
            v = {l-1, j-1, r-1};
        }
    }

    for(int i = 0; i < 3; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

/*

do interval dp

dp[i][j] = max sum possible for this range
dp2[i][j] = delimiter

all ranges are non inclusive on the right side

we brute force on the two inner segments, then we know that the 2 outmost segments have to be to end

use psa for outer two segments

7
1 3 -2 -7 1 -3 9

dp[0][n] = 7



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
