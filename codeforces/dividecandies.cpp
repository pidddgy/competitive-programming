// https://codeforces.com/contest/1056/problem/B

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define cerr if(false) cerr
bool sq(long double x) {   
  long double sr = sqrt(x); 
  return ((sr - floor(sr)) == 0); 
} 

int main() {
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int ans = 0;
    int can[m+1][m+1];
    int sumfull = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            if(((i*i)+(j*j)) % m == 0) {
                can[i][j] = 1;
                sumfull++;
            } else {
                can[i][j] = 0;
            }
        }
    }

    int upto = n%m;
    int fcols = 0;
    // sum of first n%m columns
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= upto; j++) {
            fcols += can[i][j];
        }
    }

    ans += fcols * (n/m);
    
    int frows = 0;
    // sum of first n%m rows
    for(int i = 1; i <= upto; i++) {
        for(int j = 1; j <= m; j++) {
            frows += can[i][j];
        }
    }

    ans += frows * (n/m);

    // sum of first n%m rows with n%m columns
    for(int i = 1; i <= upto; i++) {
        for(int j = 1; j <= upto; j++) {
            ans += can[i][j];
        }
    }

    ans += sumfull * (n/m) * (n/m);

    cout << ans << endl;
}