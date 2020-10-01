// https://atcoder.jp/contests/abc146/tasks/abc146_b

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    for(char x: s) {
        char ree = (((x-'A')+n)%26)+'A';
        cout << ree;
    }
    cout << endl;
}