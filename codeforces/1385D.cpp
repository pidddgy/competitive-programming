// https://codeforces.com/contest/1385/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long

#define all(x) (x).begin(), (x).end()

const string ALPHA = "abcdefghijklmnopqrstuvwxyz";
int n;
string s;

int len(int shit, int shit2) {
    return shit2-shit+1;
}

int psa[200][150000];

int query(int l, int r, char chr) {
    return psa[chr][r] - psa[chr][l-1];
}

int f(int l, int r, char chr) {

    if(l == r) {
        if(s[l] == chr) {
            return 0;
        } else {
            return 1;
        }
    }

    int m = (l+r)/2;
    
    char next = chr+1;
    int left = 0;
    left += len(l, m) - query(l, m, chr);
    left += f(m+1, r, next);

    // make right all chr
    int right = 0;
    right += len(m+1, r) - query(m+1, r, chr);
    right += f(l, m, next);

    return min(left, right);
}


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> s;
        s = "."+s;

        for(int i = 1; i <= n; i++) {
            psa[s[i]][i]++;
        }

        for(char x: ALPHA) {
            for(int j = 1; j <= n; j++) {
                psa[x][j] += psa[x][j-1];
            }
        }
    
        cout << f(1, n, 'a') << endl;

        for(char x: ALPHA) {
            for(int i = 0; i <= n; i++) {
                psa[x][i] = 0;
            }
        }
    }    
}