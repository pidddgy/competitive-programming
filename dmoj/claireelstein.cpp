// https://dmoj.ca/problem/stnbd2

#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
#define eb emplace_back
using namespace std;

vector<int> G[MAXN];
int inDeg[MAXN]; // edges leading to node i
int outDeg[MAXN]; // edges going out of node i
int cnt[MAXN];

using namespace std;

ll dfs(int S) {
    if(cnt[S] != 0) return cnt[S];

    int ret = 0;
    for(int adj: G[S]) {
        if(outDeg[adj] == 0) {
            ret++;
        } else {
            ret += dfs(adj)+1;
        }
    }
    cnt[S] = ret;
    return ret;
} 


int main() {
    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;

        G[a].eb(b);
        
        inDeg[b]++;
        outDeg[a]++;
    }
    
    int out = 0;
    for(int i = 1; i <= N; i++) {
        if(inDeg[i] == 0) {
            // cout << "we start from " << i << endl;
            out += dfs(i);
        }
    }
    
    // for(int i = 1; i <= N; i++) {
    //     cout << i << " " << cnt[i] << endl;
    // }
    cout << out << endl;
}
