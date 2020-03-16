// https://codeforces.com/problemsets/acmsguru/problem/99999/184

#include <bits/stdc++.h>
using namespace std;
int main() {
    int P, M, C, K, R, V;
    cin >> P >> M >> C >> K >> R >> V;

    cout << min(P/K, min(M/R, C/V)) << endl;
}