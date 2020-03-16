// http://codeforces.com/contest/1186/problem/0

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    if(m >= n && k >= n) {
        cout << "Yes" << endl;
    } else {
        cout << "No"  <<  endl;
    }
}