// https://codeforces.com/problemset/problem/847/E

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
int n;
string s;

vector<int> mans, ast;

// is it ok to use n time?
bool ok(int x) {
    cerr << "trying " << x << endl;
    int ind = 0;
    for(int p: mans) {
        cerr << "on " << p << endl;
        int l = p;
        int r = p;

        while(ind < ast.size()) {
            l = min(l, ast[ind]);
            r = max(r, ast[ind]);

            int need = r-l + min(p-l, r-p);

            if(need > x) {
                break;
            }

            ind++;
        }
    }

    watch(ind)

    return ind == ast.size();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> s;

    s = "."+s;

    for(int i = 1; i <= n; i++) {
        if(s[i] == 'P') {
            mans.emplace_back(i);
        } else if (s[i] == '*') {
            ast.emplace_back(i);
        }
    }

    watch(ast.size())

    int l = 1;
    int r = n*3;
    int lgood = -1;

    while(l <= r) {
        int mid = (l+r)/2;

        if(ok(mid)) {
            lgood = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout << lgood << endl;
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
