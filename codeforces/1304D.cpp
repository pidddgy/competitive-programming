// https://codeforces.com/contest/1304/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 2*1e5+500;
int n;
string s;
int ans[maxn];
void read() {
    cin >> n >> s;
    s = "."+s;
}

void solveMin() {
    for(int i = 1; i <= n; i++) {
        ans[i] = n-i+1;
    }

    for(int i = 1; i <= n-1; i++) {
        if(s[i] == '<') {
            int j = i;
            for(; j <= n-1; j++) {
                if(s[j] == '>') break;
            }

            reverse(ans+i, ans+j+1);
            i = j;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

void solveMax() {
    for(int i = 1; i <= n; i++) {
        ans[i] = i;
    }

    for(int i = 1; i <= n-1; i++) {
        if(s[i] == '>') {
            int j = i;
            for(; j <= n-1; j++) {
                if(s[j] == '<') break;
            }

            reverse(ans+i, ans+j+1);
            i = j;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        read();
        solveMin();
        solveMax();
    }
}
