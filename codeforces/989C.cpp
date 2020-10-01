// https://codeforces.com/contest/989/problem/C

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
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

char ans[60][60];
void put(int l, int r, int amt, char chr) {
    cerr << "putting " << chr << endl;
    for(int i = l; i <= r; i += 2) {
        for(int j = 1; j <= 50; j += 2) {
            if(amt == 0) return;
            
            ans[i][j] = chr;
            amt--;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    for(int j = 1; j <= 50; j++) {
        for(int i = 1; i <= 10; i++) {
            ans[i][j] = 'A';
        }

        for(int i = 11; i <= 20; i++) {
            ans[i][j] = 'B';
        }

        for(int i = 21; i <= 30; i++) {
            ans[i][j] = 'C';
        }

        for(int i = 31; i <= 40; i++) {
            ans[i][j] = 'D';
        }
    }

    put(1, 10, c-1, 'C');
    put(11, 20, d-1, 'D');
    put(21, 30, a-1, 'A');
    put(31, 40, b-1, 'B');

    cout << 40 << " " << 50 << endl;
    for(int i = 1; i <= 40; i++) {
        for(int j = 1; j <= 50; j++) {
            cout << (char)ans[i][j];
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
