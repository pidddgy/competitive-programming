// https://codeforces.com/contest/353/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string s;
    cin >> s;

    if(!count(s.begin(), s.end(), '1')) {
        cout << 0 << endl;
        return 0;
    }

    // reverse(s.begin(), s.end());

    int lastone = -1;
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == '1') {
            lastone = i;
            break;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') ans += a[i];
    }

    int sum = ans;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            sum -= a[i];
            ans = max(ans, sum);
        }
        sum += a[i];
    }

    // watch(ans)
    // watch(ans2)

    cout << ans << endl;
}

/*
4382 +3975 +9055 +7554 +8395 +204 +5313 +5739 +1555 +2306 +5423+ 828+ 8108+ 9736+ 2683+ 7940 + 1249
*/