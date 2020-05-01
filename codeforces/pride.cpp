// https://codeforces.com/contest/891/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int a[N+1];
    bool h1 = false;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        if(a[i]==1)h1=true;
    }

    if(h1) {
        int non=0;
        for(int i = 1; i <= N; i++) {
            non+=a[i]!=1;
        }

        cout << non << endl;
        return 0;
    }

    int ans = INT_MAX;
    for(int i = 1; i <= N; i++) {
        int g = a[i];
        for(int j = i+1; j <= N; j++) {
            g = gcd(g, a[j]);
            if(g == 1) {
                ans = min(ans, (j-i)+(N-1));
            }
        }
    }

    if(ans == INT_MAX) ans = -1;

    cout << ans << endl;
}