// https://dmoj.ca/problem/dmopc19c6p5

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    #define watch(x) cerr << (#x) << " is " << (x) << endl;

    int N, Q;
    cin >> N >> Q;

    int w[N+1];
    int h[N+1];

    for(int i = 1; i <= N; i++) {
        cin >> h[i];
    }

    for(int i = 1; i <= N; i++) {
        cin >> w[i];
    }

    for(int i = 1; i <= Q; i++) {
        int l, r;
        cin >> l >> r;

        assert((r-l) <= 1);

        int ans = 0;

        ans += (w[l]*2 + h[l]*2);
        if(l != r) {
            ans += (w[r]*2 + h[r]*2);
            // watch(ans)
            ans -= min(h[l], h[r]);
        }
        cout << ans << endl;
    }
    
}