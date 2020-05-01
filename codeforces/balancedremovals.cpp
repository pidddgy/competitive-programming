// https://codeforces.com/contest/1237/problem/C1

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define pvii pair<vector<int>, int>
#define fi first
#define se second
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    deque<vi> dq;

    int N;
    cin >> N;

    bool used[N+1];
    vi arr[N+1];
    for(int i = 1; i <= N; i++) {
        used[i] = false;
        int a, b, c;
        cin >> a >> b >> c;

        vi load = {a, b, c};
        arr[i] = load;
    }

    vector<pii> ans;
    for(int i = 1; i <= N; i++) {
        int rem = -1;
        for(int j = i; j <= N; j++) {
            if(i == j) continue;
            if(used[i] or used[j]) continue;

            if(rem == -1) {
                rem = j;
                continue;
            }

            vi a = arr[i];
            vi b = arr[rem];

            vi c = arr[j];

            bool inside = true;
            for(int k = 0; k < 3;k++) {
                int mi = min(a[k], b[k]);
                int ma = max(a[k], b[k]);

                if(!(mi <= c[k] and c[k] <= ma)) {
                    inside = false;
                }
            }

            if(inside) rem = j;
        }
        if(rem != -1) {
            used[i] = true;
            used[rem] = true;
            ans.emplace_back(i, rem);
            if(ans.size() == N/2) break;
        }
    }

    for(pii x: ans) {
        cout << x.fi << " " << x.se << endl;
    }

}