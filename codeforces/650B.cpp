// https://codeforces.com/contest/650/problem/B

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


const int maxn = (int)5e5+50;
int n, a, b, t;
string s;

int pre[maxn], suf[maxn];

int mod(int num) {
    return (num+n)%n;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b >> t;

    cin >> s;

    for(int i = n-1; i >= 0; i--) {
        suf[i] = suf[i+1];

        suf[i]++;
        if(s[i] == 'w') {
            suf[i] += b;
        }
    }

    int ans = 0;

    int cur = 0;
    int cost = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'w') cost += b;
        cost++;

        if(cost > t) break;

        cerr << "on " << i << endl;
        watch(cost)

        int l = i+1;
        int r = n;
        int lgood = -1;

        while(l <= r) {
            int mid = (l+r)/2;

            int s = suf[mid];

            int lf = i;
            int rf = n-mid;

            cerr << "for " << mid << " lf is " << lf << " and rf is " << rf << endl;

            if(cost + s + min(lf, rf)*a + (lf+rf)*a <= t) {
                lgood = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        int loc = i+1;
        if(lgood != -1) {
            loc += n-lgood;
                    cerr << i << " is " << loc << endl;
        cerr << endl;
        ans = max(ans, loc);
        }
    }

    cout << ans << endl;
}

/*

observation: change direction at most once

case 1: right, then switch to left
case 2: left, then switch to right

for case 1

prefix
cost of view 1


suffix sum
if i < n then assume its in the direction of i+1

remember to add if wrong direction





*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
