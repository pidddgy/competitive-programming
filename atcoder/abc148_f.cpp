// https://atcoder.jp/contests/abc148/tasks/abc148_f

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 100500;
vector<int> G[maxn];

int tdis[maxn], adis[maxn];

void bfs(int st, int arr[]) {
    queue<int> Q;
    Q.push(st);
    arr[st] = 0;

    while(!Q.empty()) {
        int S = Q.front(); Q.pop();

        for(int adj: G[S]) {
            if(arr[adj] > arr[S]+1) {
                arr[adj] = arr[S]+1;
                Q.push(adj);
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, u, v;
    cin >> N >> u >> v;

    for(int i = 1; i <= N-1; i++) {
        int a, b;
        cin >> a >> b;

        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    for(int i = 1; i <= N; i++) {
        tdis[i] = adis[i] = INT_MAX-100;
    }

    bfs(u, tdis);
    bfs(v, adis);

    for(int i = 1; i <= N; i++) {
        cerr << tdis[i] << " ";
    }
    cerr << endl;

    for(int i = 1; i <= N; i++) {
        cerr << adis[i] << " ";
    }
    cerr << endl;
    int ma = 0;
    for(int i = 1; i <= N; i++) {
        if(tdis[i] < adis[i] and adis[i] > ma) {
            ma = adis[i];
        }        
    }

    cout << ma-1 << endl;
}