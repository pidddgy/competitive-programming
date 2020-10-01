// https://dmoj.ca/problem/usaco19margold2

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

const int maxn = 8000;
const int INF = INT_MAX-300;
int N, K;
long long dis[maxn];
bool vis[maxn];

int f(int a, int b) {
    return ((min(a, b)*2019201913LL) + (max(a, b)*2019201949LL))% 2019201997LL;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for(int i = 0; i < maxn; i++) {
        dis[i] = LLONG_MAX-500;
    }
    
    for(int it = 1; it <= N; it++) {
        int mi = -1;
        for(int i = 1; i <= N; i++) {
            if(!vis[i] and ((mi == -1) or (dis[i] < dis[mi]))) {
                mi = i;
            }
        }

        vis[mi] = true;
        for(int i = 1; i <= N; i++) {
            if(!vis[i]) {
                dis[i] = min(dis[i], f(mi, i));
            }
        }
    }

    sort(dis+1, dis+N+1);
    // for(int i = 1; i <= N; i++) {
    //     cerr << dis[i] << " ";
    // }
    // cerr << endl;
    cout << dis[N+1-K] << endl;
}