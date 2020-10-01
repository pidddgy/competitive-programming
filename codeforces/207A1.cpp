// https://codeforces.com/contest/207/problem/A1

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int unsigned long long
#define pii pair<int, int>
#define fi first
#define se second

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int k[n+1], a[n+1], x[n+1], y[n+1], m[n+1];

    for(int i = 1; i <= n; i++) {
        cin >> k[i] >> a[i] >> x[i] >> y[i] >> m[i];
    }

    queue<int> cost[19];
    for(int i = 1; i <= n; i++) {
        cost[i].push(a[i]);
        for(int j = 2; j <= k[i]; j++) {
            int b = cost[i].back();
            cost[i].push(((b*x[i])+y[i]) % m[i]);
        }
    }

    int bad = 0;
    vector<pii> ans;
    while(cost[1].size() or cost[2].size()) {
        if(cost[1].empty()) {
            if(ans.size()) {
                if(ans.back().fi > cost[2].front()) {
                    bad++;
                }
            }

            ans.emplace_back(cost[2].front(), 2);
            cost[2].pop();
            continue;
        }

        if(cost[2].empty()) {
            if(ans.size()) {
                if(ans.back().fi > cost[1].front()) {
                    bad++;
                }
            }

            ans.emplace_back(cost[1].front(), 1);
            cost[1].pop();
            continue;
        }
        if(cost[1].front() < cost[2].front()) {
            if(ans.size()) {
                if(ans.back().fi > cost[1].front()) {
                    if(cost[2].size()) {
                        if(ans.back().fi <= cost[2].front()) {
                            ans.emplace_back(cost[2].front(), 2);
                            cost[2].pop();
                            continue;
                        }
                    }
                    bad++;
                }
            }

            ans.emplace_back(cost[1].front(), 1);
            cost[1].pop();
        } else {
            if(ans.size()) {
                if(ans.back().fi > cost[2].front()) {
                    if(cost[1].size()) {
                        if(ans.back().fi <= cost[1].front()) {
                            ans.emplace_back(cost[1].front(), 1);
                            cost[1].pop();
                            continue;
                        }
                    }
                    bad++;
                }
            }

            ans.emplace_back(cost[2].front(), 2);
            cost[2].pop();
        }
    }

    cout << bad << endl;
    for(pii x: ans) {
        cout << x.fi << " " << x.se << endl;
    }
}