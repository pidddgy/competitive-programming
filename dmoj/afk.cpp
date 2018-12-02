// https://dmoj.ca/problem/dmopc13c1p4
#include <bits/stdc++.h>
using namespace std;

const int MAX_INT = numeric_limits<int>::max();
int main() {
    int t;
    scanf("%i",  &t);
    for(int tc = 0; tc < t; tc++) {
        int rows; int cols;
        scanf("%i%i", &cols, &rows);
        
        int compr;
        int compc;
        int washr;
        int washc;
        char house[rows][cols];
        int dist[rows][cols];
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                scanf(" %c ",&house[r][c]);
                if(house[r][c] == 'C') {
                    compr = r;
                    compc = c;
                } else if (house[r][c] == 'W') {
                    washr = r;
                    washc = c;
                }
                dist[r][c] = MAX_INT;
            }
        }

        queue<int> rQ;
        queue<int> cQ;
        rQ.push(compr);
        cQ.push(compc);
        dist[compr][compc] = 0;
        bool found = false;

        while(!rQ.empty()) {
            int r = rQ.front();
            int c = cQ.front();
            rQ.pop(); cQ.pop();

            if(r == washr && c == washc) {
                if(dist[r][c] < 60) {
                    printf("%i\n", dist[r][c]);
                    found = true;
                }
            }

            // Push top if doesnt go past wall and is not X
            if(r-1 >= 0 && house[r-1][c] != 'X' && dist[r-1][c] > dist[r][c] + 1) {
                rQ.push(r-1);
                cQ.push(c);
                dist[r-1][c] = dist[r][c] + 1;
            }

            // Push right if doesnt go past wall and is not X
            if(c+1 < cols && house[r][c+1] != 'X' && dist[r][c+1] > dist[r][c] + 1) {
                rQ.push(r);
                cQ.push(c+1);
                dist[r][c+1] = dist[r][c] + 1;
            }
            
            // Push down if doesnt go past wall and is not X
            if(r+1 < rows && house[r+1][c] != 'X' && dist[r+1][c] > dist[r][c] + 1) {
                rQ.push(r+1);
                cQ.push(c);
                dist[r+1][c] = dist[r][c] + 1;
            }

            // Push left if doesnt go past wall and is not X
            if(c-1 >= 0 && house[r][c-1] != 'X' && dist[r][c-1] > dist[r][c] + 1) {
                rQ.push(r);
                cQ.push(c-1);
                dist[r][c-1] = dist[r][c] + 1;
            }
        }
        if(!found)
            printf("#notworth\n");
    }
}
