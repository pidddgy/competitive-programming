// https://atcoder.jp/contests/abc154/tasks/abc154_d

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define ld long double
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;

    int a[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    int psa[N+1];
    psa[0] = 0;
    for(int i = 1; i <= N; i++) {
        psa[i] = a[i] + psa[i-1];
    }

    int bestind = -1;
    int ma = 0;
    for(int i = K; i <= N; i++) {
        if(psa[i] - psa[i-K] > ma) {
            bestind = i-K+1;
            ma = psa[i] - psa[i-K];
        }
    }
    
    watch(bestind)
    ld ev = 0;
    for(int i = bestind; i <= bestind+K-1; i++) {
        ld x = a[i];
        ev += (((x+1)*x)/2) * (1/x);
    }

    cout << fixed << setprecision(7) << ev << endl;




}