// https://codeforces.com/contest/1111/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define int long long
#define endl '\n'
#define cerr if(false) cerr
#define ld long double

const int maxn = 100500;

int a[maxn];
int psa[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++) {
        psa[i] = psa[i-1]+a[i];
    }

    ld best = 0;
    // remove i elements
    for(int i = 0; i <= min(m, n-1); i++) {
        cerr << "on " << i << endl;
        int curSum = psa[n]-psa[i];
        int rem = m-i;

        watch(curSum)
        watch(rem)

        curSum += min(rem, (n-i)*k);

        watch(n-i)


        cerr << "avg is " << fixed << setprecision(20) << (ld)curSum/(n-i) << endl;

        best = max(best, (ld)curSum/(n-i));
    }

    cout << fixed << setprecision(11) << best << endl;


}