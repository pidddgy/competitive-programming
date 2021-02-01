// https://codeforces.com/contest/1311/problem/F

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

const int maxn = 400500;

int bitcnt[maxn];
int bitsum[maxn];

void upd(int arr[], int pos, int val) {
    for(int i = pos; i <= 4e5; i += i &-i) {
        arr[i] += val;
    }
}

int sum(int arr[], int pos) {
    int res = 0;
    for(int i = pos; i >= 1; i -= i & -i) {
        res += arr[i];
    }

    return res;
}

int query(int arr[], int l, int r) {
    return sum(arr, r)-sum(arr, l-1);
}

int n;
pii a[maxn];
map<int, int> cmp;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi;
    }

    vector<int> rel;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].se;
        rel.emplace_back(a[i].se);
    }

    sort(all(rel));

    int cur = 1;
    for(int i = 0; i < sz(rel); i++) {
        if(i == 0 or (i > 0 and rel[i-1] != rel[i])) {
            cmp[rel[i]] = cur;
            cur++;
        }
    }

    sort(a+1, a+n+1);

    int ans = 0;
    for(int i = 1; i <= n; i++) {

        // sum of all a[i].se with lesser speed
        int sum = query(bitsum, 1, cmp[a[i].se]);

        // count of all a[i] with lesser speed
        int cnt = query(bitcnt, 1, cmp[a[i].se]);

        int cont = cnt*a[i].fi - sum;

        cerr << i << endl;
        watch(sum)
        watch(cnt)
        cerr << endl;

        ans += cont;

        upd(bitcnt, cmp[a[i].se], 1);
        upd(bitsum, cmp[a[i].se], a[i].fi);
    }

    cout << ans << endl;
}

/*

for i in 1..n

all numbers to left of i that are greater than i are 0
for all numbers to left of i that are lesser than i, contribute i*cnt - sum

all numbers to right of i that are less than i are 0
for all numbers to right of i that are less than i, contribute i*cnt - sum


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
