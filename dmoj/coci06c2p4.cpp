// https://dmoj.ca/problem/coci06c2p4

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'

int trng(int n) {
    return (n*(n+1))/2;
}

int sq(int n) {
    return n*n;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout <<  n*(n-1)*(n-2)*(n-3)/24 << endl;
}