// https://dmoj.ca/problem/dmopc14c2p5

#include <bits/stdc++.h>
#define maxn 1000500
#define ld long double
#define endl '\n'

using namespace std;

vector<int> G[maxn];
bool vis[maxn];
ld prob[maxn];
vector<int> sorted;
int N, M;

void dfs(int at) {
    vis[at] = true;

    for(int to: G[at]) {
        if(!vis[to]) {
            dfs(to);
        }
    }

    sorted.emplace_back(at);
}

int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    for(int i = 1; i <= M; i++) {
        int I, J;
        cin >> I >> J;
        G[I].emplace_back(J);
    }

    dfs(1);
    prob[1] = 1;

    reverse(sorted.begin(), sorted.end());
    for(int i: sorted) {
        for(int j: G[i]) {
            prob[j] += prob[i] / G[i].size();
        }
    }




    for(int i = 1; i <= N; i++) {
        if(G[i].size() == 0) {
            cout << fixed << setprecision(12)<< prob[i] << endl;
        }
    }

}