// https://codeforces.com/problemset/problem/1136/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;

    cout << n+1 + (min(n-k, k-1) + n-1) + n << endl; 

    // n+1 = pick up stone
    // (min(n-k, k-1) + n-1) = walking around
    // n = time spent picking up
}
