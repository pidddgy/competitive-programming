// https://atcoder.jp/contests/abc155/tasks/abc155_c

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    map<string, int> cnt;

    int ma = 0;
    while(N--) {
        string s;
        cin >> s;

        cnt[s]++;
        ma = max(ma, cnt[s]);
    }

    for(pair<string, int> x: cnt) {
        if(x.second == ma) {
            cout << x.first << endl;
        }
    }
}