// https://codeforces.com/contest/965/problem/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
// #define cerr cout
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

const int maxw = 300500;

int w, l;
int a[maxw];
int b[maxw];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> l;

    for(int i = 1; i <= w-1; i++) {
        cin >> a[i];
    }
    a[w] = INT_MAX;

    for(int i = 1; i <= l; i++) {
        b[i] = a[i];
    }

    int i=1;
    while(i <= w-1) {
        int r = i+l-1;

        if(r >= w) break;

        int l2 = i+l;
        int r2 = min(w, i+l+l-1);

        cerr << i << "," << r << " " << l2 << "," << r2 << endl;
        for(int j = 1; j <= w; j++) {
            cerr << a[j];
            if(j%l == 0) cerr << " ";
        }
        cerr << endl;

        for(int j = 1; j <= w; j++) {
            cerr << b[j];
            if(j%l == 0) cerr << " ";
        }
        cerr << endl;

        int cur = r;

        for(int j = r2; j >= l2; j--) {
            for(;;) {
                bool change = false;
                while(cur > i and !b[cur]) {
                    cur--;
                }

                if(cur >= i and (j-cur) <= l and b[cur] and b[j] < a[j]) {
                    int take = min(b[cur], a[j]-b[j]);
                    b[j] += take;
                    b[cur] -= take;
                    change = true;
                }

                if(!change) break;
            }   
        }

        int p1 = l2;
        int p2 = r2;

        while(p1 < p2) {
            while(!b[p1]) p1++;
            while(b[p2] == a[p2]) p2--;

            if(p1 >= p2) break;

            int take = min(b[p1], a[p2]-b[p2]);

            b[p1] -= take;
            b[p2] += take;
        }

        for(int j = i; j <= r; j++) b[j] = 0;
        
        if(r2 > w-1) break;
        i += l;
    }

    int ans = 0;
    for(int j = 0; j < maxw; j++) {
        ans += b[j];
    }

    cout << ans << endl;
}

/*

divide into chunks of size k, only use one from each chunk

better to go as far up as possible

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?