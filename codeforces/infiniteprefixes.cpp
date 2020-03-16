// https://codeforces.com/contest/1295/problem/B

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int T;
    cin >> T;
    while(T--) {
        int N, X;
        cin >> N >> X;

        string s;
        cin >> s;

        // watch(s)

        // Val == balance
        int val[N];
        int cur = 0;

        for(int i = 0; i < N; i++) {
            if(s[i] == '0') {
                cur++;
            } else {
                cur--;
            }

            val[i] = cur;

            // cout << val[i] << " ";
        }
        // cout << endl;
        
        int bal = val[N-1];

        int ans = 0;
        bool shit = false;
        for(int i = 0; i < N; i++) {
            // cout << "currently on " << val[i] << endl;
            // watch(X - val[i])
            // watch(bal)
            if(bal == 0) {
                // cout << "hi" << endl;
                // watch(val[i])
                // watch(X)
                if(val[i] == X) {
                    // cout << "bloop" << endl;
                    ans = -1;
                    shit = true;
                    break;
                }
            } else if(((X - val[i]) % bal) == 0) {
                if(bal < 0) {
                    if(val[i] >= X) {
                        ans++;
                    }
                } else if(bal > 0) {
                    if(val[i] <= X) {
                        ans++;
                    }
                }
            }
        }

        if(!shit) if(X == 0) ans++;
        cout << ans << endl;

    }
}