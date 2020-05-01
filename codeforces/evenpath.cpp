// https://codeforces.com/contest/1252/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    int r[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> r[i];
    }

    int c[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> c[i];
    }

    int sr[N+1];
    sr[0] = 0;
    for(int i = 1; i <= N; i++) {
        sr[i] = sr[i-1];
        if(r[i]%2==0) {
            sr[i]++;
        }
    }

    for(int i = 1; i <= N; i++) {
        cerr << sr[i] << " ";
    }
    cerr << endl;

    int sc[N+1];
    sc[0] = 0;
    for(int i = 1; i <= N; i++) {
        sc[i] = sc[i-1];
        if(c[i]%2==0) {
            sc[i]++;
        }
    }

    for(int i = 1; i <= N; i++) {
        cerr << sc[i] << " ";
    }
    cerr << endl;

    while(Q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        string ans = "NO";
        if(a > c) swap(a, c);
        if(b > d) swap(b, d);
        if(sr[c]-sr[a-1] == c-a+1 and sc[d]-sc[b-1] == d-b+1) {
            ans = "YES";
        } else if(sr[c]-sr[a-1] == 0 and sc[d]-sc[b-1] == 0) {
            ans = "YES";
        }

        cout << ans << endl;
    }

    
}