// https://dmoj.ca/problem/cco08p4

#include <bits/stdc++.h>
#define pii pair<int, int>
#define pcc pair<char, char>
#define fi first
#define se second
#define mp make_pair

using namespace std;

pii p[1005][1005];

pii findp(pii nm) {
    if(p[nm.fi][nm.se].fi == nm.fi && p[nm.fi][nm.se].se == nm.se)
        return nm;
    else return p[nm.fi][nm.se] = findp(p[nm.fi][nm.se]);
}


pii Mo(char a) {
    if(a == 'N') return {-1, 0};
    if(a == 'E') return {0, 1};
    if(a == 'S') return {1, 0};
    if(a == 'W') return {0, -1};
}

int main() {
    int N, M;
    cin >> N >> M;

    char A[N+1][M+1];
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++) {
            cin >> A[i][j];
            p[i][j] = {i, j};
        }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            char c = A[i][j];
            p[i][j] = findp({i+Mo(c).fi, j+Mo(c).se});
        }
    }

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            findp({i, j});

    map<pii, bool> S;
    int res = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(S[p[i][j]] == false) {
                S[p[i][j]] = true;
                res++;
            }
        }
    }

    cout << res << endl;
}
