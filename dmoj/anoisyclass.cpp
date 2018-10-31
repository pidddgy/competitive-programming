// https://dmoj.ca/problem/anoisyclass

#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"

using namespace std;

vector<int> students[10001];

int main() {
    char canQuietClass = 'Y';
    int N; int M;
    scanf("%i%i", &N, &M);

    for(int i = 0; i < M; i++) {
        int x; int y;
        scanf("%i%i", &x, &y);
        students[x].push_back(y);
    }

    for(int i = 1; i < N + 1; i++) {
        vector<bool> visited(N+1);
        queue<int> Q;
        for(int j = 0; j < students[i].size(); j++) {
            Q.push(students[i][j]);
        }
        while(!Q.empty()) {
            int S = Q.front();
            Q.pop();
            if(S == i) {
                canQuietClass = 'N';
                break;
            }
            visited[S] = true;
            for(int adj = 0; adj < students[S].size(); adj++) {
                if(!visited[students[S][adj]])
                {
                    Q.push(students[S][adj]);
                    visited[students[S][adj]] = true;
                }
            }
        }
    }
    printf("%c\n", canQuietClass);
}
