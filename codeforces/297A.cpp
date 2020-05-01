// https://codeforces.com/contest/297/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    if(count(a.begin(), a.end(), '1')+count(a.begin(), a.end(), '1')%2 >= count(b.begin(), b.end(), '1')) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}