// https://codeforces.com/problemset/problem/513/G1

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

const int maxn = 10;
int orig[maxn], arr[maxn];

int n, k;
void reset() {
    for(int i = 1; i <= n; i++) {
        arr[i] = orig[i];
    }
}

vector<pii> pairs;
vector<vector<int>> indcombos;

void f(vector<int> cur = {}) {
    if(sz(cur) == k) {
        indcombos.push_back(cur);
        return;
    }

    for(int i = 0; i < sz(pairs); i++) {
        cur.push_back(i);
        f(cur);
        cur.pop_back();
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    assert(n <= 6);
    assert(k <= 4);

    for(int i = 1; i <= n; i++) {
        cin >> orig[i];
    }


    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            pairs.emplace_back(i, j);
        }
    }

    ld sum = 0, cases = 0;

    f();

    for(vector<int> x: indcombos) {
        reset();

        for(int y: x) {
            pii z = pairs[y];
            int len = z.se-z.fi+1;
            // swap(arr[z.fi], arr[z.se]);
            reverse(arr+z.fi, arr+z.fi+len);
        }

        int inv = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i+1; j <= n; j++) {
                if(arr[i] > arr[j]) {
                    inv++;
                }
            }
            cerr << arr[i] << " ";
        }
        cerr << endl;

        sum += inv;
        cases++;
    }

    ld ans = sum/cases;

    cout << fixed << setprecision(13) << ans << endl;
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
