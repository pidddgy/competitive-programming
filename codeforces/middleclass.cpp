// https://codeforces.com/contest/1334/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define ld long double
#define cerr if(false) cerr
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int N;
        ld X;
        cin >> N >> X;


        int a[N+1];
        for(int i = 1; i <= N; i++) {
            cin >> a[i];
        }

        sort(a+1, a+N+1, greater<int>());
        int psa[N+1];
        psa[0] = 0;
        for(int i = 1; i <= N; i++) {
            psa[i] = psa[i-1]+a[i];
        }

        int w[N+1];
        for(int i = 1; i <= N; i++) w[i] = 0;

        for(int i = N; i >= 1; i--) {
            if(a[i] > X) {
                // cerr << i << " greater than " << X << endl;
                w[i]++;
            }
            if(i < N) w[i] += w[i+1];
        }

        for(int i = 1; i <= N; i++) {
            cerr << psa[i] << " ";
        }
        cerr << endl;

        int ans = 0;
        for(int i = 1; i <= N; i++) {
            ld avg = (ld)psa[i] / i;
            cerr << i << " is " << avg << endl;
            int tot = w[i+1];
            if(i == N) tot = 0;
            if(avg >= X) {
                tot += i;
            }
            watch(tot)
            ans = max(ans, tot);
            cerr << "ans is now " << ans << endl;
        }

        cout << ans << endl;
    }
}