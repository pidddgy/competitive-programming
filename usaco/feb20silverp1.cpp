// http://www.usaco.org/index.php?page=viewproblem2&cpid=1014

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define pii pair<int, int>
#define fi first
#define se second

const int SEED = 413158523;
const int MOD = 1000000007;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    freopen("swap.in","r",stdin); 
    freopen("swap.out","w",stdout);

    int N, M, K;
    cin >> N >> M >> K;

    int a[N+1];
    for(int i = 1; i <= N; i++) a[i] = i;

    vector<pii> ops;
    for(int i = 1; i <= M; i++) {
        int l, r;
        cin >> l >> r;

        ops.emplace_back(l, r);
    }

    set<int> S;
    int rem = K;
    for(int i = 1; i <= K; i++) {
        for(pii x: ops) {
            // cerr << x.fi << "," << x.se << endl;
            reverse(a+x.fi, a+x.se+1);
        }

        for(int j = 1; j <= N; j++) {
            cerr << a[j] << " ";
        }
        cerr << endl;
        int hash = 1;

        for(int j = 1; j <= N; j++) {
            hash *= SEED;
            hash += a[j];
        }

        watch(hash)

        if(S.count(hash)) {
            rem %= i-1;
        }

        S.emplace(hash);
        rem--;

        if(rem == 0) {
            cerr << "found on " << i << endl;
            for(int j = 1; j <= N; j++) {
                cout << a[j] << endl;
            }

            return 0;
        }
    }

}