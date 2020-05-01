// https://codeforces.com/contest/1255/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
const int maxn = 100050;
bool vis[maxn];
set<int> arr[maxn];
set<int> appear[maxn];
int cnt[maxn];

int ans[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 1; i <= N-2; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        for(int x: {a, b, c}) {
            arr[i].emplace(x);
            appear[x].emplace(i);
            cnt[x]++;
        }
    }

    int cur = -1;
    for(int i = 1; i <= N; i++) {
        if(cnt[i] == 1) {
            cur = i;
            break;
        }
    }

    ans[1] = cur;

    for(int x: arr[*appear[cur].begin()]) {
        if(x == cur) continue;
        if(cnt[x] == 2) {
            ans[2] = x;
        } else {
            ans[3] = x;
        }
    }

    for(int i = 4; i <= N; i++) {
        for(int x: appear[ans[i-1]]) {
            set<int> s = arr[x];

            if(s.count(ans[i-1]) and s.count(ans[i-2]) and !s.count(ans[i-3])) {
                for(int y: s) {
                    if(y != ans[i-1] and y != ans[i-2]) {
                        ans[i] = y;
                    }
                }
                break;
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}