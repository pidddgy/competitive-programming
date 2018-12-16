// https://dmoj.ca/problem/ecoo18r1p1

#include <bits/stdc++.h>
using namespace std;
int main() {
   for(int tc = 0; tc < 10; tc++) {
        int T, N;
        scanf("%i%i", &T, &N);

        queue<int> Q;
        char days[N];
        int delayed = 0;
        int currentBox = 0;

        for(int j = 0; j < N; j++)
            scanf(" %c", &days[j]);

        for(int j = 0;; j++) {
            if(days[j] == 'B')
                Q.push(j);

            if(currentBox > 0) 
                currentBox--;

            if(currentBox == 0) {
                if(!Q.empty()) {
                    currentBox = T;
                    Q.pop();
                } else if (Q.empty() && j >= N)
                    break;
            }
            
            if(j >= N)
                delayed++;
        }
        printf("%i\n", delayed);
    }
}
