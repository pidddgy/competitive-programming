// https://codeforces.com/contest/1330/problem/B

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool istrng(int n) {
    int x = (8*n)+1;

    return(sqrt(x) * sqrt(x) == x);
}
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cout << istrng(4) << endl;
}