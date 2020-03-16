// http://codeforces.com/contest/1196/problem/D1

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int q;
    cin >> q;

    while(q--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        for(int i = 0; i < 2100; i++) {
            s += ".";
        }

        s = "."+s;

        // watch(s);


        char a[4] = {'.', 'R', 'G', 'B'};

        int ans = k;
        // watch(ans)
        
        for(int i = 1; i <= n; i++) {
            // watch(i)
            // cout << "trying " << i << " to " << i+k-1 << endl;
            int cur;
            if(s[i] == 'R') cur = 1;
            if(s[i] == 'G') cur = 2;
            if(s[i] == 'B') cur = 3;

            int edit = 0;
            for(int j = i; j <= i+k-1; j++) {
                if(s[j] != a[cur]) {
                    // cout << "edit on " << j << endl;
                    edit++;
                }

                cur++;
                if(cur == 4) cur = 1;
            }

            ans = min(edit, ans);
        }

        cout << ans << endl;
    }
}