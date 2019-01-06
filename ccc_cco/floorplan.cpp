// https://dmoj.ca/problem/ccc03s3

#include <bits/stdc++.h>
using namespace std;
int main() {
    int tiles; 
    scanf("%i", &tiles);

    int R; int C;
    scanf("%i%i ", &R, &C);

    char house[R][C];
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            char square;
            scanf(" %c", &square);
            house[i][j] = square;
        }
    }
    bool visited[R][C];
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++)
            visited[i][j] = false;
    }

    vector<int> roomSizes;
    for(int row = 0; row < R; row++) {
        for(int col = 0; col < C; col++) {
            if(!visited[row][col] && house[row][col] == '.') {
                int roomSize = 0;
                visited[row][col] = true;
                queue<int> rQ;
                queue<int> cQ;

                rQ.push(row);
                cQ.push(col);

                while(!rQ.empty()) {
                    int r = rQ.front();
                    int c = cQ.front();
                    rQ.pop();
                    cQ.pop();

                    if(house[r][c] != 'I') {
                        roomSize++;
                        // Upwards neighbour
                        if(!visited[r - 1][c] && r-1 >= 0 && house[r-1][c] != '*') {
                            rQ.push(r - 1); 
                            cQ.push(c);
                            visited[r - 1][c] = true;
                        }

                        // Right neighbour
                        if(!visited[r][c + 1] && c+1 < C && house[r][c+1] != '*') {
                            rQ.push(r);
                            cQ.push(c+1);
                            visited[r][c+1] = true;
                        }

                        // Downwards neghbour
                        if(!visited[r + 1][c] && r+1 < R && house[r+1][c] != '*') {
                            rQ.push(r+1);
                            cQ.push(c);
                            visited[r + 1][c] = true;
                        }

                        // Left neighbour
                        if(!visited[r][c - 1] && c-1 >= 0 && house[r][c-1] != '*') {
                            rQ.push(r);
                            cQ.push(c-1);
                            visited[r][c - 1] = true;
                        }
                    }
                }  
                roomSizes.push_back(roomSize);
            }
        }
    } 
    sort(roomSizes.begin(), roomSizes.end(), [](int a, int b) {return a > b;});
    int roomsCovered = 0;
    for(auto roomSize: roomSizes) {
        if(tiles >= roomSize) {
            tiles -= roomSize;
            roomsCovered++;
        } else {
            break;
        }
    }
    if(roomsCovered == 1) {
        printf("%i room, %i square metre(s) left over\n", roomsCovered, tiles);
    } else {
        printf("%i rooms, %i square metre(s) left over\n", roomsCovered, tiles);
    }
}
