// https://codeforces.com/problemset/problem/1016/C

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

const int maxn = 300500;
int n;

int a[2][maxn];
// int preftop[maxn], prefbot[maxn], suftop[maxn], sufbot[maxn];

// these all assume time 0
int pref[2][maxn], suf[2][maxn];
int psa[2][maxn];

int f(int i, int j, int time) {
    if(j == n+1) {
        return 0;
    }

    int val = f(i^1, j+1, time+2) + a[i^1][j]*(time+1) + a[i^1][j+1]*(time+2);
    int val2 = (pref[i][n]-pref[i][j]) + (time-j)*(psa[i][n] - psa[i][j]) + 
                suf[i^1][j] + (time+n-j) * (psa[i^1][n] - psa[i^1][j-1]);

    return max(val, val2);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for(int i = 0; i <= 1; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            psa[i][j] = psa[i][j-1]+a[i][j];
        }
    }

    for(int i = 0; i <= 1; i++) {
        for(int j = 1; j <= n; j++) {
            pref[i][j] = pref[i][j-1] + a[i][j]*j;
            suf[i][n-j+1] = suf[i][n-j+2] + a[i][n-j+1]*j;
        }
    }

    for(int i = 0; i <= 1; i++) {
        for(int j = 1; j <= n; j++) {
            cerr << suf[i][j] << " ";
        }
        cerr << endl;
    }

    cout << f(0, 1, 0) << endl;
}

/*

each subproblem is a rectangle with one corner already taken

can either go:
    - up/down and then right into another subproblem
    - right, up/down, left

base cases are a[n][0], a[n][1] which would just be the values at those cells

doing recursion because transitions are hard

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
