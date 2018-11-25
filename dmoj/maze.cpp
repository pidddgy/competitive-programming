#include <bits/stdc++.h>
using namespace std;
const int MAX = 999;
int main() {
    int T;
    scanf("%i", &T);

    for(int c = 0; c < T; c++) {
        int R;
        int C;
        scanf("%i%i", &R, &C);
        char city[R][C];
        int stepArray[R][C];

        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                stepArray[i][j] = MAX;
            }
        }
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                char is;
                scanf(" %c", &is);
                city[i][j] = is;
            }
        }
        int output = -1;
        queue<int> rQ;
        queue<int> cQ;

        rQ.push(0);
        cQ.push(0);
        stepArray[0][0] = 1;

        while(!rQ.empty()) {
            int r = rQ.front();
            int c = cQ.front();

            rQ.pop();
            cQ.pop();
            if(r == R-1 && c == C-1 && city[r][c] != '*') {
                output = stepArray[r][c];
                break;
            }
            if(city[r][c] == '+') {
                if(r - 1 >= 0 && stepArray[r-1][c] > stepArray[r][c] + 1) {
                    stepArray[r-1][c] = stepArray[r][c] + 1;
                    rQ.push(r - 1);
                    cQ.push(c);
                }
                if(r + 1 < R && stepArray[r+1][c] > stepArray[r][c] + 1) {
                    stepArray[r+1][c] = stepArray[r][c] + 1;
                    rQ.push(r + 1);
                    cQ.push(c);
                }
                if(c - 1 >= 0 && stepArray[r][c-1] > stepArray[r][c] + 1) {
                    stepArray[r][c-1] = stepArray[r][c] + 1;
                    rQ.push(r);
                    cQ.push(c - 1);
                }
                if(c + 1 < C && stepArray[r][c+1] > stepArray[r][c] + 1) {
                    stepArray[r][c+1] = stepArray[r][c] + 1;
                    rQ.push(r);
                    cQ.push(c + 1);
                }
            }
            if(city[r][c] == '-') {
                if(c - 1 >= 0 && stepArray[r][c-1] > stepArray[r][c] + 1) {
                    stepArray[r][c - 1] = stepArray[r][c] + 1;
                    rQ.push(r);
                    cQ.push(c - 1);
                }
                if(c + 1 < C && stepArray[r][c+1] > stepArray[r][c] + 1) {
                    stepArray[r][c+1] = stepArray[r][c] + 1;
                    rQ.push(r);
                    cQ.push(c + 1);
                }
            }
            if(city[r][c] == '|') {
                if(r - 1 >= 0 && stepArray[r-1][c] > stepArray[r][c] + 1) {
                    stepArray[r-1][c] = stepArray[r][c] + 1;
                    rQ.push(r - 1);
                    cQ.push(c);
                }
                if(r + 1 < R && stepArray[r+1][c] > stepArray[r][c] + 1) {
                    stepArray[r+1][c] = stepArray[r][c] + 1;
                    rQ.push(r + 1);
                    cQ.push(c);
                }
            }
        }
        printf("%i\n", output);
    }
}
