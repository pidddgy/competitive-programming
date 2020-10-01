// https://codeforces.com/contest/568/problem/A

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

bool prime[(int)1e7];
int d[15];

bool palindrome(int x) {
	int cnt = 0;
	while(x) {
        d[++cnt] = x%10;
        x /= 10;
    }

	for(int i = 1; i <= cnt / 2 ; i++) {
        if(d[i] != d[cnt+1-i]) {
            return false;
        }
    }
    return true;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 2; i <= 1e7; i++) {
        prime[i] = true;
    }

    for(int i = 2; i <= 1e7; i++) {
        if(prime[i]) {
            for(int j = i*i; j <= 1e7; j += i) {
                prime[j] = false;
            }
        }
    }


    int p, q;
    cin >> p >> q;

    int ta = 0, pal = 0;
    int ans = 0;
    
    for(int i = 1; i <= 1e7; i++) {
        if(palindrome(i)) pal++;

        if(prime[i]) ta++;

        // cerr << i << " " << ta << "," << pal << endl;

        if(ta <= (pal*p)/q) {
            ans = i;
        }
    }

    if(ans == 0) {
        cout << "Palindromic tree is better than splay tree" << endl;
    } else {
        cout << ans << endl;        
    }
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
