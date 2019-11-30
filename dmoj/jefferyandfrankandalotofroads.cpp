// https://dmoj.ca/problem/vmss15c1p5

#include <bits/stdc++.h>
#define fi first
#define se second
#define marsv 1005
#define watch(x) cout << (#x) << " is " << (x) << endl;


using namespace std;

map<string, int> dp[marsv][marsv];

int main() {
    int N, R, S;
    cin >> N >> R >> S;

    // R -> money, S -> capacity

    // dp[i][j] = maximum val with i money and j capacity
    // also store string->int map

    map<string, int> values;
    map<int, string> names;
    for(int apple = 1; apple <= N; apple++) {
        string E;
        int V, A, B;
        cin >> E >> V >> A >> B;

        values[E] = V;
        names[apple] = E;
        // a -> money, b -> volume
        for(int i = 1; i <= R; i++) {
            for(int j = 1; j <= S; j++) {
                if((i-A >= 1 and j-B >= 1) or (i-A == 0 and j-B == 0)) 
                {
                    int val = 0;
                    int cur = 0;
                    map<string, int> temp;
                    for(auto x: dp[i-A][j-B]) {
                        val += values[x.fi]*(x.se);
                        temp[x.fi] += x.se;
                    }

                    for(auto x: dp[i][j]) {
                        cur += values[x.fi]*(x.se);
                    }

                    if(val+V > cur) {
                        dp[i][j].clear();
                        dp[i][j] = temp;
                        dp[i][j][E]++;
                    }

                }
            }
        }
    }

    int ans = 0;
    map<string, int> ans2;

    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= S; j++) {
            int val = 0;
            map<string, int> temp;
            for(int i = 1; i <= N; i++) {
                temp[names[i]] = 0;
            }
            for(auto x: dp[i][j]) {
                val += values[x.fi]*x.se;
                temp[x.fi] += x.se;
            }

            if(val > ans) {
                ans = val;
                ans2 = temp;
            }
        }
    }


    
    cout << ans << endl;

    for(auto x: ans2) {
        cout << x.fi << " " << x.se << endl;
    }

    
}