// https://dmoj.ca/problem/hci16oversleep

#include <bits/stdc++.h>
using namespace std;
const int MAX_INT = 2147483647;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    // N == rows, M == cols
    int N, M, sr, sc, er, ec;
    cin >> N >> M;

    char map[N][M];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 's') {
                sr = i;
                sc = j;
            } else if (map[i][j] == 'e') {
                er = i;
                ec = j;
            }
        }

    queue<int> rQ, cQ;
    bool vis[N][M];
    int dist[N][M]; 
    bool found = false;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) {
            vis[i][j] = false;
            dist[i][j] = MAX_INT;
        }
    
    rQ.push(sr); cQ.push(sc);
    vis[sr][sc] = true;
    dist[sr][sc] = 0;
    while(!rQ.empty()) {
        int R = rQ.front(); rQ.pop();
        int C = cQ.front(); cQ.pop();
        if (R == er && C == ec) {
            cout << dist[R][C] - 1 << "\n";
            found = true;
            break;
        }
        // Up
        if(!vis[R-1][C] && R-1 >=0 && map[R-1][C] != 'X') {
            rQ.push(R-1);
            cQ.push(C);
            vis[R-1][C] = true;
            dist[R-1][C] = dist[R][C] + 1;
        }
        // Right
        if(!vis[R][C+1] && C+1 < M && map[R][C+1] != 'X') {
            rQ.push(R);
            cQ.push(C+1);
            vis[R][C+1] = true;
            dist[R][C+1] = dist[R][C] + 1;
        }
        // Down
        if(!vis[R+1][C] && R+1 < N && map[R+1][C] != 'X') {
            rQ.push(R+1);
            cQ.push(C);
            vis[R+1][C] = true;
            dist[R+1][C] = dist[R][C] + 1;
        }
        // Left
        if(!vis[R][C-1] && C-1 >= 0 && map[R][C-1] != 'X') {
            rQ.push(R);
            cQ.push(C-1);
            vis[R][C-1] = true;
            dist[R][C-1] = dist[R][C] + 1;
        }
    }
    if(!found) cout << "-1" << "\n";
}
