// https://dmoj.ca/problem/dmopc18c6p3

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second


using namespace std;

const int maxNM = 200005;

int p[maxNM];

int findp(int n) {
    if(n == p[n]) return n;
    else return p[n] = findp(p[n]);
}

void join(int a, int b) {
    int n = findp(a);
    int m = findp(b);

    assert(n != m);

    p[n] = m;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> A[N+1];
    pii E[M+1];
    for(int i = 1; i <= N; i++) p[i] = i;

    for(int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;

        A[a].emplace_back(b);
        A[b].emplace_back(a);

        E[i].fi = a;
        E[i].se = b;

    }

    bool use = false;
    for(int i = 1; i <= M; i++) {
        if(findp(E[i].fi) != findp(E[i].se)) {
            join(E[i].fi, E[i].se);
        } else {
            if(!use) use = true;
            else if (use) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
}
