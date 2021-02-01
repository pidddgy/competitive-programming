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
int ans = 0;
int fac[19];
int cnt[10];
int state[10];

void f(int cur) {
    if(cur == 10) {
        int dig = 0;
        for(int i = 0; i <= 9; i++) {
            dig += state[i];
            cerr << state[i] << " ";
        }
        cerr << endl;

        int cum = 0;
        for(int i = 1; i <= 9; i++) {
            if(state[i]) {
                cerr << "can use " << i << " in first" << endl;
                state[i]--;
                int loc = fac[dig-1];
                for(int j = 0; j <= 9; j++) {
                    if(state[j])
                    loc /= fac[state[j]];
                }

                cum += loc;
                state[i]++;
            }
        }

        ans += cum;
        return;
    }

    if(cnt[cur] == 0) f(cur+1);

    for(int i = 1; i <= cnt[cur]; i++) {
        state[cur]++;
        f(cur+1);
    }
    state[cur] = 0;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fac[0] = 1;
    fac[1] = 1;
    for(int i  =2; i <= 18; i++) {
        fac[i] = fac[i-1]*i;
    }

    cin >> s;
    n = sz(s);

    for(char x: s) {
        cnt[x-'0']++;
    }

    f(0);

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
