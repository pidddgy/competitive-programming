// https://dmoj.ca/problem/dwite09c4p5

#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#define endl '\n'
#define pii pair<int, int>
#define MAX_INT 2147483647
using namespace std;

char maze[10][10];
int cuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuute(pii a, pii b) {
    int dist[10][10];
    for(int i = 0; i < 10; i++) 
        for(int j = 0; j < 10; j++)
            dist[i][j] = MAX_INT;

    queue<pii> Q;
    Q.push(a);
    dist[a.first][a.second] = 0;

    while(!Q.empty()) {
        pii S = Q.front(); Q.pop();
        if (S.first == b.first && S.second == b.second) return dist[S.first][S.second];

        // Right
        int temp = S.second;
        for(;;temp++) {
            if(maze[S.first][temp+1] == '#' || temp+1 == 10) {
                if(dist[S.first][temp] > dist[S.first][S.second] + temp - S.second) {
                    dist[S.first][temp] = dist[S.first][S.second] + temp - S.second;
                    Q.push({S.first, temp});
                }
                break;
            }
        }
        
        // Down
        temp = S.first;
        for(;;temp++) {
            if(maze[temp+1][S.second] == '#' || temp+1 == 10) {
                if(dist[temp][S.second] > dist[S.first][S.second] + temp - S.first) {
                    dist[temp][S.second] = dist[S.first][S.second] + temp - S.first;
                    Q.push({temp, S.second});
                }
                break;
            }
        }

        // Left
        temp = S.second;
        for(;;temp--) {
            if(maze[S.first][temp-1] == '#' || temp-1 == -1) {
                if(dist[S.first][temp] > dist[S.first][S.second] + S.second - temp) {
                    dist[S.first][temp] = dist[S.first][S.second] + S.second - temp;
                    Q.push({S.first, temp});
                }
                break;
            }
        }

        // Up
        temp = S.first;
        for(;;temp--) {
            if(maze[temp-1][S.second] == '#' || temp-1 == -1) {
                if(dist[temp][S.second] > dist[S.first][S.second] + S.first - temp) {
                    dist[temp][S.second] = dist[S.first][S.second] + S.first - temp;
                    Q.push({temp, S.second});
                }
                break;
            }
        }
    }
    return -1;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    pii POI[6];

    for(int r = 0; r < 10; r++)
        for(int c = 0; c < 10; c++) {
            char sq; cin >> sq;
            maze[r][c] = sq;
            if(sq == 'A') POI[0] = {r, c};
            if(sq == 'B') POI[1] = {r, c};
            if(sq == 'C') POI[2] = {r, c};
            if(sq == 'D') POI[3] = {r, c};
            if(sq == 'E') POI[4] = {r, c};
            if(sq == 'F') POI[5] = {r, c};
        }

   for(int i = 0; i < 5; i++)
       cout << cuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuute({POI[i].first, POI[i].second}, {POI[i+1].first, POI[i+1].second}) << endl;
}
