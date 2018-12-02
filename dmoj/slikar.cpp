#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
using namespace std;
const int MAX_INT = numeric_limits<int>::max();

int main() {
    int rows; 
    int cols;
    scanf("%i%i", &rows, &cols);

    int denr;
    int denc;
    int pr;
    int pc;
    vector<pair<int, int>> flooded;
    char forest[rows][cols];
    int waterDist[rows][cols];
    int dist[rows][cols];

    // Set all waterDist and dist to MAX_INT
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            waterDist[i][j] = MAX_INT;
            dist[i][j] = MAX_INT;
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf(" %c ", &forest[i][j]);

            if(forest[i][j] == '*')
                flooded.emplace_back(i, j);     
            if(forest[i][j] == 'D') {
                denr = i;
                denc = j;
            }
            if(forest[i][j] == 'S') {
                pr = i;
                pc = j;
            }
        }
    }

    // Set waterDist to correct dists
    for(auto flood: flooded) {
        queue<int> rQ;
        queue<int> cQ;
        rQ.push(flood.first);
        cQ.push(flood.second);
        waterDist[flood.first][flood.second] = 0;

        while(!rQ.empty()) {
            int r = rQ.front();
            int c = cQ.front();
            rQ.pop(); cQ.pop();

            // Up
            if(r-1 >= 0 && waterDist[r-1][c] > waterDist[r][c] + 1 && forest[r-1][c] == '.') {
                waterDist[r-1][c] = waterDist[r][c] + 1;
                rQ.push(r-1);
                cQ.push(c);
            }

            // Right
            if(c+1 < cols && waterDist[r][c+1] > waterDist[r][c] + 1 && forest[r][c+1] == '.') {
                waterDist[r][c+1] = waterDist[r][c] + 1;
                rQ.push(r);
                cQ.push(c+1);
            }

            // Down
            if(r+1 < rows && waterDist[r+1][c] > waterDist[r][c] + 1 && forest[r+1][c] == '.') {
                waterDist[r+1][c] = waterDist[r][c] + 1;
                rQ.push(r+1);
                cQ.push(c);
            }

            // Left
            if(c-1 >= 0 && waterDist[r][c-1] > waterDist[r][c] + 1 && forest[r][c-1] == '.') {
                waterDist[r][c-1] = waterDist[r][c] + 1;
                rQ.push(r);
                cQ.push(c-1);
            }
        }
    }

    // BFS to get shortest distance from hedgehogs to den that doesn't result in getting flooded
    queue<int> rQ;
    queue<int> cQ;
    rQ.push(pr);
    cQ.push(pc);
    dist[pr][pc] = 0;

    while(!rQ.empty()) {
            int r = rQ.front();
            int c = cQ.front();
            rQ.pop(); cQ.pop();

            // Up
            if(r-1 >= 0 && dist[r-1][c] > dist[r][c] + 1 && forest[r-1][c] != 'X' && waterDist[r-1][c] > dist[r][c] + 1) {
                dist[r-1][c] = dist[r][c] + 1;
                rQ.push(r-1);
                cQ.push(c);
            }

            // Right
            if(c+1 < cols && dist[r][c+1] > dist[r][c] + 1 && forest[r][c+1] != 'X' && waterDist[r][c+1] > dist[r][c] + 1) {
                dist[r][c+1] = dist[r][c] + 1;
                rQ.push(r);
                cQ.push(c+1);
            }

            // Down
            if(r+1 < rows && dist[r+1][c] > dist[r][c] + 1 && forest[r+1][c] != 'X' && waterDist[r+1][c] > dist[r][c] + 1) {
                dist[r+1][c] = dist[r][c] + 1;
                rQ.push(r+1);
                cQ.push(c);
            }

            // Left
            if(c-1 >= 0 && dist[r][c-1] > dist[r][c] + 1 && forest[r][c-1] != 'X' && waterDist[r][c-1] > dist[r][c] + 1) {
                dist[r][c-1] = dist[r][c] + 1;
                rQ.push(r);
                cQ.push(c-1);
            }
    }

    if(dist[denr][denc] == MAX_INT)
        printf("KAKTUS\n");
    else
        printf("%i\n", dist[denr][denc]);
}
