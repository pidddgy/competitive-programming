// https://codeforces.com/contest/1348/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;
        
        sort(s.begin(), s.end());

        if(s[0] != s[k-1]) {
            cout << s[k-1] << endl;
            continue;
        } 
        
        if(s[k] != s[n-1]) {
            cout << s[0];
            for(int i = k; i < n; i++) {
                cout << s[i];
            }
            cout << endl;
        } else {
            cout << s[0];
            for(int i = 0; i < ((n-k)+(k-1))/k; i++) {
                cout << s[n-1];
            }
            cout << endl;
        }
    }
}
