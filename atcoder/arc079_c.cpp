// https://atcoder.jp/contests/arc079/tasks/arc079_c

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()


const int maxn = 200500;

int a[maxn];
int ma() {
    int res = 0;
    for(int i = 1; i <= n; i++) {
        res = max(ma, a[i]);
    }   

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    while(max_element(a+1, a+n+1) > n-1) {
        max_element(a+1, a+n+1)--;

        for(int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}