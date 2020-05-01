// https://codeforces.com/contest/1046/problem/C

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, D;
    cin >> N >> D;

    int a[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    int pnts[N+1];
    for(int i = 1; i <= N; i++) {
        int _;
        cin >> _;

        pnts[i] = _;
    }

    int pos = 2;
    int toBeat = a[D]+pnts[1];
    int best = D;
    for(int i = D-1; i >= 1; i--) {
        while(pos <= N) {
            if(a[i] + pnts[pos] <= toBeat) {
                best = min(best, i);
                pos++;
                break;
            } else {
                pos++;
            }
        }
    }

    cout << best << endl;    
}