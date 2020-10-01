// https://codeforces.com/contest/863/problem/C

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

int A[10][10], B[10][10];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int k, a, b;
    cin >> k >> a >> b;

    a--;
    b--;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> B[i][j];
            B[i][j]--;
        }
    }

    map<pii, int> used;
    vector<pii> scores;

    int aw = 0, bw = 0;
    while(k) {
        // cerr << "currently on " << a << " " << b << endl;
        if(used.count(pii(a, b))) {
            // cerr << "modding" << endl;
            int s1 = 0, s2 = 0;
            for(int i = used[pii(a, b)]; i < sz(scores); i++) {
                s1 += scores[i].fi;
                s2 += scores[i].se;
            }

            int cnt = k / (sz(scores) - used[pii(a, b)]);

            aw += s1 * cnt;
            bw += s2 * cnt;

            k %= (sz(scores) - used[pii(a, b)]);
            used.clear();
        } else {
            used[pii(a, b)] = sz(scores);

            if((b+1)%3 == a) {
                scores.emplace_back(1, 0);
            } else if((a+1)%3 == b) {
                scores.emplace_back(0, 1);
            } else {
                scores.emplace_back(0, 0);
            }

            aw += scores.back().fi;
            bw += scores.back().se;

            int na = A[a][b], nb = B[a][b];
            // cerr << "next is " << na << " " << nb << endl;

            a = na;
            b = nb;
            k--;
        }
    }

    cout << aw << " " << bw << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
