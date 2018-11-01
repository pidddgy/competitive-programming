// https://dmoj.ca/problem/tsoc16c1p4

#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
using namespace std;

int main() {
    int holesNeeded = 0;
    int height; int width;
    scanf("%i%i", &height, &width);

    char lab[height][width];
    vector < pair <int, int> > monkeys;
    for(int row = 0; row < height; row++) {
        for(int rowCell = 0; rowCell < width; rowCell++) {
            char cell;
            scanf(" %c", &cell);

            lab[row][rowCell] = cell;
            if(cell == 'M')
                monkeys.emplace_back(row, rowCell);
        }
    }

    bool visited[height][width];
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++)
            visited[i][j] = false;
    }

    for(auto monkey : monkeys) {
        if(!visited[monkey.first][monkey.second]) {

            visited[monkey.first][monkey.second] = true;
            holesNeeded++;
            queue<pair<int, int>> Q;
            Q.push(monkey);

            while(!Q.empty()) {
                int x = Q.front().first;
                int y = Q.front().second;
                Q.pop();
                if(!(lab[x][y] == '#')) {
                    
                    // Upwards neighbour
                    if(!visited[x - 1][y]) {
                        Q.push({ x - 1, y }); 
                        visited[x - 1][y] = true;
                    }

                    // Right neighbour
                    if(!visited[x][y + 1]) {
                        Q.push({ x, y + 1}); 
                        visited[x][y+1] = true;
                    }

                     // Downwards neghbour
                    if(!visited[x + 1][y]) {
                        Q.push({ x + 1, y });
                        visited[x + 1][y] = true;
                    }

                    // Left neighbour
                    if(!visited[x][y - 1]) {
                        Q.push({ x, y - 1}); 
                        visited[x][y - 1] = true;
                    }
                }
            }
        }
    }
    printf("%i\n", holesNeeded);
    return 0;
}
