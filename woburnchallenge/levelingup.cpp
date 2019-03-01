// http://wcipeg.com/problem/wc183i2

#include <bits/stdc++.h>

const int maxP = 100000;
int line[maxP];

using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < maxP; i++) line[i] = -1;

    int N;
    cin >> N;

    int S, L; // S = Jessie's starting position, L = Arboks starting level
    cin >> S >> L;

    int P[N]; // where pokemon is located
    int M[N]; // level of pokemon
    int G[N]; // how many levels we get by murdering this pokemon
    
    for(int i = 0; i < N; i++) {
        cin >> P[i] >> M[i] >> G[i];
        line[P[i]] = i;
    }

    for(;;) {
        // id of pokemon
        int l = -1;
        int r = -1;

        for(int i = S; i > 0; i--) {
            if(line[i] != -1) {
                if(M[line[i]] <= L) {
                    l = line[i];
                }
                break;
            }
        }

        for(int i = S; i < maxP; i++) {
            if(line[i] != -1) {
                if(M[line[i]] <= L) {
                    r = line[i];
                }
                break;
            }
        }

        if(l == -1 && r == -1) break;

        int lg = G[l];
        int rg = G[r];

        if(lg >= rg) { // default to left
            L += lg;
            S = P[l];
            line[S] = -1;

        } else if (rg > lg) {
            L += rg;
            S = P[r];
            line[S] = -1;

        }

    }
    cout << L << endl;
}
