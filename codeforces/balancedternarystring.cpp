// https://codeforces.com/contest/1102/problem/D

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

    string s;
    cin >> s;
    s = "."+s;

    int cnt[3];
    for(int i = 0; i < 3; i++) {
        cnt[i] = count(s.begin(), s.end(), i+'0');
    }

    if(cnt[0] < n/3) {
        for(int i = 1; i <= n; i++) {
            if(s[i] != '0' and cnt[s[i]-'0']>(n/3)) {
                cnt[s[i]-'0']--;
                s[i] = '0';
                cnt[0]++;
            }
            if(cnt[0] == n/3) break;
        }
    }

    if(cnt[2] < n/3) {
        for(int i = n; i >= 1; i--) {
            if(s[i] != '2' and cnt[s[i]-'0'] > n/3) {
                cnt[s[i]-'0']--;
                s[i] = '2';
                cnt[2]++;
            }
            if(cnt[2] == n/3) break;
        }
    }

    if(cnt[1] < n/3) {
        for(int i = 1; i <= n; i++) {
            if(s[i] == '2' and cnt[2] > n/3) {
                cnt[2]--;
                s[i] = '1';
                cnt[1]++;
            }
            if(cnt[1] == n/3) break;
        }
        
        if(cnt[1] < n/3)
        for(int i = n; i >= 1; i--) {
            if(s[i] == '0' and cnt[0] > n/3) {
                cnt[0]--;
                s[i] = '1';
                cnt[1]++;
            }
            if(cnt[1] == n/3) break;
        }
    }



    assert(cnt[0] == n/3);
    assert(cnt[1] == n/3);
    assert(cnt[2] == n/3);


    for(int i = 1; i <= n; i++) {
        cout << s[i];
    }
    cout << endl;


}