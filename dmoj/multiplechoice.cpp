#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    int correct;
    scanf("%i ", &N);
    char key[N];
    char answers[N];

    for(int i = 0; i < N; i++)
        scanf("%c ", &answers[i]);
    for(int i = 0; i < N; i++)
        scanf("%c ", &key[i]);

    for(int i = 0; i < N; i++)
        if(key[i] == answers[i]) correct++;

    printf("%i\n", correct);
}
