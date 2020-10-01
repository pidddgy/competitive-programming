// https://atcoder.jp/contests/arc069/tasks/arc069_a

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define cerr if(false) cerr
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int l = 0;
    int r = M;

    int ans = 0;
    while(l <= r) {
        int m = (l+r)/2;

        // remove rem c pieces
        int rem = m;

        int s = N+(rem/2);
        int c = M-rem;

        if(s*2 > c) {
            // remove less
            r = m-1;
        } else {
            // if we have too many s pieces, remove more c
            l = m+1;
        }

        ans = max(ans, min(s, c/2));
    }

    cout << ans << endl;
}

/*

7 4

-> dont remove any c pieces

3 10

-> remove 2 pieces

*/