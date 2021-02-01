// https://codeforces.com/contest/227/problem/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 100500;

int n;
int a[maxn];
int psa[maxn];

int query(int l, int r) {
    return psa[r]-psa[l-1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a+1, a+n+1, greater<int>());

    for(int i = 1; i <= n; i++) {
        psa[i] = psa[i-1]+a[i];
    }

    int ans_1 = 0;
    int cur = 1;
    for(int i = 2; i <= n; i++) {
        ans_1 += a[i]*cur;
        cur++;
    }    

    int q;
    cin >> q;

    while(q--) {
        int k;
        cin >> k;

        cerr << "answering query " << k << endl;

        if(k == 1) {
            cout << ans_1 << " ";
            continue;
        }

        cur = 1;
        int gsz = 1;

        int ans = 0;
        int j = 1;
        for(int i = 2; i <= n; i += gsz) {
            gsz *= k;
            cerr << i << " " << min(n, i+gsz-1) << endl;
            watch(j)
            watch(query(i, min(n, i+gsz-1)))
            ans += query(i, min(n, i+gsz-1))*j;
            j++;
        }

        cout << ans << " ";
    }
    cout << endl;
}

/*




*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
