// https://dmoj.ca/problem/dmopc15c6p2

#include <bits/stdc++.h>
#define ld long double
using namespace std;
int main() {
    ld ans = 0;
    int N;
    cin >> N;

    while(N--) {
        ld a;
        cin >> a;
        
        ans += a;
    }

    cout << setprecision(6) << fmod(ans, 360) << endl;
}
