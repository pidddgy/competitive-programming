// https://codeforces.com/contest/448/problem/C

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

const int maxn = 5500;

int a[maxn];
int n, ans;

int f(int l, int r, int rem) {
    int mi = INT_MAX;
    int freq = 0;

    for(int i = l; i <= r; i++) {
        if(a[i]-rem < mi) {
            freq = 1;
            mi = a[i]-rem;
        } else if(a[i]-rem == mi) freq++;
    }
    
    int hor = 0;

    int last = -1;
    int cnt = 0;
    for(int i = l; i <= r; i++) {
        if(a[i]-rem == mi) {
            if(last != -1) {
                hor += f(last, i-1, rem+mi);
                cnt++;
                last = -1;
            }
        }

        if(a[i]-rem != mi and last == -1) {
            last = i;
        }
    }

    if(last != -1) {
        hor += f(last, r, rem+mi);
        cnt++;
    }
    
    hor += mi;
    
    return min(hor, r-l+1);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ans = n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cout << f(1, n, 0) << endl;
}

/*
recursion, split into pieces

it is worth doing some horizontal paints if occurences of min >= min
    -> removes # of min - min

worst case is if we split into only one piece each time (1, 2, 3, 4, 5, 6....)

o(n^2)
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?