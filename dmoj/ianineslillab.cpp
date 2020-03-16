// https://dmoj.ca/problem/utso18p4

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int maxv = 1e5+420;

pii bestVal[maxv];
int main() {
    for(int i = 0; i < maxv; i++) {
        bestVal[i].fi = 0;
        bestVal[i].se = 0;
    }
    int N;
    cin >> N;

    while(N--) {
        int a, b;
        cin >> a >> b;

        bestVal[a+b].fi += a;
        bestVal[a+b].se += b;
    }

    int best = 0;
    for(int i = 0; i < maxv; i++) {
        best = max(best, min(bestVal[i].fi, bestVal[i].se));
        if(i < 10)
        cout << i << " is " <<min(bestVal[i].fi, bestVal[i].se) << endl; 
    }

    cout << best << endl;
}