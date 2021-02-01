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

int go(vector<vector<int>> &v) {
    int res = 0;

    // clear 1
    // try exchanging 2
    int take = min(v[0][1], v[1][0]); res += take;
    v[0][0] += take;
    v[1][1] += take;

    v[0][1] -= take; 
    v[1][0] -= take;

    // have to exchange 3 to get rid of 1
    take = min(v[0][2], v[1][0]); res += take;
    watch(take)
    v[0][0] += take;
    v[1][2] += take;

    v[0][2] -= take;
    v[1][0] -= take;

    // clear 3
    // exchange 3 for 0
    take = min(v[0][2], v[2][0]); res += take;
    v[0][0] += take;
    v[2][2] += take;

    v[0][2] -= take;
    v[2][0] -= take;

    take = min(v[0][1], v[2][0]); res += take;
    v[0][0] += take;
    v[2][1] += take;

    v[0][1] -= take;
    v[2][0] -= take;

    res += max(v[1][2], v[2][1]);
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
                    int loc = 0;
                    
                    vector<vector<int>> cnt(3, vector<int>(3, 0));

                    // find out of position
                    int lb = 1, rb = l;
                    for(int x: vector<int>({i, j, k})) {
                        cerr << "doing " << i << " " << x << endl;
                        cnt[i][x] = query(x, lb, rb);
                    }

                    lb = rb+1;
                    rb = lb+psa[j][n]-1;
                    for(int x: vector<int>({i, j, k})) {
                        cnt[j][x] = query(x, lb, rb);
                    }

                    lb = rb+1;
                    rb = lb+psa[k][n]-1;
                    for(int x: vector<int>({i, j, k})) {
                        cnt[k][x] = query(x, lb, rb);
                    }

                    lb = rb+1;
                    rb = lb+psa[i][n]-l-1;
                    for(int x: vector<int>({i, j, k})) {
                        cnt[i][x] += query(x, lb, rb);
                    }
                    
                    // cerr << "init is: " << endl;
                    ans = min(ans, go(cnt));
                }
            }
        }
    }

    cout << ans << endl;
}

/*
key claim is that if there is one element out of position then there is a complement also out of position so we can fix hem in one swap

BABCBCACCA

3 a, 3 b, 4 c

ideal state is

3 0 0
0 3 0
0 0 4

given a 2d matrix make it into "identity"

one operation:
    for any two rows pick one element from both and give it to the other

2 1 0
0 2 1
1 0 3

rather than matrix think of it as a list?

2 1 0
1 2 0
0 0 4

ex of cyclic:
1 needs 2
2 needs 3
3 needs 1

1 1 1
1 2 0
1 0 4
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?