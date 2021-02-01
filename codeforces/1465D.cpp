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

int n;
string s;

int ans = 1e18;
int x, y;

int go(string t) {
    cerr << "trying " << t << endl;
    int res = 0;
    vector<int> cnt(2);
    for(char c: t) {
        if(c == '1') res += cnt[0]*x;
        else res += cnt[1]*y;

        cnt[c-'0']++;
    }

    return res;
}

string get(int split, string chrs) {
    string res = s;
    for(int i = 0; i <= split; i++) {
        if(s[i] == '?') res[i] = chrs[0];
    }

    for(int i = split+1; i < n; i++) {
        if(s[i] == '?') res[i] = chrs[1];
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    n = sz(s);
    cin >> x >> y;

    int l = -1, r = n-1;
    int ans = 1e18;

    // 0...1
    while(l <= r) {
        int mid = (l+r)/2;

        int c1 = go(get(mid, "01"));
        int c2 = go(get(mid+1, "01"));

        if(c1 < c2) {
            ans = min(ans, c2);
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    l = -1, r = n-1;
    // 1..0
    while(l <= r) {
        int mid = (l+r)/2;
        cerr << "mid is " << mid << endl;

        int c1 = go(get(mid, "10"));
        int c2 = go(get(mid+1, "10"));

        if(c1 < c2) {
            ans = min(ans, c2);
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    l = -1, r = n-1;
    while(l <= r) {
        int mid = (l+r)/2;

        int c1 = go(get(mid, "01"));
        int c2 = go(get(mid+1, "01"));

        if(c1 <= c2) {
            ans = min(ans, c2);
            l = mid+1;
        } else {
            r = mid-1;
        }
    }



    l = -1, r = n-1;
    // 1..0
    while(l <= r) {
        int mid = (l+r)/2;
        cerr << "mid is " << mid << endl;

        int c1 = go(get(mid, "10"));
        int c2 = go(get(mid+1, "10"));

        if(c1 <= c2) {
            ans = min(ans, c2);
            l = mid+1;
        } else {
            r = mid-1;
        }
    }


    

    string ree = s;
    for(int i = 0; i < n; i++) {
        if(s[i] == '?') ree[i] = '0';
    }

    ans = min(ans, go(ree));
for(int i = 0; i < n; i++) {
        if(s[i] == '?') ree[i] = '1';
    }
    ans = min(ans, go(ree));


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