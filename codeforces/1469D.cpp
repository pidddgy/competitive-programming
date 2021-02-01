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

const int maxn = 200500;
int n;
int a[maxn];
vector<pii> ans;
void go(int x, int y) {
    // cout << x << " " << y << endl;
    ans.emplace_back(x, y);

    a[x] = (a[x]+a[y]-1)/a[y];
}

int sq(int num) {
    return num*num;
}

void solve() {
    ans.clear();
    cin >> n;
    for(int i = 1; i <= n; i++) {
        a[i] = i;
    }

    int cur = n;

    while(cur >= 3) {
        // watch(cur)
        int ind = -1;
        for(int i = cur-1;; i--) {
            if(sq(i-1) < a[cur]) {
                ind = i;
                break;
            }
        }

        for(int i = ind+1; i < cur; i++) {
            go(i, i+1);
        }
        go(cur, ind);
        go(cur, ind);

        cur = ind;
    }

    map<int, int> cnt;
    for(int i = 1; i <= n; i++) {
        // cout << a[i] << " ";
        cnt[a[i]]++;
    }

    assert(cnt[1] == n-1 and cnt[2] == 1);
    assert(sz(ans) <= n+5);

    cout << sz(ans) << endl;
    for(pii x: ans) {
        cout << x.fi << " " << x.se << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*


100 99 

100 / 99 = 2
99 / 2 = 50
50 / 2 = 25

divide second last by last to make 1

divide last by third last to make 2

1111111111111111...2

majority of them will only be using one operation

if we stop at some index

iterate
cur becomes that index

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
