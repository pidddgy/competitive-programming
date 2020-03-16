// https://mcpt.ca/problem/acoinproblem

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

bool poss[10005];

int main() {
    poss[0] = true;
    int N, S;
    cin >> N >> S;

    int a[N+1];
    for(int i = 1; i <= N; i++) cin >> a[i];

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j < 10005; j++) {
            if(j-a[i] >= 0) {
                poss[j] = max(poss[j], poss[j-a[i]]);
            }
        }
    };

    if(poss[S]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}