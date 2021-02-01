// https://codeforces.com/contest/1427/problem/D

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

const int maxn = 60;

int n;
int a[maxn];

vector<vector<int>> ans;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    bool rev = false;
    for(int i = 1; i <= n; i++) {
        cerr << "on " << i << endl;
        int ind = -1;
        for(int j = 1; j <= n; j++) {
            if(a[j] == i) ind = j;
        }

        watch(i)
        watch(ind)

        vector<int> op;

        if(!rev) {
            for(int j = 1; j <= i-1; j++) {
                op.push_back(1);
            }

            op.push_back(ind-i+1);

            for(int j = ind+1; j <= n; j++) {
                op.push_back(1);
            }
        } else {
            // right side is correct
            for(int j = 1; j <= ind-1; j++) {
                op.push_back(1);
            }

            op.push_back((n+1-i)-ind+1);

            for(int j = n-i+2; j <= n; j++) {
                op.push_back(1);
            }
        }

        // don't flip
        if(!rev and i == n) {
            break;
        }

        cerr << "doing" << endl;
        for(int x: op) {
            cerr << x << " ";
        }
        cerr << endl;

        // we want to flip the whole thing
        if(sz(op) == 1) {
            op.clear();
            for(int i = 1; i <= n; i++) {
                op.push_back(1);
            }
        } else {
            // flipping whole thing doesn't reverse
            rev ^= 1;
        }

        ans.emplace_back(op);

        int j =1;
        for(int k = 0; k < sz(op); k++) {
            reverse(a+j, a+j+op[k]);
            j += op[k];
        }
        reverse(a+1, a+n+1);

        for(int i = 1; i <= n; i++) {
            cerr << a[i] << " ";
        }
        cerr << endl;
        cerr << endl;
    }

    assert(sz(ans) <= n);

    for(int i = 1; i <= n; i++) {
        cerr << a[i] << " ";
    }
    cerr << endl;

    cout << sz(ans) << endl;
    for(auto x: ans) {
        cout << sz(x) << " ";
        for(int y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
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
