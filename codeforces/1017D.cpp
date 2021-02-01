// https://codeforces.com/contest/1017/problem/D

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 13;

int n, m, q;
int w[maxn];
int cnt[(int)1e4];
int psa[9000][1400];

int getmask(string &s) {
    int res = 0;

    for(int i = 0; i < sz(s); i++) {
        if(s[i] == '1') res += (1 << i);
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;

    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }

    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;

        int msk = (getmask(s));

        cnt[msk]++;
    }

    for(int i = 0; i < (1<<13); i++) {
        for(int j = 0; j < (1<<13); j++) {
            if(!cnt[j]) continue;
            int x = i^j;

            int wu = 0;
            for(int k = 0; k < n; k++) {
                if(!(x & (1 << k))) wu += w[k];
            }

            psa[i][wu] += cnt[j];
        }
    } 

    for(int i = 0; i < (1<<13); i++) {
        for(int j = 1; j < 1400; j++) {
            psa[i][j] += psa[i][j-1];
        }
    }

    while(q--) {
        string s;
        cin >> s;

        int k;
        cin >> k;

        cout << psa[getmask(s)][k] << endl;
    }


}

/*
64 000 000 

640 000 000
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
