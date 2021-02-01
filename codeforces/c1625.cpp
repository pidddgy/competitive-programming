// https://cses.fi/problemset/task/1625
 
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
 
const int len = 15;
// string s;
 
int ans = 0;
bool vis[len][len];
 
 
 
bool ok(int r, int c) {
    if(1 <= r and r <= 7) {
        if(1 <= c and c <= 7) {
            if(!vis[r][c]) {
                return true;
            }
        }
    }
    return false;
}
 
string st;
 
// left, up, right, down
string dchrs = "LURD";
vector<pii> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
 
vector<string> paths;
int s = 0;
int calls = 0;
void f(int row, int col) {
    calls++;
    if(s > 48) return;
    if(row == 7 and col == 1) {
        if(s == 48) {
            ans++;
        }
        return;
    }
 
    bool l = ok(row, col-1);
    bool u = ok(row-1, col);
    bool r = ok(row, col+1);
    bool d = ok(row+1, col);

    if((!u and !d and l and r) or (u and d and !l and !r)) return;

    vis[row][col] = true;

    watch(s)

    int ind = s;
    char p = st[ind];
    if(l) {
        if(p == 'L' or p == '?') {
            s++;
            f(row, col-1);
            s--;
        }
    }
    if(u) {
        if(p == 'U' or p == '?') {
            // s += 'U';
            s++;
            f(row-1, col);
            // s.pop_back();
            s--;
        }
    }

    if(r) {
        if(p == 'R' or p == '?') {
            // s += 'R';
            s++;
            f(row, col+1);
            // s.pop_back();
            s--;
        }
    }

    if(d) {
        if(p == 'D' or p == '?') {
            // s += 'D';
            s++;
            f(row+1, col);
            // s.pop_back();
            s--;
        }
    }

    vis[row][col] = false;
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> st;
 
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
    // cout << calls << endl;
    
    // cout << sz(paths) << endl;
    // cout << calls << endl;
 
 
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