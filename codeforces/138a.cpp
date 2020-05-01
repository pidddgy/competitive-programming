// https://codeforces.com/contest/138/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
const string vowels = "aeiou";
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, K;
    cin >> n >> K;

    string scheme = "?";

    for(int i = 1; i <= n; i++) {
        string qua[5];
        for(int j = 1; j <= 4; j++) {   
            cin >> qua[j];
            watch(qua[j])
        }

        string suf[5];
        for(int j = 1; j <= 4; j++) {
            int vow = 0;
            string cur = "";
            cerr << "on " << qua[j] << endl;
            for(int k = qua[j].size()-1; k >= 0; k--) {
                cur.push_back(qua[j][k]);
                if(vowels.find(qua[j][k]) != string::npos) {
                    cerr << "index " << k << " is vowel" << endl;
                    watch(cur)
                    vow++;
                    watch(cur)
                }
                watch(cur)
                if(vow == K) {
                    cerr << "breaking with " << cur << endl;
                    break;
                }
            }

            watch(cur)
            reverse(cur.begin(), cur.end());

            if(vow != K) {
                watch(j);
                cerr << "failed on " << qua[j] << endl;
                cout << "NO" << endl;
                return 0;
            }

            watch(cur)
            suf[j] = cur;
            cerr << endl;
        }

        string pattern = "a";
        string a = suf[1];
        string b = "?";

        watch(suf[1])
        watch(suf[3])
        for(int j = 2; j <= 4; j++) {
            if(suf[j] != a) {
                if(b == "?") {
                    b = suf[j];
                } else if(suf[j] != b) {
                    cout << "NO" << endl;
                    return 0;
                }
            }

            if(suf[j] == a) pattern.push_back('a');
            else if(suf[j] == b) pattern.push_back('b');
        }

        if(pattern == "aaaa") continue;
        if(scheme == "?") {
            scheme = pattern;
        } else if(pattern != scheme) {
            cout << "NO" << endl;
            return 0;
        }
    }

    if(scheme == "?") {
        cout << "aaaa" << endl;
    } else if(set<string>({"aabb", "abab", "abba", "aaaa"}).count(scheme)) {
        cout << scheme << endl;
    } else {
        cout << "NO" << endl;
    }
}