// https://codeforces.com/contest/1379/problem/0

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()

string NEEDLE = "abacaba";
int nsz = NEEDLE.size();
int N;

int f (string s) {
    int freq = 0;
    for(int i = 0; i < N; i++) {
        bool ok = true;
        for(int j = 0; j < nsz; j++) {
            if(s[i+j] != NEEDLE[j]) {
                ok = false;
            }
        }

        if(ok) freq++;
    }

    return freq;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        cin >> N;

        string s;
        cin >> s;

        bool found = false;
        for(int i = 0; i+nsz-1 < N; i++) {
            string cpy = s;
            bool bad = false;
            for(int j = 0; j < nsz; j++) {
                if(cpy[i+j] != '?' and cpy[i+j] != NEEDLE[j]) {
                    bad = true;
                }
                cpy[i+j] = NEEDLE[j];
            }

            if(bad) continue;

            if(f(cpy) == 1) {
                found = true;
                cout << "Yes" << endl;
                for(char x: cpy) {
                    if(x == '?') {
                        cout << "z";
                    } else {
                        cout << x;
                    }
                }
                cout << endl;
                break;
            }
        }

        if(!found) {
            cout << "No" << endl;
        }
    }
}
