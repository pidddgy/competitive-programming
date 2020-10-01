// https://dmoj.ca/problem/ccc15j5

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()

int ans = 0;
int n, k;

unordered_map<int, int> cache;

int h(int a, int b, int c) {
    int ret = a;
    ret *= 9137;
    ret += b;
    ret *= 9137;
    ret += c;
    ret *= 9137;
    return ret;
}

int f(int p, int rem, int last) {
    if(cache.count(h(p, rem, last))) {
        return cache[h(p, rem, last)];
    }

    if(p == 0) {
        return (rem == 0);
    }

    if(rem == 0) return 0;

    int l = last;

    int sum = 0;
    for(int i = l; i <= rem/p; i++) {
        sum += f(p-1, rem-i, i);
    }

    cache[h(p, rem, last)] = sum;
    return sum;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n/k; i++) {
        ans += f(k-1, n-i, i);
    }

    cout << ans << endl;
}
