// https://codeforces.com/contest/723/problem/C
    
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;

const int maxn = 3000;

unordered_map<int, int> cnt;
int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    int per = n/m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int ops = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] > m or (a[i] <= m and cnt[a[i]] > per)) {
            for(int j = 1; j <= m; j++) {
                if(cnt[j] < per) {
                    cnt[j]++;
                    cnt[a[i]]--;
                    a[i] = j;
                    ops++;
                    break;
                }
            }
        }
    }

    cout << per << " " << ops << endl;
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}