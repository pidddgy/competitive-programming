#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize "Ofast"
int main() {
    int N; int K;
    scanf("%i %i", &N, &K);

    int totalScores[N];
    int worstRanks[N];

    // Fill totalScores and worstRanks with 0
    for(int i = 0; i < N; i++)  {
        totalScores[i] = 0;
        worstRanks[i] = 0;
    }

    for(int rnd = 0; rnd < K; rnd++) {
        for(int plyr = 0; plyr < N; plyr++) {
            int scr;
            scanf("%i",  &scr);
            totalScores[plyr] += scr;
        }

        for(int j = 0; j < N; j++) {
            int r = 1;
            for(int l = 0; l < N; l++)
                if(totalScores[l] > totalScores[j]) r++;

            if(worstRanks[j] < r) worstRanks[j] = r;
        }
    }

    int highestScore = *max_element(totalScores, totalScores+N);

    for(int i = 0; i < N; i++)
        if(totalScores[i] == highestScore) 
            printf("Yodeller %i is the TopYodeller: score %i, worst rank %i \n", i+1, highestScore, worstRanks[i]);
}
