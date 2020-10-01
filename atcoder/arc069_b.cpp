// https://atcoder.jp/contests/arc069/tasks/arc069_b

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long

int N;
string s;

int mod(int n) {
    return (n+N)%N;
}

char other(char c) {
    if(c == 'S') {
        return 'W';
    } else {
        return 'S';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> s;

    for(string x: vector<string>({"SS", "WW", "WS", "SW"})) {
        char ans[N];
        for(int i = 0; i < N; i++) {
            ans[i] = '?';
        }

        for(int i = 0; i <= 1; i++) {
            ans[i] = x[i];
        }

        for(int i = 2; i < N; i++) {
            if(s[i-1] == 'o') {
                if(ans[i-1] == 'S') {
                    ans[i] = ans[i-2];                    
                } else if(ans[i-1] == 'W') {
                    ans[i] = other(ans[i-2]);
                }
            } else if(s[i-1] == 'x') {
                if(ans[i-1] == 'S') {
                    ans[i] = other(ans[i-2]);
                } else if(ans[i-1] == 'W') {
                    ans[i] = ans[i-2];
                }
            }
        }

        // watch(ans)
        bool ok = true;
        for(int i = 0; i < N; i++) {
            int l = mod(i-1), r = mod(i+1);
            assert(l < N);
            assert(r < N);

            if(s[i] == 'o') {
                if(ans[i] == 'S') {
                    ok &= (ans[l] == ans[r]);
                } else {
                    ok &= (ans[l] != ans[r]);
                }
            } else if(s[i]=='x') {
                if(ans[i] == 'S') {
                    ok &= (ans[l] != ans[r]);
                } else {
                    ok &= (ans[l] == ans[r]);
                }
            }

            // if(!ok) {
            //     cerr << "failed on " << i << endl;
            //     break;
            // }
        }

        if(ok) {
            // cout << ans << endl;
            for(int i = 0; i < N; i++) {
                cout << ans[i];
            }
            cout << endl;
            exit(0);
            // cerr << "hiiii" << endl;
        }
    }
    cout << -1 << endl;
}
