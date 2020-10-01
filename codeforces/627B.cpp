// https://codeforces.com/contest/627/problem/B

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
int N, K, A, B, Q;

int cnt[maxn];
int bita[maxn], bitb[maxn];

void upd(int arr[], int ind, int val) {
    for(int i = ind; i <= N; i += (i & (-i))) {
        arr[i] += val;
    }
}

int query(int arr[], int l, int r) {
    int x = 0;
    for(int i = l-1; i >= 1; i -= (i & (-i))) {
        x += arr[i];
    }

    int y = 0;
    for(int i = r; i >= 1; i -= (i & (-i))) {
        y += arr[i];
    }

    return y-x;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K >> A >> B >> Q;

    while(Q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int d, a;
            cin >> d >> a;

            int cpy = cnt[d];
            cnt[d] += a;

            upd(bita, d, min(A, cnt[d]) - min(A, cpy));
            upd(bitb, d, min(B, cnt[d]) - min(B, cpy));

            for(int i = 1; i <= N; i++) {
                cerr << cnt[i] << " ";
            }
            cerr << endl;
        } else if(t == 2) {
            int p;
            cin >> p;

            int ans = query(bitb, 1, p-1) + query(bita, p+K, N);

            cout << ans << endl;
        }
    }    
}

/*
have two fenwick trees, one of which is max'ed with a and the other maxed with b

when updating, take copy of old element in array and udpate with difference of new
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
