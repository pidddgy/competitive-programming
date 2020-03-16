// https://codeforces.com/contest/1300/problem/B

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;
        N *= 2;

        // watch(N)

        int a[N];
        for(int i = 0; i < N; i++) {
            cin >> a[i];
        }

        sort(a, a+N);   

        int ans = INT_MAX;

        for(int i = 0; i < N/2; i++) {
            ans = min(ans, abs(a[i] - a[N-i-1]));
        }

        cout << ans << endl;
    }
}