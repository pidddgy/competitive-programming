// https://codeforces.com/problemset/problem/1430/E

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 200500;

int n;
int last[26], len[26];
vector<int> bit[26];

void upd(int letter, int pos, int val) {
    for(int i = pos; i <= len[letter]; i += (i & -i)) {
        bit[letter][i] += val;
    }
}

void updr(int letter, int l, int r, int val) {
    if(l > r) return;
    upd(letter, l, val);
    upd(letter, r+1, -val);
}

int psum(int letter, int upto) {
    int sum = 0;
    for(int i = upto; i >= 1; i -= (i&(-i))) {
        sum += bit[letter][i];
    }

    return sum;
}

int query(int letter, int l, int r) {
    return psum(letter, r) - psum(letter, l-1);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    for(char x: s) len[x-'a']++;

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j <= len[i]; j++) {
            bit[i].push_back(0);
        }
    }

    string need = s;
    reverse(all(need));
    s = "."+s;
    need = "."+need;

    map<char, int> cnt;
    for(int i = 1; i <= n; i++) {
        cnt[s[i]]++;
        int j = s[i]-'a';

        // cerr << "setting " << j << " " << cnt[s[i]] << " to " << i << endl;
        updr(j, cnt[s[i]], cnt[s[i]], i);
    }

    // watch(query(0, 2, 2))
    // for(int i = 1; i <= len[0]; i++) {
        // cerr << query(0, 1, i) << " ";
    // }
    // cerr << endl;

    // query 1, i for point query

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        // find index of next 
        int chr = need[i]-'a';
        int next = query(chr, 1, last[chr]+1);

        ans += next-i;

        cerr << "swap " << i << " w " << next << endl;

        for(int j = 0; j < 26; j++) {
            int incr = -1, decr = -1;
            int l = last[j];
            int r = len[j];

            while(l <= r) {
                int mid = (l+r)/2;

                if(query(j, 1, mid) >= i) {
                    incr = mid;
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }

            l = last[j], r = len[j];

            while(l <= r) {
                int mid = (l+r)/2;

                if(query(j, 1, mid) <= next-1) {
                    decr = mid;
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }

            if(incr != -1 and decr != -1) {
                cerr << "adding 1 to " << j << " " << incr << " " << decr << endl;
                updr(j, incr, decr, 1);
            }
        }

        last[chr]++;
    }

    cout << ans << endl;
}

/*


icpcsguru

uicpcsgru

never optimal to use a later character we need
for each letter keep track of the last index we used

binary indexed tree on each letter
swapping j to i increments all letters in between (i, j-1)

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?