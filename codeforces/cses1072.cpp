// https://codeforces.com/problemset/problem/1430/E

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
bool in(int r, int c) {
    if(1 <= r and r <= n) {
        if(1 <= c and c <= n) {
            return true;
        }
    }

    return false;
}

void go() {
    int sum = 0;
    map<int, int> cnt;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int x = 0;

            // up
            if(in(i-2, j-1)) x++;
            if(in(i-2, j+1)) x++;

            // right
            if(in(i-1, j+2)) x++;
            if(in(i+1, j+2)) x++;

            // down
            if(in(i+2, j-1)) x++;
            if(in(i+2, j+1)) x++;

            // left
            if(in(i-1, j-2)) x++;
            if(in(i+1, j-2)) x++;

            // cout << x << " ";
            sum +=  (n*n-1)-x ;
            cnt[x]++;
        }
        // cout << endl;
    }

    for(int i = 0; i <= 8; i++) {
        cerr << cnt[i] << " ";
    }
    cerr << endl;

    cout << sum/2 << endl;
    cerr << endl;
}

int sq(int num) {
     return num*num;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    int upto = 4;
    for(int i = 1; i <= min(t, upto); i++) {
        n = i;
        go();
    }

    cerr << "~~~" << endl;
    for(int i = upto+1; i <= t; i++) {
        n = i;
        int ans = (n*n-1)*(n*n);

        map<int, int> cnt;
        cnt[2] = 4;
        cnt[3] = 8;
        cnt[4] = (i-3)*4;
        cnt[6] = (i-4)*4;
        cnt[8] = sq(i-4);

        for(int j = 0; j <= 8; j++) {
            cerr << cnt[j] << " ";
            ans -= cnt[j]*j;
        }
        cerr << endl;

        cout << ans/2 << endl;
        cerr << endl;
    }
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
