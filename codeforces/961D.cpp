// https://codeforces.com/contest/961/problem/D

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
int n;

pii a[maxn];

pii f(pii p1, pii p2) {
    int x = p1.fi - p2.fi;
    int y = p2.se - p1.se;

    int a = y;
    int b = x;

    cerr << a << " " << b << endl;

    int hugs = a*p1.fi + b*p1.se;
    int cute = a*p2.fi + b*p2.se;
    assert(hugs == cute);

    return pii(a, b);
}

bool go(int x, int y) {
    bool loc = true;
    pii tmp = f(a[x], a[y]);
    int c = tmp.fi*a[x].fi + tmp.se * a[x].se;

    cerr << "putting " << x << " w " << y << " gives " << tmp.fi << " " << tmp.se << " = " << c << endl;

    bool ok = true;

    vector<int> rem;
    for(int i = 1; i <= n; i++) {
        pii p = a[i];
        if(tmp.fi*p.fi + tmp.se*p.se != c) {
            rem.emplace_back(i);
        }
    }

    cerr << "rem is: " << endl;
    for(int x: rem) {
        cerr << x << " ";
    }
    cerr << endl;

    if(sz(rem) >= 2) {
        tmp = f(a[rem[0]], a[rem[1]]);
        c = tmp.fi*a[rem[0]].fi + tmp.se*a[rem[0]].se;

        for(int x: rem) {
            if(tmp.fi*a[x].fi + tmp.se*a[x].se != c) {
                ok = false;
            }
        }
    }

    return ok;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // f(pii(2, 2), pii(3, 4));
    // f(pii(1, 5), pii(1, 8));
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 mt(seed);

    cin >> n;

    if(n <= 4) {
        cout << "YES" << endl;
        return 0;
    }

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    bool ans = false;

    for(int xd = 1; xd <= 500; xd++) {
        int i = mt()%n+1;
        int j = i;

        while(i==j) {
            j = mt()%n+1;
        }


        if(go(i, j)) {
            cerr << i << " " << j << " works " << endl;
            ans = true;
            break;
        } 
    }



    if(ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

/*

two lines

slap two pairs of coefficients of a, b so that ax + by = at most 2 c's

a = (2, 2)
b = (3, 4)

2a + 2b = 3a + 4b
2b = 1a + 4b
1a = 2b

0 = a+2b

-a = 2b

xa = yb

set a = y so that there will be a factor

a = 6
b = -3

a = (1, 4)
b = (1, 7)

1a + 4b = 1a + 7b

0a = 3b

a = 3

0*3 / 3


fix 1, put it on the same line as 2
join all possible, we have rem remaining

try to use rem

next, put 1 with any point in rem

try the case where 1 is alone

pick random shit and pray

there is 1/2 chance of failure on each pick


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
