// https://codeforces.com/contest/1200/problem/D

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

const int maxn = 3500;

int n, k;
char c[maxn][maxn];
// int d[maxn][maxn];
int psa[maxn][maxn];


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for(int j = 1; j <= n; j++) {
            c[i][j] = s[j-1];
        }
    }

    // process each row
    int add = 0;
    for(int i = 1; i <= n; i++) {
        int l = -1, r = -1;
        for(int j = 1; j <= n; j++) {
            if(c[i][j] == 'B') {
                if(l == -1) l = j;
                r = j;
            }            
        }

        // cannot contribute
        if(r-l+1 > k) {
            continue;
        }

        int r1 = max(1LL, i-k+1);
        int r2 = i;

        int c1, c2;

        if(l == -1) {
            // c1 = 1;
            // c2 = n;
            add++;
            continue;
        } else {
            c1 = max(1LL, r-k+1);
            c2 = l;
        }

        cerr << "row " << i << " -> " << r1 << "," << c1 << " " <<  " " << r2 << "," << c2 << endl;
        psa[r1][c1]++;
        psa[r1][c2+1]--;
        psa[r2+1][c1]--;
        psa[r2+1][c2+1]++;
    }

    // process each column
    for(int i = 1; i <= n; i++) {
        int l = -1, r = -1;
        for(int j = 1; j <= n; j++) {
            if(c[j][i] == 'B') {
                if(l == -1) l = j;
                r = j;
            }            
        }

        // cannot contribute
        if(r-l+1 > k) {
            continue;
        }

        int c1 = max(1LL, i-k+1);
        int c2 = i;

        int r1, r2;
        if(l == -1) {
            // r1 = 1;
            // r2 = n;
            add++;
            continue;
        } else {
            r1 = max(1LL, r-k+1);
            r2 = l;
        }


        cerr << "col " << i << " -> " << r1 << "," << c1 << " " <<  " " << r2 << "," << c2 << endl;
        psa[r1][c1]++;
        psa[r1][c2+1]--;
        psa[r2+1][c1]--;
        psa[r2+1][c2+1]++;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            psa[i][j] += psa[i-1][j];
            psa[i][j] += psa[i][j-1];
            psa[i][j] -= psa[i-1][j-1];

            cerr << psa[i][j] << " ";
            ans = max(ans, psa[i][j]);
        }
        cerr << endl;
    }

    cout << ans+add << endl;
}

/*

2d difference array

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
