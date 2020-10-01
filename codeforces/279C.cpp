// https://codeforces.com/problemset/problem/279/C

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

// indices that are + or - the previous
vector<int> pos, neg;

int n, m;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];

        if(i >= 2) {
            if(a[i] > a[i-1]) {
                pos.emplace_back(i);
            } else if(a[i] < a[i-1]) {
                neg.emplace_back(i);
            }
        }
    }

    sort(all(pos));
    sort(all(neg));

    while(m--) {
        int l, r;
        cin >> l >> r;

        if(l == r) {
            cout << "Yes" << endl;
            continue;
        }

        int l2 = 0, r2 = sz(pos)-1;
        int lgpos = -1;
        while(l2 <= r2) {
            int mid = (l2+r2)/2;

            if(pos[mid] <= r) {
                l2 = mid+1;
                lgpos = pos[mid];
            } else {
                r2 = mid-1;
            }
        }

        if(lgpos < l and lgpos != -1) lgpos = -1;

        l2 = 0, r2 = sz(neg)-1;
        int lgneg = -1;
        while(l2 <= r2) {
            
            int mid = (l2+r2)/2;

            if(neg[mid] > l) {
                r2 = mid-1;
                lgneg = neg[mid];
            } else {
                l2 = mid+1;
            }
        }

        if(lgneg > r and lgpos != -1) lgneg = -1;

        cerr << lgpos << " " << lgneg << endl;
        if(lgpos == -1 or lgneg == -1) {
            cout << "Yes" << endl;
        } else if(lgpos < lgneg) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}

/*

binary search for rightmost + and leftmost -
check if pos <= pos2

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
