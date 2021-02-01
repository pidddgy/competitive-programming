// https://cses.fi/problemset/task/1625
 
#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
// #define cerr cout
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
 
void solve() {
    
}
 
const int len = 15;
// string s;
 
int ans = 0;
bool vis[len][len];
 
 
 
inline bool ok(int r, int c) {
    if(1 <= r and r <= 7) {
        if(1 <= c and c <= 7) {
            if(!vis[r][c]) {
                return true;
            }
        }
    }
    return false;
}
 
int mod(int num, int m) {
    return (num+m)%m;
}
    string st;
 
// left, up, right, down
string dchrs = "LURD";
vector<pii> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
 
vector<string> paths;
string s;
int calls = 0;
void f(int r, int c) {
    calls++;
    if(sz(s) > 48) return;
    if(r == 7 and c == 1) {
        if(sz(s) == 48) {
            ans++;
        }
        return;
    }
 
    // cerr << s << endl;
    // cerr << r << "," << c << endl;
 
    for(int i = 0; i < 4; i++) {
        int nr = r, nc = c;
        nr += dir[i].fi;
        nc += dir[i].se;
 
        // cerr << nr << " " << nc << endl;
 
        if(ok(nr, nc)) {
            // cerr << "e" << endl;
            bool fl = ok(nr+dir[i].fi, nc+dir[i].se);
            bool g = true;
 
            for(int j = -1; j <= 1; j += 2) {
                int sr = nr, sc = nc;
                sr += dir[mod(i+j, 4)].fi;
                sc += dir[mod(i+j, 4)].se;
 
                if(!ok(sr, sc)) {
                    g = false;
                }
            }
            // cerr << fl << " " << g << endl;
 
            int ind = sz(s);
            if(dchrs[i] == st[ind] or st[ind] == '?')
            if(!(!fl and g)) {
                // cerr << "ok" << endl;
                cerr << "can move from " << r << "," << c << " to " << nr << " " << nc << endl;
                s += dchrs[i];
                vis[nr][nc] = true;
                f(nr, nc);
                vis[nr][nc] = false;
                s.pop_back();
            } else {
                cerr << "cannot move from " << r << "," << c << " to " << nr << " " << nc << endl;
            }
        }
    }
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> st;
 
    vis[1][1] = true;
    f(1, 1);
 
    // int ans = 0;
    // for(string x: paths) {
    //     // cout << x << endl;
    //     bool valid = true;
    //     for(int i = 0; i < 48; i++) {
    //         if(x[i] != st[i] and st[i] != '?') valid = false;
    //     }
    //     ans += valid;
    // }
    // watch(sz(paths))
    cout << ans << endl;
    
    // cout << sz(paths) << endl;
    cout << calls << endl;
 
 
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