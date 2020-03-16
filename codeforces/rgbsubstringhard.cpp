// http://codeforces.com/contest/1196/problem/D2

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

char a[5];
int main() {
    a[1] = 'R';
    a[2] = 'G';
    a[3] = 'B';
    int q;
    cin >> q;

    while(q--) {
        int n, k;
        string s;

        cin >> n >> k >> s;
        s = "."+s;

        int ans = 1e9;
        for(int fi = 1; fi <= 3; fi++) {
            // watch(fi)
            int cur = fi;

            int edit[n];
            edit[0] = 0;

            for(int i = 1; i <= n; i++) {
                // cout << "i is " << i << ", cur is " << cur << ",s[i] is " << s[i] << ", and a[cur] is " << a[cur] << endl;
                if(s[i] != a[cur]) edit[i] = 1;
                else edit[i] = 0;

                cur++;
                if(cur == 4) cur = 1;
            }

            for(int i = 1; i <= n; i++) {
                // watch(i)
                // watch(edit[i]);
                // cout << endl;
            }

            for(int i = 1; i <= n; i++) edit[i] += edit[i-1];
            
            int mi = 1e9;
            for(int i = k; i <= n; i++) {
                mi = min(mi, edit[i] - edit[i-k]);
            }

            ans = min(ans, mi);

            // cout << endl;
        }

        cout << ans << endl;


    }
}