// https://codeforces.com/problemset/problem/718/A

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
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

int n, t;

const int maxn = 200500;

int dp[maxn];
char s[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;

    // what index the period comes right before
    int period = '?';

    for(int i = 1; i <= n-1; i++) {
        char x;
        cin >> x;

        if(x == '.') {
            period = i;
            i--;
        } else {
            s[i] = x;
        }
    }

    for(int i = 1; i <= n-1; i++) {
        cerr << s[i];
    }
    cerr << endl;

    dp[n-1] = INT_MAX;

    for(int i = n-1; i >= 1; i--) {
        if(s[i+1] >= '5') {
            dp[i] = 1;
        } else if(s[i+1] == '4') {
            dp[i] = dp[i+1]+1;
        } else {
            dp[i] = INT_MAX;
        }
    }

    for(int i = 1; i <= n-1; i++) {
        cerr << dp[i] << " ";
    }
    cerr << endl;

    int ind = -1;
    for(int i = n-1; i >= period-1; i--) {
        if(dp[i] <= t) ind = i;
    }

    // check if we hit a digit that isn't 9 at any point
    bool carry = true;
    if(ind != -1) {
        for(int i = ind; i >= 1; i--) {
            if(s[i] == '9') {
                s[i] = '0';
            } else {
                carry = false;
                s[i]++;
                break;
            }
        }
    } else carry = false;

    if(carry) {
        cout << 1;
    }

    for(int i = 1; i <= ((ind == -1)?n-1:ind); i++) {
        if(i == period) {
            cout << ".";
        }

        cout << s[i];
    }
    cout << endl;
}

/*
observation: each digit can be raised by at most 1

keep track of where the period is 
dp[i] = max needed to raise this one up
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
