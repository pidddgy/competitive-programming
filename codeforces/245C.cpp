// https://codeforces.com/contest/245/problem/C

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

void no() {
    cout << -1 << endl;
    exit(0);
}

const int maxn = 105;
int n;
int a[maxn];

bool ok(int x) {
    return (x >= 1) and (x*2+1 <= n);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;


    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    } 

    int ans = 0;
    for(int i = n; i >= 1; i--) {
        while(a[i]) {
            ans++;
            if(ok(i/2)) {
                if(a[i/2]) a[i/2]--;
                if(a[(i/2)*2]) a[(i/2)*2]--;
                if((a[(i/2)*2 + 1])) a[(i/2)*2 + 1]--;
            } else if(ok(i)) {
                a[i]--;
            } else no();
        }
    }

    cout << ans << endl;
}

/*

iterate over i from n...1, imagining that all elements to the right of i are all cleared out
we want to have this be the right point of our segment. if we cannot then try to use left point. if cannot do either then print -1

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
