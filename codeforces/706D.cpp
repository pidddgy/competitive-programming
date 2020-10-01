// https://codeforces.com/contest/706/problem/D

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

const int bits = 30;
const int root = 1;

int nextInd = 2;
int nxt[200050 * 32][2], cnt[200050 * 32];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 200050 * 32; i++) {
        nxt[i][0] = nxt[i][1] = -1;  
    }

    int q;
    cin >> q;
    
    for(int i = 0; i < 1; i++) {
        int x = 0;
        int cur = root;

        for(int j = bits; j >= 0; j--) {
            int val = (1 << j) & x;
            cerr << "inserting bit " << j << endl;
            int b = (val) ? 1 : 0;

            if(nxt[cur][b] == -1) {
                nxt[cur][b] = nextInd++;
            }

            cur = nxt[cur][b];
            cnt[cur]++;
        }
    }

    while(q--) {
        char t;
        int x;
        cin >> t >> x;

        if(t == '+') {
            int cur = root;

            for(int j = bits; j >= 0; j--) {
                int val = (1 << j) & x;
                cerr << "inserting bit " << j << endl;
                int b = (val) ? 1 : 0;

                if(nxt[cur][b] == -1) {
                    nxt[cur][b] = nextInd++;
                }

                cur = nxt[cur][b];
                cnt[cur]++;
            }
        } else if(t == '-') {
            int cur = root;
            for(int j = bits; j >= 0; j--) {
                int val = (1 << j) & x;
                int b = (val) ? 1 : 0;

                assert(nxt[cur][b] != -1);
                cur = nxt[cur][b];

                assert(cnt[cur] > 0);
                cnt[cur]--;
            }
        } else if(t == '?') {
            int cur = root;
            int num = 0;

            for(int j = bits; j >= 0; j--) {
                cerr << "on bit " << j << endl;
                int val = (1 << j) & x;
                int b = (val) ? 0 : 1;

                cerr << "we want " << b << endl;
                if(nxt[cur][b] == -1 or cnt[nxt[cur][b]] < 1) {
                    b ^= 1;
                }

                assert(nxt[cur][b] != -1);

                cur = nxt[cur][b];

                if(b) {
                    num |= (1 << j);
                }
            }

            cout << (x^num) << endl;
        }
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
