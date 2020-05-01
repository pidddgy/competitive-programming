// https://codeforces.com/contest/1335/problem/E2

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;

        int a[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int cnt[205][n+1];
        for(int i = 0; i < 205; i++) {
            for(int j = 0; j < n+1; j++) {
                cnt[i][j] = 0;
            }
        }
        vector<int> pos[205];

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 200; j++) {
                cnt[j][i] = cnt[j][i-1];
            }

            cerr << "incrementing " << a[i] << " " << i << endl;
            cnt[a[i]][i]++;
            pos[a[i]].emplace_back(i);
        }

        watch(cnt[2][n])
        for(int i = 1; i <= n; i++) {
            cerr << cnt[2][i] << " ";
        }
        cerr << endl;

        int ans = 0;
        for(int i = 1; i <= 200; i++) {
            ans = max(ans, (int)pos[i].size());
            cerr << "on " << i << endl;
            for(int p = 0; p < pos[i].size()/2; p++) {
                int l = pos[i][p]+1;
                int r = pos[i][(int)pos[i].size()-1-p]-1;
                cerr << "trying " << l << " " << r << endl;

                for(int el = 1; el <= 200; el++) {
                    int sum = cnt[el][r]-cnt[el][l-1];
                    cerr << el << " is " << sum << endl;
                    ans = max(ans, (p+1)*2 + sum);
                }
            }

        }

        cout << ans << endl;
    }
}