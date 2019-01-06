// https://dmoj.ca/problem/ccc07s1

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    scanf("%i", &N);
    for(int i = 0; i < N; i++) {
        int y; int m; int d;
        scanf("%i%i%i", &y, &m, &d);
        if(y < 1989)
            printf("Yes\n");
        else if (y == 1989)
            if(m < 2)
                printf("Yes\n");
            else if (m == 2 && d <= 27)
                printf("Yes\n");
            else
                printf("No\n");
        else
            printf("No\n");
    }
}
