// https://codeforces.com/contest/1234/problem/D

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
const int maxn = 100500;
string s;
int N;

int bit[26][maxn];

int prefsum(char letter, int pos) {
    int res = 0;
    for(int i = pos; i >= 1; i -= i&-i) {
        res += bit[letter-'a'][i];
    }
    return res;
}

int query(int letter, int l, int r) {
    return prefsum(letter, r) - prefsum(letter, l-1);
}

void update(char letter, int pos, int val) {
    for(int i = pos; i <= N; i += i&-i) {
        bit[letter-'a'][i] += val;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    N = s.size();
    s = "."+s;   

    for(int i = 1; i <= N; i++) {
        update(s[i], i, 1);
    }

    int q;
    cin >> q;

    while(q--) {
        int type;
        cin >> type;

        if(type == 1) {
            int pos;
            char c;
            cin >> pos >> c;

            update(s[pos], pos, -1);
            s[pos] = c;
            update(s[pos], pos, 1);
        } else {
            int l, r;
            cin >> l >> r;

            int ans = 0;

            for(char x: string("abcdefghijklmnopqrstuvwxyz")) {
                ans += (query(x, l, r) > 0);
            }

            cout << ans << endl;
        }
    }
}