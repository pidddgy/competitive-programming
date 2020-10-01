// https://codeforces.com/contest/551/problem/B

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

int cnta[26], cntb[26], cntc[26], cpy[26];

void resetcpy() {
    for(int i = 0; i < 26; i++) cpy[i] = cnta[i];
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b, c;
    cin >> a >> b >> c;

    for(char x: a) {
        cnta[x-'a']++;
    }

    for(char x: b) {
        cntb[x-'a']++;
    }

    for(char x: c) {
        cntc[x-'a']++;
    }

    int best = 0, amtb = 0, amtc = 0;
    for(int i = 0; i <= 1e5; i++) {
        resetcpy();
        cerr << "trying " << i << endl;

        bool ok = true;
        int loc = i;
        int mi = 1e15;
        // build i of b
        for(int j = 0; j < 26; j++) {
            cpy[j] -= cntb[j]*i;  
            if(cpy[j] < 0) {
                ok = false;
            }
            
            if(cntc[j])
            mi = min(mi, cpy[j]/cntc[j]);
        }

        watch(mi)

        if(loc+mi > best and ok) {
            best = loc+mi;
            amtb = i;
            amtc = mi;
        }
    }

    resetcpy();
    
    watch(amtb)
    watch(amtc)
    while(amtb--) {
        cout << b;
        for(int j = 0; j < 26; j++) {
            cpy[j] -= cntb[j];
        }
    }

    while(amtc--) {
        cout << c;
        for(int j = 0; j < 26; j++) {
            cpy[j] -= cntc[j]; 
        }
    }

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < cpy[i]; j++) {
            char out = 'a'+i;

            cout << out;
            
        }
    }

    cout << endl;

}

/*

reduction: we're really just trying to find number of a and b, we can just dump the ramiaining letters


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
