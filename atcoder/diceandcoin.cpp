// https://atcoder.jp/contests/abc126/tasks/abc126_c

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define ld long double
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    ld base = 1.0/N;
    ld tot = 0;
    for(int i = 1; i <= N; i++) {
        int cur = i;
        int flip = 0;
        while(cur < K) {
            cur*=2;
            flip++;
        }

        tot += base * (pow(0.5, flip));
    }
    cout << setprecision(420) << tot << endl;
}
