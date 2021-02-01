// https://codeforces.com/contest/1157/problem/F

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

int a[maxn];
int psa[maxn];
int bad[maxn];


int query(int arr[], int l, int r) {
    if(l > r) return 0;

    return arr[r]-arr[l-1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;    

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        a[x]++;
    }

    for(int i = 1; i <= 2e5; i++) {
        psa[i] += psa[i-1];
        psa[i] += a[i];

        bad[i] += bad[i-1];
        if(a[i] <= 1) bad[i]++;
    }

    pii p = {0, 0};
    int ma = 0;
    for(int i = 1; i <= 2e5; i++) {
        if(a[i] == 0) continue;

        int l = i;
        int r = 2e5;
        int lgood = -1;

        while(l <= r) {
            int mid = (l+r)/2;

            // bad
            if(query(bad, i+1, mid-1) or a[mid] == 0) {
                r = mid-1;
            } else {
                lgood = mid;
                l = mid+1;
            }
        }

        int loc = a[i] + query(psa, i+1, lgood-1);
        if(lgood != i) loc += a[lgood];

        if(loc > ma) {
            ma = loc;
            p = pii(i, lgood);
        }
    }

    cout << ma << endl;
    for(int i = p.fi; i <= p.se; i++) {
        cout << i << " ";
        a[i]--;
    }

    for(int i = p.se; i >= p.fi; i--) {
        while(a[i]) {
            cout << i << " ";
            a[i]--;
        }
    }
    cout << endl;
}

/*

get a contiguous segment

for any continuous segment, can we make a valid circle?

small cases
2 numbers are only valid if abs(a-b) <= 1
3 numbers are only valid if it is something like 111 or 121
4:
1232

question -> can we make a valid circle with more than one number that occurs only once?

add some numbers to 1234 that aren't 3 or 4 to make a valid circle

tentative: we go up and come back down. the peak and smallest element can occur only once



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
