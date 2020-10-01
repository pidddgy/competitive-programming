// https://codeforces.com/contest/336/problem/C

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

int n;
int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    multiset<int> ans;

    for(int b = 0; b <= 30; b++) {
        multiset<int> S;

        int val = -1;
        for(int i = 1; i <= n; i++) {
            if(a[i] & (1LL << b)) {
                if(val == -1) val = a[i];
                else val &= a[i];

                S.emplace(a[i]);
            }
        }

        for(int i = 0; i < b; i++) {
            vector<int> rem;
            if(val & (1LL << i)) {
                for(int x: S) {
                    if(x & (1LL << i)) {
                        rem.emplace_back(x);
                    }
                }
            }

            for(int x: rem) {
                assert(S.count(x));
                S.erase(S.lower_bound(x));
            }
        }

        watch(b)
        for(int x: S) {
            cerr << x << " ";
        }
        cerr << endl;

        if(sz(S)) {
            ans = S;
        }
    }

    cout << sz(ans) << endl;
    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;
}

/*

observation: beauty is just the least significant set bit

fix the bit that will be the least significant
    add all the numbers

    repeat 60 times:
        if there is any bit set that is less significant then remove all elements with this bit set (do not remove elements hwile iterating)

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
