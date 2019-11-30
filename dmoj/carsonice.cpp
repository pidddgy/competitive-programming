// https://dmoj.ca/problem/cco15p4

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 2005
#define maxm 2005
#define mp make_pair
#define endl '\n'
#define watch(x) cout << (#x) << " is " << (x) << endl;

using namespace std;

char a[maxn][maxm];
bitset<maxm> vis[maxn];
int cars = 0;
int N, M;

void dfs(pii at) {
    vis[at.fi][at.se] = true;
    
    if(a[at.fi][at.se] == 'E') {
        for(int k = at.se+1; k < M; k++) {
            if(a[at.fi][k] != '.' and !vis[at.fi][k]) {
                dfs(mp(at.fi, k));
            }
        }
    }

    if(a[at.fi][at.se] == 'S') {
        for(int k = at.fi+1; k < N; k++) {
            if(a[k][at.se] != '.' and !vis[k][at.se]) {
                dfs(mp(k, at.se));
            }
        } 
    }

    if(a[at.fi][at.se] == 'W') {
        for(int k = at.se-1; k >= 0; k--) {
            if(a[at.fi][k] != '.' and !vis[at.fi][k]) {
                dfs(mp(at.fi, k));
            }
        }
    }

    if(a[at.fi][at.se] == 'N') {
        for(int k = at.fi-1; k >= 0; k--) {
            if(a[k][at.se] != '.' and !vis[k][at.se]) {
                dfs(mp(k, at.se));
            }
        }
    }

    cout << "(" << at.fi << "," << at.se << ")" << endl;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> a[i][j];
            if(a[i][j] not_eq '.') cars++;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!vis[i][j] and a[i][j] != '.') {
                dfs(mp(i, j));
            }
        }
    }
}


// for(int i = 0; i <= N; i++) {
//     for(int j = 0; j <= M; j++) {
//         if(depend[i][j].fi != -1) {
//             cout << i << "," << j << " depends on " << depend[i][j].fi << "," << depend[i][j].se << endl;
//         }
//     }
// }

/*
3 3
..S
..E
..W
*/