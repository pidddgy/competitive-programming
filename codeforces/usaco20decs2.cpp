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

const int maxn = 2700;
int n;
int x[maxn], y[maxn];
map<int, int> ac;

int psa[6000][6000];

int query(int i, int j, int ii, int jj) {
    // watch(i)
    // cerr << "adding " << ii << " " << jj << endl;
    // watch(psa[ii][jj])
    // cerr << "subtract " << ii << " " << j-1 << endl;
    // watch(psa[ii][j-1])
    // cerr << "subtract " << i-1 << " " << jj << endl;
    // watch(psa[i-1][jj])
    // cerr << "add " << i-1 << " " << j-1 << endl;
    return psa[ii][jj] - psa[ii][j-1] - psa[i-1][jj] + psa[i-1][j-1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<int> cmp;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        cmp.emplace_back(x[i]);
        cmp.emplace_back(y[i]);
    }

    sort(all(cmp));
    cmp.erase(unique(all(cmp)), cmp.end());

    for(int i = 0; i < sz(cmp); i++) {
        ac[cmp[i]] = i+1;
    }

    for(int i = 1; i <= n; i++) {
        x[i] = ac[x[i]];
        y[i] = ac[y[i]];

        cerr << x[i] << " " << y[i] << endl;
    }

    for(int i = 1; i <= n; i++) {
        psa[x[i]][y[i]]++;
    }

    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            cerr << psa[i][j] << " ";
        }
        cerr << endl;
    }
    cerr << endl;
    for(int i = 1; i < 6000; i++) {
        for(int j = 1; j < 6000; j++) {
            psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
    }

    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            cerr << psa[i][j] << " ";
        }
        cerr << endl;
    }
    int ans = 1;
    // left, right
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            // cerr << i << " " << j << endl;
            int c = 0;
            int up = query(1, min(y[i], y[j]), min(x[i], x[j]), max(y[i], y[j]));
            // cerr << 1 << " " << min(y[i], y[j]) << " " << min(x[i], x[j]) << " " << max(y[i], y[j]) << endl;
            int down = query(max(x[i], x[j]), min(y[i], y[j]), 5000, max(y[i], y[j]));
            watch(up)
            watch(down)
            ans += up*down;
            cerr << endl;
        }
    }

    cout << ans << endl;
}

/*

all x, y are distinct

for each row we either go left or right




*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?

