// https://codeforces.com/contest/818/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 100500;
const int maxc = 1000500;
int a[maxn], cnt[maxc];
bool bad[maxc];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, A;
    cin >> n >> A;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    bad[A] = true;

    for(int i = 1; i <= n; i++) {
        if(a[i] == A) {
            cnt[A]++;
        } else {
            int c = a[i];
            if(cnt[c] < cnt[A]) {
                bad[c] = true;
            }

            cnt[c]++;
        }
    }

    for(int i = 1; i <= 1e6; i++) {
        if(!bad[i] and cnt[i] >= cnt[A]) {
            cout << i << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
}
