// https://codeforces.com/contest/1129/problem/A1

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;

    vector<int> candies[n+1];

    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        candies[a].emplace_back(b);
    }

    for(int st = 1; st <= n; st++) {
        cerr << "currently started from " << st << endl;
        unordered_map<int, int> stored;
        int i = st;
        int lastCandy = 0;
        int ans = 0;

        while(true) {
            cerr << "currently on " << i << endl;
            int best = INT_MAX;
            int bestind;
            int eraseInd;
            for(int j = 0; j < candies[i].size(); j++) {
                int x = candies[i][j];
                int dis = 0;
                if(i < x) {
                    dis = x-i;
                } else {
                    dis = n-x-i;
                }

                if(dis < best) {
                    bestind = x;
                    best = dis;
                    eraseInd = j;
                }
            }

            cerr << "h" << endl;
            candies[i].erase(candies[i].begin()+eraseInd);
            cerr << "l" << endl;
            // deliver to bestind
            if(best == INT_MAX) {
                // dont pick up
            } else {
                cerr << "emplacing " << bestind << endl;
                stored[bestind] ++;
            }

            for(pii x: stored) {
                if(x.fi == i) {
                    cout << "delivering " <<x.fi << " to " << x.fi << endl;
                    stored[x.fi] = 0;
                }
            }
            
            bool noneLeft = true;
            for(int x: candies[i]) {
                if(candies[i].size()) noneLeft = false;
            }
            
            i++;
            ans++;
            if(i == n+1) i = 1;

            if(noneLeft) lastCandy++;
            else lastCandy = 0;

            
            if(lastCandy >= n) break;
        }
        cout << ans << endl;
        cerr << endl;
    }
    cout << endl;
}