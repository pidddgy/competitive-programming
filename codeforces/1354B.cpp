// https://codeforces.com/contest/1354/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

#define cerr if(false) cerr
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        int N = s.size();
        s = "."+s;

        int psa[5][N+5];
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < N+5; j++) {
                psa[i][j] = 0;
            }
        }

        for(int i = 1; i <= N; i++) {
            psa[s[i]-'0'][i]++;
        }

        for(int i = 1; i <= 3; i++) {
            for(int j = 1; j <= N; j++) {
                psa[i][j] += psa[i][j-1];
            }
        }

        // for(int i= 1; i <= 3; i++) {
        //     for(int j = 1; j <= N; j++) {
        //         cerr << psa[i][j] << " ";
        //     }
        //     cerr << endl;
        // }

        int ans = INT_MAX;
        for(int i = 1; i <= N; i++) {
            int l = i;
            int r = N;
            int lastgood = -1;
            while(l <= r) {
                int m = (l+r)/2;

                bool ok = true;

                cerr << "trying " << i << " " << m << endl;
                for(int j = 1; j <= 3; j++) {
                    if(psa[j][m] - psa[j][i-1] <= 0) {
                        cerr << "failed on " << j << endl;
                        ok = false;
                    }
                }

                if(ok) {
                    lastgood = m;
                    r = m-1;
                } else {
                    l = m+1;
                }
            }

            if(lastgood != -1) {
                ans = min(ans, lastgood-i+1);
            }
        }

        if(ans == INT_MAX) {
            cout << 0 << endl;
        } else {
            cout << ans << endl;
        }        
    }
}
