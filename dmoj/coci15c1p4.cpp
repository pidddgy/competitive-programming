// https://dmoj.ca/problem/coci15c1p4

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

int N, K, P;
map<int, int> rxor, cxor, rcnt, ccnt;
map<int, map<int, int>> rook;
int ans = 0;

void upd(int r, int c, int val) {
    ans -= N - ccnt[rxor[r]];
    ans -= N - rcnt[cxor[c]];

    // if overcounted
    if(rxor[r] != cxor[c]) ans++;

    rcnt[rxor[r]]--;
    rxor[r] ^= val;
    rcnt[rxor[r]]++;

    ccnt[cxor[c]]--;
    cxor[c] ^= val;
    ccnt[cxor[c]]++;

    ans += N - ccnt[rxor[r]];
    ans += N - rcnt[cxor[c]];
    if(rxor[r] != cxor[c]) ans--;

    rook[r][c] = val;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K >> P;

    rcnt[0] = N;
    ccnt[0] = N;
    for(int i = 1; i <= K; i++) {
        int r, c, x;
        cin >> r >> c >> x;

        upd(r, c, x);
    }

    for(int i = 1; i <= P; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int v = rook[r1][c1];

        upd(r1, c1, v);
        upd(r2, c2, v);

        cout << ans << endl;
    }
}
