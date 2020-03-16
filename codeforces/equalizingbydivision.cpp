// http://codeforces.com/contest/1213/problem/D1

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;

    int orig[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> orig[i];
    }

    sort(orig+1, orig+N+1);
    
    int ans = 2147483647;
    for(int i = 0; i <= 200500; i++) {
        int a[N+1];
        for(int j = 1; j <= N; j++) a[j] = orig[j];
        int eq = 0;
        int op = 0;
        for(int j = 1; j <= N; j++) {
            int opsused = 0;
            while(a[j] > i) {
                a[j] = floor(a[j]/2);
                opsused++;
            }

            if(a[j] == i) {
                eq++;
                op += opsused;
            }

            if(eq == K) break;
        }


        if(eq == K) {
            // if(op < ans) {
            //     cout << "we are using " << i << endl;
            // }
            ans = min(ans, op);
        }
    }

    cout << ans << endl;

    
}