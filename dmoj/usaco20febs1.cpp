// http://www.usaco.org/index.php?page=viewproblem2&cpid=1014

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
// #define cerr if(false) cerr
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 100050;
const int maxm = 105;

int ans[maxn];
// shift after each
int p[maxn];

// cycle ith belongs to
int cc[maxn];
vector<int> ops;
int pos[maxn];

vector<int> A[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);


    int N, M, K;
    cin >> N >> M >> K;

    vector<pii> ops;
    for(int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;

        l--; r--;

        ops.emplace_back(l, r);
    }

    for(int i = 0; i < N; i++) {
        p[i] = i;

        for(pii x: ops) {
            if(x.fi <= p[i] and p[i] <= x.se) {
                p[i] = (x.fi+x.se)-p[i];
            }
        }
    }

    int curc = 1;

    for(int i = 0; i < N; i++) {
        if(cc[i] == 0) {
            cc[i] = curc;

            A[cc[i]].emplace_back(i);

            int curPos = p[i];
            if(curPos != i) pos[curPos] = 1;

            while(curPos != i) {
                A[cc[i]].emplace_back(curPos);
                cc[curPos] = cc[i];

                if(p[curPos] != i) pos[p[curPos]] = pos[curPos]+1;

                curPos = p[curPos];
            }

            curc++;
        }
    }

    for(int i = 0; i < N; i++) {
        int ind = A[cc[i]][(pos[i]+K)%(A[cc[i]].size())];

        ans[ind] = i+1;
        
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }

}