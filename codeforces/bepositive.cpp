// http://codeforces.com/contest/1130/problem/0

#include <bits/stdc++.h>
#define endl '\n'
#define watch(x) cout << (#x) << " is " << (x) << endl;

using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    long double a[N];
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int need = (N + 1) / 2;

    int lo = pow(-10, 3);
    int hi = pow(10, 3);
    for(double i = lo; i < hi; i++) {
        if(i == 0) continue;
        int p = 0;
        for(int j = 0; j < N; j++) {
            if( (a[j] / i) > 0) {
                p++;
            }
        }
        if(p >= need) {
            cout << i << endl;
            return 0;
        }
    }

    cout << 0 << endl;
}
