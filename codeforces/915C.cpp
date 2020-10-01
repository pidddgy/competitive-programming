// https://codeforces.com/problemset/problem/915/C

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

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;


    map<char, int> cnta, cntb;

    for(int i = 0; i < sz(a); i++) {
        cnta[a[i]]++;
    }
    
    for(int i = 0; i < sz(b); i++) {
        cntb[b[i]]++;
    }

    if((sz(b) > sz(a))) {
        for(char x: string("9876543210")) {
            for(int i = 0; i < cnta[x]; i++) {
                cout << x;
            }
        }
        cout << endl;

        return 0;
    }

    if(cnta == cntb) {
        cout << b << endl;
        return 0;
    }

    for(int i = sz(a)-1; i >= 0; i--) {
        string ans(sz(a), ' ');

        map<char, int> cpy = cnta;

        for(int j = 0; j < i; j++) {
            if(cpy[b[j]] > 0) {
                cpy[b[j]]--;
                ans[j] = b[j];
            }
        }

        for(char x: string("9876543210")) {
            if(cpy[x] > 0 and x < b[i]) {
                cpy[x]--;

                ans[i] = x;
                break;
            }
        }

        for(int j = i+1; j < sz(a); j++) {
            for(char x: string("98765432210")) {
                if(cpy[x] > 0) {
                    cpy[x]--;
                    ans[j] = x;
                    break;
                }
            }
        }

        if(ans.find(' ') == string::npos) {
            cout << ans << endl;
            break;
        }
    }
    
}

/*

for i in 1...N
    pick this i to be smaller than b[i]
    for j in 1...i-1
        pick digit exactly equal to i
    put biggest digit < digit in b[i]
    from there put all biggest digits possible

edge case: check if we can make a equal to b

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
