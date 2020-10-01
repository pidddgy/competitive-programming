// https://codeforces.com/problemset/problem/733/C

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

const int maxn = 505;

int n, k;
int a[maxn], b[maxn];
int ind = 1;
int shift = 0;

void no() {
    cout << "NO" << endl;
    exit(0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> k;
    for(int i = 1; i <= k; i++) {
        cin >> b[i];
    }

    vector<pair<int, char>> ans;

    int l = 1;  
    while(l <= n) {
        int r = l;
        int sum = 0;
        bool found = false;
        for(;r <= n; r++) {
            sum += a[r];
            if(sum == b[ind]) {
                found = true;
                break;
            }
        }

        if(!found) no();

        cerr << "for " << ind << " we can use " << l << " " << r << endl;

        int st = -1;
        int ma = *max_element(a+l, a+r+1);
        for(int i = l; i <= r; i++) {
            bool ok = false;

            if(a[i] == ma) {
                if((i > l) and (a[i-1] < a[i])) {
                    ok = true;
                }

                if((i < r) and (a[i+1] < a[i])) {
                    ok = true;
                }
            }

            if(ok) {
                st = i;
            }
        }
        int reml = st-l, remr = r-st;
        
        if((st == -1) and (r != l)) no();

        if(r == l) reml = remr = 0;

        if(reml+remr) {
            // we add remr to shift later
            if((st > l) and (a[st-1] < a[st])) {
                for(int i = 1; i <= reml; i++) {
                    ans.emplace_back(st-shift, 'L');
                    shift++;
                }

                for(int i = 1; i <= remr; i++) {
                    ans.emplace_back(st-shift, 'R');
                }
            } else {
                for(int i = 1; i <= remr; i++) {
                    ans.emplace_back(st-shift, 'R');
                }

                for(int i = 1; i <= reml; i++) {
                    ans.emplace_back(st-shift, 'L');
                    shift++;
                }
            }
        }

        l = r+1;
        ind++;
        shift += remr;

        watch(shift)
    }

    if(ind != k+1) no();
    cout << "YES" << endl;
    for(auto x: ans) {
        cout << x.fi << " " << x.se << endl;
    }
}

/*

partition the array into segments that sum to respective values

for each segment of size N we need to find N-1 operations that compress the segment into 1 element
    take the biggest element and either go left or right

keep track of how far the whole thing shifted down

find biggest segment with any adjacent element less than current


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
