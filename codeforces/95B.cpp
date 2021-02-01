// https://codeforces.com/contest/95/problem/B

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

// print 444.....777...... with some digit
void f(int len) {
    assert(len % 2 == 0);

    for(int i = 1; i <= len/2; i++) {
        cout << 4;
    }

    for(int i = 1; i <= len/2; i++) {
        cout << 7;
    }
    cout << endl;
    exit(0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    if(sz(s) % 2) {
        f(sz(s)+1);
    }

    map<char, int> cnt;
    for(char x: s) {
        cnt[x-'0']++;
    }

    if((cnt[4] == cnt[7]) and (cnt[4]+cnt[7] == sz(s))) {
        cout << s << endl;
        return 0;
    }

    if((s[0]-'0') > 7) {
        f(sz(s)+2);
    }

    // cnt now represents number of 4/7 remaining
    cnt.clear();
    cnt[4] = sz(s)/2;
    cnt[7] = sz(s)/2;

    bool o = false;
    string ans;
    for(int i = 0; i < sz(s)-1; i++) {
        if(o) {
            if(cnt[4]) {
                ans += '4';
                cnt[4]--;
            } else {
                ans += '7';
                cnt[7]--;
            }
            continue;
        } else if(cnt[4] and (4 >= (s[i]-'0'))) {
            bool nxto = o | (4 > (s[i]-'0'));
            int need = 4;
            if((s[i+1]-'0') > 4) need = 7;
            
            watch(need)
            int have = cnt[need];
            if(need == 4) have--;

            if(!have) {
                need = 7;
            }

            if((s[i+1]-'0') >= 7) need = INT_MAX;

            have = cnt[need];
            watch(have)

            if(nxto or have) {
                ans += '4';
                cnt[4]--;
                if(4 > (s[i]-'0')) o = true;

                continue;
            }   
        }

        if(cnt[7]) {
            ans += '7';
            cnt[7]--;
        } else f(sz(s)+2);

        if(7 > (s[i]-'0')) o = true;
        if(7 < (s[i]-'0') and !o) {
            watch(ans)
            cerr << "failed" << endl;
            f(sz(s)+2);
        }
    }

    watch(ans)
    int last;
    if(cnt[4]) last = 4;
    else last = 7;

    if(last < (s.back()-'0') and !o) {
        f(sz(s)+2);
    }

    ans += (last+'0');

    cout << ans << endl;
}

/*

if odd then just print whatever with even+1 digits
also check if number itself is lucky

observation: we should always keep the ability to go over if we haven't used it

if we ever lose the ability to go over 



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
