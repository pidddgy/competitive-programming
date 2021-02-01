// https://dmoj.ca/problem/ccc05s3

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

vector<vector<int>> mult(vector<vector<int>> a, vector<vector<int>> b) {
    int m = sz(a), n = sz(a[0]);
    int p = sz(b), q = sz(b[0]);

    vector<vector<int>> res(m*p, vector<int>(n*q, 0));

    cerr << "new matrix has " << m*p << " rows and " << n*q << " cols" << endl;

    int x = 0;
    for(int i = 0; i < m*p; i += p) {
        int y = 0;
        for(int j = 0; j < n*q; j += q) {
            for(int l = 0; l < p; l++) {
                for(int k = 0; k < q; k++) {
                    res[i+l][j+k] = b[l][k] * a[x][y];
                }
            }
            y++;
        }
        x++;
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int r, c;
    cin >> r >> c;

    vector<vector<int>> cur(r, vector<int>(c, 0));

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> cur[i][j];
        }
    }

    for(int ree = 1; ree < N; ree++) {
        cin >> r >> c;

        vector<vector<int>> v(r, vector<int>(c, 0));

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cin >> v[i][j];
                cerr << v[i][j] << " ";
            }
            cerr << endl;
        }

        cur = mult(cur, v);
    }

    // for(int i = 0; i < sz(cur); i++) {
    //     for(int j = 0; j < sz(cur[i]); j++) {
    //         cerr << cur[i][j] << " ";
    //     }
    //     cerr << endl;
    // }
    
    int mi = LLONG_MAX, mirowsum = LLONG_MAX, micolsum = LLONG_MAX;
    int ma = LLONG_MIN, marowsum = LLONG_MIN, macolsum = LLONG_MIN;

    int n = sz(cur);
    int m = sz(cur[0]);

    for(int i = 0; i < n; i++) {
        int rowsum = 0;
        for(int j = 0; j < m; j++) {
            mi = min(mi, cur[i][j]);
            ma = max(ma, cur[i][j]);
            rowsum += cur[i][j];
        }

        mirowsum = min(mirowsum, rowsum);
        marowsum = max(marowsum, rowsum);
    }

    for(int i = 0; i < m; i++) {
        int colsum = 0;
        for(int j = 0; j < n; j++) {
            colsum += cur[j][i];
        }

        micolsum = min(micolsum, colsum);
        macolsum = max(macolsum, colsum);
    }

    for(int x: vector<int>({ma, mi, marowsum, mirowsum, macolsum, micolsum})) {
        cout << x << endl;
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
