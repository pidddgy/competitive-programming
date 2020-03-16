#include <bits/stdc++.h>

typedef unsigned long long ull;
#define pii pair<ull, ull>
#define fi first
#define se second
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;


int main() {
    ull N, M;
    cin >> N >> M;

    ull A[N+1];
    for(ull i = 1; i <= N; i++) cin >> A[i];

    vector<pii> ops;
    ops.emplace_back(numeric_limits<ull>::max(), 0);
    for(ull i = 1; i <= M; i++) {
        ull a, b;
        cin >> a >> b;
        ops.emplace_back(b, a);
    }

    sort(ops.rbegin(), ops.rend());
    sort(A+1, A+N+1);

    ull pos = 1;
    ull curOp = 1;

    while(curOp <= M && pos <= N) {
        ull k = 1;
        while(k <= ops[curOp].se && pos <= N) {
            if(A[pos] < ops[curOp].fi) {
                k++;
                A[pos] = ops[curOp].fi;
            }
            pos++;
        }
        curOp++;
    }

    ull ans = 0;
    for(ull i = 1; i <= N; i++) {
        ans += A[i];
    }

    cout << ans << endl;
}

/* 
3 2
4 4 3
2 4
1 5 
*/