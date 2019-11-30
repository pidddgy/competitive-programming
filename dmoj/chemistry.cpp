// https://dmoj.ca/problem/bts19p3

#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;



ull dec(ull beakers, ull cups) {
    // cout << "there are " << pow(2, beakers) << " groups " << endl;
    // cout << "poison must be in group of " << ceil(cups/(pow(2, beakers))) << endl;
    return ceil(cups/(pow(2, beakers)));
}
int main() {
    #define int unsigned long long

    int N, M;
    cin >> N >> M;

    // min size can decompose with K beakers is ceil(N / ceil(log2(K)))

    int l = 1;
    int r = ULLONG_MAX - 50;

    for(int m = 1; m <= 10000000; m++) {
        int poss = N;
        for(int i = 1; i <= M; i++) {
            poss = dec(m, poss);
            if(poss == 1) break;
        }

        if(poss == 1) {
            cout << m << endl;
            return 0;
        }

    }

}
