// https://codeforces.com/contest/1156/problem/C

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

const int maxn = 200500;

int n, z;
int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> z;

    for(int i =  1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);

    int l = 1;
    int r = n/2;

    int lgood = 0;
    while(l <= r) {
        int mid = (l+r)/2;
        cerr << "trying " << mid << endl;

        int bad = false;
        int j = n-mid+1;
        for(int i = 1; i <= mid; i++) {
            cerr << "match " << i << " w " << j << endl;
            if(a[j]-a[i] < z) {
                bad = true;
            }
            j++;
        }

        if(!bad) {
            lgood = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    cout << lgood << endl;
}

/*

observation: we always use leftmost and rightmost element
countercase:
z = 5
1 6 8 11

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
