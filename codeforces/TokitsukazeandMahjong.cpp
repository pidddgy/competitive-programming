// http://codeforces.com/contest/1191/problem/B

#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int cnt[26];
int main() {
    int a;
    char b;

    for(int i = 0; i < 3; i++) {
        cin >> a >> b;
        cnt[b-'a']++;
    }

    int ma = 0;
    for(int i = 0; i < 26; i++) {
        ma = max(ma, cnt[i]);
    }

    cout << 3-ma << endl;

}