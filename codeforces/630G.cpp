// https://codeforces.com/contest/630/problem/G

using namespace std;
#include <bits/stdc++.h>
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

int nk(int n, int k) {
    watch(n)
    watch(k)
    int top = 1;

    for(int i = 0; i < k; i++) {
        cerr << "multiplying top by " << n-i << endl;
        top *= n-i;
    }

    int bot = 1;

    for(int i = 1; i <= k; i++) {
        cerr << "multiplying bot by " << i << endl;
        bot *= i;
    }

    return top/bot;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    watch(nk(3+n-1, 3))
    watch(nk(5+n-1, 5))
    cout << nk(3+n-1, 3) * nk(5+n-1, 5) << endl;
}