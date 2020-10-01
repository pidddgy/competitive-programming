// https://codeforces.com/contest/375/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'

string arr[]={"1869","6198","1896","9186","9168","6189","8691"};

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string a;
    cin >> a;

    map<int, int> cnt;

    for(char x: a) {
        cnt[x-'0']++;
    }

    for(int x: set<int>({1, 6, 8, 9})) {
        cnt[x]--;
    }

    int rem = 0;
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= cnt[i]; j++) {
            rem *= 10;
            rem += i;
            rem %= 7;

            cout << i;
        }
    }

    cout << arr[rem];

    while(cnt[0]--) {
        cout << 0;
    }
    cout << endl;
}