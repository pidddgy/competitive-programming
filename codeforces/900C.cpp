// https://codeforces.com/contest/900/problem/C

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

const int maxn = 100500;

int a[maxn];
bool record[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ma = INT_MIN, ma2 = INT_MIN;
    map<int, int> cnt;
    cnt[a[1]] = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] > ma) {
            record[i] = true;
        } else if((a[i] <= ma) and (a[i] > ma2) and (ma != INT_MIN)) {
            cnt[ma]++;
        }

        if(a[i] > ma) {
            ma2 = ma;
            ma = a[i];
        } else if(a[i] > ma2) {
            ma2 = a[i];
        }
    }

    int add = INT_MIN;
    int ans = INT_MAX;

    for(int i = 1; i <= n; i++) {
        int val = cnt[a[i]] - record[i];

        if(val > add) {
            add = val;
            ans = a[i];
        } else if(val == add and a[i] < ans) {
            ans = a[i];
        }
    }

    cout << ans << endl;
}

/*

for num in list
    keep track of biggest and second biggest number

    if number is smaller than biggest number and greater than second biggest number 
        increment biggest number

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
