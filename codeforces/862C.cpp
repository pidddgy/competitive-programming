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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    int orig = n;

    if(n == 2 and x == 0) {
        cout << "NO" << endl;
        return 0;
    }

    vector<int> ans;

    if(n % 2 == 0) {
        ans.emplace_back(0);
        n--;
    }

    int xo = 0;
    int cur = 1;

    // n is now odd
    while(n > 1) {
        int emp = (1 << 17) ^ cur;

        xo ^= emp;
        ans.emplace_back(emp);
        cur++;
        n--;
    }

    if(((xo^x) == 0) and (orig % 2 == 0)) {
        for(int i: ans) {
            cerr << i << " ";
        }
        cerr << endl;
        watch(xo)
        watch(x)
        ans[1] -= (1 << 17);
        ans.emplace_back(1 << 17);
    } else {
        ans.emplace_back(xo^x);
    }

    cout << "YES" << endl;
    int ree = 0;
    for(int i: ans) {
        cout << i << " ";
        ree ^= i;
    }
    cout << endl;

    assert(ree == x);
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
