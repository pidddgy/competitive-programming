// https://codeforces.com/contest/1272/problem/E

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int INF = INT_MAX-200;
const int maxn = 200500;
// stores in reverse
vector<int> G[maxn];

// dis -> even to odd, dis2 -> odd to even
int dis[maxn], dis2[maxn];
int a[maxn];

void bfs(queue<int> Q, int arr[]) {
    while(!Q.empty()) {
        int S = Q.front();
        Q.pop();

        for(int adj: G[S]) {
            if(arr[adj] > arr[S]+1) {
                Q.push(adj);
                arr[adj] = arr[S]+1;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        a[i] = x;

        if(i-x >= 1) {
            G[i-x].emplace_back(i);
        }

        if(i+x <= n) {
            G[i+x].emplace_back(i);
        }
    }

    for(int i = 1; i <= n; i++) {
        dis[i] = dis2[i] = INF;
    }
    queue<int> even, odd;
    for(int i = 1; i <= n; i++) {
        if(a[i] & 1) {
            odd.push(i);
            dis2[i] = 0;
        } else {
            even.push(i);
            dis[i] = 0;
        }
    }

    bfs(even, dis);
    bfs(odd, dis2);

    for(int i = 1; i <= n; i++) {
        if(a[i] & 1) {
            if(dis[i] == INF) {
                cout << -1 << " ";
            } else {
                cout << dis[i] << " ";
            }
        } else {
            if(dis2[i] == INF) {
                cout << -1 << " ";
            } else {
                cout << dis2[i] << " ";
            }
        }
    }

    cout << endl;
}
