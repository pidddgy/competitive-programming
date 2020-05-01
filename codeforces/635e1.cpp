// https://codeforces.com/contest/1335/problem/E1

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
// #define cerr if(false) cerr
#define endl '\n'
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int N;
        cin >> N;



        int a[N+1];
        for(int i = 1; i <= N; i++) {
            cin >> a[i];
        }

        int psa[30][N+1];
        for(int i = 0; i < 30; i++) {
            for(int j = 0; j < N+1; j++) {
                psa[i][j] = 0;
            }
        }

        for(int i = 1; i <= N; i++) {
            psa[a[i]][i]++;
        }

        for(int i = 1; i <= 26; i++) {
            for(int j = 1; j <= N; j++) {
                psa[i][j] += psa[i][j-1];
            }
        }

        cerr << "d" << endl;
        cerr << psa[1][1] << endl;

        int ans = 0;
        for(int i = 1; i <= 26; i++) {
            for(int j = 1; j <= 26; j++) {
                // i = outside
                // j = inside
                if(i == j) continue;
                for(int k = 0; k <= N; k++) {
                    int lcnt = psa[i][k];

                    int l = 1;
                    int r = N;
                    int lastgood = -1;

                    while(l <= r) {
                        int m = (l+r)/2;

                        int rcnt = psa[i][N]-psa[i][m-1];
                        if(rcnt < lcnt) {
                            r = m-1;
                        } else if(rcnt > lcnt) {
                            l = m+1;
                        } else if(rcnt == lcnt) {
                            l = m+1;
                            lastgood = m;
                        }
                    }

                    cerr << "next" << endl;

                    if(lastgood != -1 and lastgood > k) {
                        cerr << "using " << i << " " << j << endl;
                        watch(lastgood)
                        watch(k)

                    
                        int mcnt = psa[j][lastgood] - psa[j][k];

                        watch(mcnt)
                        watch(lcnt)
                        watch(mcnt+(lcnt*2))

                        if(mcnt+(lcnt*2) == 3) return 0;
                        // if(mcnt != 0) {
                            ans = max(ans, mcnt+(lcnt*2));
                        // }

                    }
                    cerr << endl;
                }
            }
        }

        cout << ans << endl;
    }   
}