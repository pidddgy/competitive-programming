// https://mcpt.ca/problem/lcc20c1s3

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

// struct ip {
//     int a, b, c, d;

//     ip(int aa, int bb, int cc, int dd) {
//         a = aa;
//         b = bb;
//         c = cc;
//         d = dd;
//     }
// };

// struct Compare {
//     bool operator()(ip &x, ip &y) {
//         if(x.a < y.a) return true;
//         if(x.a == y.a and x.b < y.b) return true;
//         if(x.a == y.a and x.b == y.b and x.c < y.c) return true;
//         if(x.a == y.a and x.b == y.b and x.c == y.c and x.d < y.d) return true;

//         return false;
//     }
// };

int n, m;
pair<vector<int>, vector<int>> bad[maxn];
vector<int> a[maxn];

struct Compare {
    bool operator()(vector<int> &l, vector<int> &r) {
        return lexicographical_compare(all(l), all(r));
    }
};

void pr(vector<int> v) {
    for(int x: v) cout << x << " ";
    cout << endl;
}

// difference array
int d[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        int j = 0;
        string cur;
        for(; j < sz(s); j++) {
            if(s[j] == '.') {
                bad[i].fi.push_back(stoi(cur));
                cur = "";
            } else if(s[j] == '-') {
                break;
            } else {
                cur += s[j];
            }
        }

        bad[i].fi.push_back(stoi(cur));
        cur = "";
        j++;

        for(; j < sz(s); j++) {
            if(s[j] == '.') {
                bad[i].se.push_back(stoi(cur));
                cur = "";
            } else if(s[j] == '-') {
                break;
            } else {
                cur += s[j];
            }
        }
        bad[i].se.push_back(stoi(cur));
        cur = "";

        // watch(sz(bad[i].fi))
        // for(int j = 0; j < 4; j++) {
        //     cout << bad[i].fi[j] << " ";
        // }
        // cout << endl;

        // for(int j = 0; j < 4; j++) {
        //     cout << bad[i].se[j] << " ";
        // }
        // cout << endl;
    }

    for(int i = 1; i <= m; i++) {
        string s;
        cin >> s;

        int j = 0;
        string cur;
        for(; j < sz(s); j++) {
            if(s[j] == '.') {
                a[i].push_back(stoi(cur));
                cur = "";
            } else if(s[j] == '-') {
                break;
            } else {
                cur += s[j];
            }
        }
        a[i].push_back(stoi(cur));
    }

    sort(a+1, a+m+1, Compare());

    // for(int i = 1; i <= m; i++) {
    //     pr(a[i]);
    // }


    for(int i = 1; i <= n; i++) {
        int left = -1;
        int l = 1;
        int r = m;

        while(l <= r) {
            int mid = (l+r)/2;
            // make sure bad[i].fi <= a[mid]
            // second case handles equal to b/c lexicographical_compare only returns true if strictly less than
            if((lexicographical_compare(all(bad[i].fi), all(a[mid])) or a[mid] == bad[i].fi)) {
                left = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        int right = -1;
        l = 1;
        r = m;

        while(l <= r) {
            int mid = (l+r)/2;

            // make sure bad[i].se <= a[mid]
            if( lexicographical_compare(all(a[mid]), all(bad[i].se)) or a[mid] == bad[i].se) {
                right = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        // cerr << left << " " << right << endl;
        if(left <= right and left != -1 and right != -1) {
            d[left]++;
            d[right+1]--;
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; i++) {
        d[i] += d[i-1];
        if(d[i] > 0) ans++;
    }

    cout << ans << endl;
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
