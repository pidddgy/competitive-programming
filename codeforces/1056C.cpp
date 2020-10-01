// https://codeforces.com/contest/1056/problem/C

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

const int maxn = (int)1e3+5;

int n, m;
int p[2*maxn], G[2*maxn];
bool used[2*maxn];

signed main() {
    cin >> n >> m;

    for(int i = 1; i <= 2*n; i++) {
        cin >> p[i];
    }

    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        G[a] = b;
        G[b] = a;
    }

    int t;
    cin >> t;

    t--;

    int last = 0;
    for(int i = 1; i <= 2*n; i++) {
        watch(i)
        watch(t)
        // if our turn
        if(t == 0) {
            cerr << "our turn" << endl;
            if(G[last] and last != 0 and !used[G[last]]) {
                cerr << "a" << endl;
                cout << G[last] << endl;
                used[G[last]] = true;
                last = G[last];
            } else {
                cerr << "b" << endl;
                bool found = false;
                for(int j = 1; j <= 2*n; j++) {
                    if(G[j] and !used[j] and !used[G[j]]) {
                        pii take = {0, 0};

                        take = max(take, pii(p[j], j));
                        take = max(take, pii(p[G[j]], G[j]));

                        cerr << "using a pair" << endl;
                        used[take.se] = true;
                        cout << take.se << endl;
                        found = true;
                        break;
                    }
                }

                if(!found) {
                    pii take = {0, 0};
                    for(int j = 1; j <= 2*n; j++) {
                        if(!used[j]) {
                            take = max(take, pii(p[j], j));
                        }
                    }

                    used[take.se] = true;
                    last = take.se;
                    cout << take.se << endl;
                }
            }
        } else {
            int x;
            cin >> x;

            if(x == -1) exit(0);

            used[x] = true;
            last = x;
        }

        t ^= 1;
        cerr << endl;
    }
}

/*

if opponent used some element part of a pair we have no choice but to take the corresponding element

if we have the chance to make any move we should exhaust all the pairs, taking the biggest possible

if an optimal solution requires us to take a smaller part of a pair, we can exchange that smaller part while having no impact
once all the pairs are exhausted, it's obviously better to just take whatever biggest element is not taken



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
