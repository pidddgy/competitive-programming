// https://cses.fi/problemset/task/1755

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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    map<char, int> cnt;

    for(char x: s) cnt[x]++;
    int r = 0;
    for(auto x: cnt) {
        r += x.se%2;
    }

    if(r > 1) {
        cout << "NO SOLUTION" << endl;
        exit(0);
    } 

    string ans;
    char odd = '?';


    for(auto x: cnt) {
        if(x.se%2) {
            odd = x.fi;
        } else {
            for(int i = 1; i <= x.se/2; i++) {
                cout << x.fi;
            }
        }
    }

    for(int i = 1; i <= cnt[odd]; i++) cout << odd;

    for(int i = 0; i < 26; i++) {
                char out = 'Z'-i;
                watch(out)
        if(cnt[out]%2==0) {
            for(int i = 1; i <= cnt[out]/2; i++) {
                cout << out;
            }
        }
    }

    cout << endl;

    
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
