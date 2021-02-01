// https://codeforces.com/contest/724/problem/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
// #define cerr cout
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

int n, m;
string s;

int seg[4*maxn];

void upd(int pos, int val) {
    pos += n;
    seg[pos] = val;

    for(int i = pos/2; i >= 1; i /= 2) {
        seg[i] = seg[i*2] + seg[i*2+1];
    }
}

int query(int l, int r) {
    l += n;
    r += n;

    int res = 0;
    while(l <= r) {
        if(l%2 == 1) res += seg[l++];
        if(r%2 == 0) res += seg[r--];

        l /= 2;
        r /= 2;
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m;
    cin >> s;


    n = sz(s);

    s = "."+s;

    for(int i = 1; i <= n; i++) upd(i, 1);

    string ans;
    for(int i = 25; i >= 0; i--) {
        for(int j = 1; j <= n; j++) {
            if(s[j]-'a' != i) continue;

            int left = 0;
            int l = 1, r = j-1;

            while(l <= r) {
                int mid = (l+r)/2;

                if(query(mid, j-1)) {
                    l = mid+1;
                    left = mid;
                } else {
                    r = mid-1;
                }
            }

            int right = n+1;
            l = j+1, r = n;

            while(l <= r) {
                int mid = (l+r)/2;

                if(query(j+1, mid)) {
                    r = mid-1;
                    right = mid;
                } else {
                    l = mid+1;
                }
            }

            if(right-left-1 < m) {
                upd(j, 0);
            }
        }
    }

    string out;
    char ma = 0;
    for(int i = 1; i <= n; i++) {
        if(query(i, i)) {
            out += s[i];
            ma = max(ma, s[i]);
        }
    }

    for(int i = 1; i <= n; i++) {
        if(!query(i, i) and s[i] < ma) {
            out += s[i];
        }
    }

    sort(all(out));

    cout << out << endl;
}

/*

lol segtree idk
start with all characters, then try to remove as many z then y and so on
remove suffix of alphabet, then greedily remove whatever is possible

rem = keep up to (rem)

1 081 600 000
6 656 000 000
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
