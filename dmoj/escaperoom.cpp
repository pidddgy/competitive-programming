#include <bits/stdc++.h>
using namespace std;


#define maxnm 1005
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define pii pair<int, int>
#define fi first
#define se second

int a[maxnm][maxnm];
bool vis[maxnm][maxnm];
int M, N;
set<int> fuckk;


void recurse(int r, int c) {
    if(vis[M][N]) return;
    vis[r][c] = true;
    int val = a[r][c];
    
    if(fuckk.find(val) == fuckk.end())
    for(int i = 1; i <= min(val, (int)(sqrt(val) + 5)); i++) {
        if((val % i) == 0) {
            int other = val / i;

            if(i <= M) {
if(other <= N)
            if((!vis[i][other]) and (i <= M) and (other <= N)) {
                recurse(i, other);
            }
            }
            

            if(other <= M) {
                if(i <= N)
                if((!vis[other][i]) and (other <= M) and (i <= N)) {
                    recurse(other, i);
                }
            }

        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    #define endl '\n'

    cin >> M >> N;
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> a[i][j];
            vis[i][j] = false;
        }
    }

    recurse(1, 1);

    if(vis[M][N]) cout << "yes" << endl;
    else cout << "no" << endl;
}