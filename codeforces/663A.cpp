// https://codeforces.com/contest/663/problem/A

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = (int)1e6+13;
const int maxq = 105;

bool isnum(string s) {
    for(char x: s) {
        int v = x-'0';

        if(!(0 <= v and v <= 9)) {
            return false;
        }
    }

    return true;
}


int ans[maxq];
char sign[maxq];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int q = 0;

    sign[1] = '+';
    for(;;) {
        string s;
        cin >> s;

        if(s == "?") {
            q++;
        }

        if(isnum(s)) {
            n = stoi(s);
            break;
        } else {
            sign[q+1] = s[0];
        }
    }

    vector<int> add, sub;
    for(int i = 1; i <= q; i++) {
        if(sign[i] == '+') {
            cerr << i << " is add" << endl;
            add.emplace_back(i);
        } else {
            cerr << i << " is sub" << endl;
            sub.emplace_back(i);
        }
    }

    int sum = 0;
    for(int x: sub) {
        ans[x] = n;
        sum -= n;
    }

    for(int x: add) {
        ans[x] = 1;
        sum++;
    }

    for(int x: add) {
        int take = max(0, min(n-ans[x], n-sum));

        ans[x] += take;
        sum += take;

        if(sum == n) break;
    }

    for(int x: sub) {
        int take = min(ans[x]-1, n-sum);

        ans[x] -= take;
        sum += take;

        if(sum == n) break;
    }

    for(int i = 1; i <= q; i++) {
        if(ans[i] < 1 or ans[i] > n) {
            cout << "Impossible" << endl;
            exit(0);
        }
    }
    
    if(sum != n) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
        cout << ans[1] << " ";
        for(int i = 2; i <= q; i++) {
            cout << sign[i] << " " << ans[i] << " ";
        }
        cout << "= " << n << endl;
    }
}

/*

start from minimum sum and go as far up as possible
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?