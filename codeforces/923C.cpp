// https://codeforces.com/contest/923/problem/C

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

const int maxn = 300500;
const int root = 1;
const int bits = 30;
int nxtInd = 2;

int cnt[maxn*32];
int nxt[maxn*32][2];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn*32; i++) {
        nxt[i][0] = nxt[i][1] = -1;
    }

    int N;
    cin >> N;

    int A[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    int P[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> P[i];
 
        int cur = root;
        for(int j = bits; j >= 0; j--) {
            int val = (1 << j) & P[i];
            int b = (val > 0) ? 1 : 0;

            if(nxt[cur][b] == -1) {
                nxt[cur][b] = nxtInd++;
            }
            
            cur = nxt[cur][b];
            cnt[cur]++;
        }
    }

    cerr << endl;

    for(int i = 1; i <= N; i++) {
        int cur = root;
        int e = 0;

        for(int j = bits; j >= 0; j--) {
            int val = (1 << j) & A[i];
            int b = (val > 0) ? 1 : 0;

            if(nxt[cur][b] == -1 or cnt[nxt[cur][b]] < 1) {
                b ^= 1;
            }

            assert(cnt[nxt[cur][b]] >= 1);

            cnt[nxt[cur][b]]--;
            cur = nxt[cur][b];
            if(b) {
                e |= (1 << j);
            }
        }

        cout << (A[i]^e) << " ";
    }
    cout << endl;
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