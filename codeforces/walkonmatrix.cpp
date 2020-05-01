// https://codeforces.com/contest/1332/problem/D

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> x;

    int big = powl(2, 17);
    int thing = big+x;
    cout << 2 << " " << 3 << endl;
    cout << thing << " " << big << " " << 0 << endl;
    cout << x << " " << thing << " " << x << endl; 
}