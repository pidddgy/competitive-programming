// https://dmoj.ca/problem/ccc20s4

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

const int maxn = (int)1e6+5;

int a[maxn];
int psa[3][maxn];

int query(int x, int l, int r) {
    if(l > r) return 0;
    
    int res = psa[x][r];
    if(l-1 >= 0) res -= psa[x][l-1];

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = sz(s);
    s = "."+s;

    for(int i = 1; i <= n; i++) {
        a[i] = s[i]-'A';
    }

    for(int i = 1; i <= n; i++) {
        psa[a[i]][i]++;

        for(int j = 0; j <= 2; j++) {
            psa[j][i] += psa[j][i-1];
        }
    }

    int ans = LLONG_MAX;
    for(int i = 0; i <= 2; i++) {
        for(int j = 0; j <= 2; j++) {
            for(int k = 0; k <= 2; k++) {
                if(sz(set<int>({i, j, k})) != 3) continue;
                for(int l = 0; l <= psa[i][n]; l++) {
                    cerr << "trying " << i << " " << j << " " << k << " with " << l << endl;
                    int loc = 0;
                    // find out of position
                    int lb = 1, rb = l;
                    loc += query(j, lb, rb) + query(k, lb, rb);

                    cerr << lb << " " << rb << endl;
                    cerr << "first seg is " << loc << endl;

                    lb = rb+1;
                    rb = lb+psa[j][n]-1;
                    loc += query(i, lb, rb) + query(k, lb, rb);

                    lb = rb+1;
                    rb = lb+psa[k][n]-1;
                    loc += query(i, lb, rb) + query(j, lb, rb);

                    lb = rb+1;
                    rb = lb+psa[i][n]-l-1;
                    loc += query(j, lb, rb) + query(k, lb, rb);

                    watch(loc)
                    ans = min(ans, (loc+1)/2);
                    cerr << endl;
                }
            }
        }
    }

    cout << ans << endl;
}

/*
key claim is that if there is one element out of position then there is a complement also out of position so we can fix hem in one swap
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?