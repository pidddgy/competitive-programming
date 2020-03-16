// https://codeforces.com/contest/1321/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int N;
    cin >> N;

    int a[N+1];
    int b[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        b[i] = a[i]-i;
    }

    unordered_map<int, int> cnt;

    for(int i = 1; i <= N; i++) {
        cnt[b[i]] += a[i];
    }

    int ma = -INT_MAX;
    for(pair<int, int> x: cnt) {
        ma = max(ma, x.second);
    }

    cout << ma << endl;
}