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

const int maxn = 2000;
const int maxm = 55;

char a[maxn][maxm];
int n, m;

int ree[26][26][26];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("cownomics.in", "r", stdin); 
    freopen("cownomics.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= 2*n; i++) {
        string s;
        cin >> s;

        for(int j = 1; j <= m; j++) {
            a[i][j] = s[j-1];
        }
    }

    int ans = 0;
    int shit = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = i+1; j <= m; j++) {
            for(int k = j+1; k <= m; k++) {
                
                shit++;
                for(int l = 1; l <= n; l++) {
                    string emp;
                    ree[a[l][i]-'A'][a[l][j]-'A'][a[l][k]-'A'] = shit;
                    // emp += a[l][i];
                    // emp += a[l][j];
                    // emp += a[l][k];


                    // S.emplace(emp);
                }

                int add = 1;
                for(int l = n+1; l <= 2*n; l++) {
                    if(ree[a[l][i]-'A'][a[l][j]-'A'][a[l][k]-'A'] == shit) add = 0;
                }

                ans += add;
            }
        }
    }

    cout << ans << endl;
}

/*
62 500 000

64 000 000
for any to be completely inside another, go up, down, left, right
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
