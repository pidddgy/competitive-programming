// https://dmoj.ca/problem/dpj

#include <bits/stdc++.h>
#define ld long double
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define pb push_back
using namespace std;

int N;
vector<vector<ld>> dp(1000); // each elem in dp[i] is a possible probability of sushi i
map<vector<int>, vector<vector<ld>>> vis;
int sushi = 0;

// s = state
// cur = current fish #
// fills dp
void f(vector<int> s, int cur) {
    if(cur > sushi) return;
    if(vis.find(s) != vis.end()) {
        for(int i = 0; i < 1000; i++) {
            for(int j = 0; j < vis[s][i].size(); i++) {
                dp[i].push_back(vis[s][i][j]);
            }
        }
    } 

    ld nz = 0;
    for(int i = 1; i <= N; i++) {
        if(s[i] != 0) nz++;
    }
    ld prob = nz/N;
    dp[cur].pb(prob);
    vector<int> news(s);

    vector<vector<ld>> old = dp;
    
    for(int i = 1; i <= N; i++) {
        if(news[i] != 0) {
            news[i]--;
            f(news, cur+1);
            news[i]++;
        }
    }

    vector<vector<ld>> diff(1000);
    for(int i = 0; i < 1000; i++) {
        for(int j = old[i].size(); j < dp[i].size(); j++) {
            diff[i].emplace_back(dp[i][j]);
        }
    }


    vis[s] = diff;
    
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<int> a(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        sushi += a[i];
    }

    f(a, 1);
    ld ans = 0;
    for(int i = 1; i <= sushi; i++) {
        ld avg = 0;
        for(ld j: dp[i]) {
            avg += 1/j;
        }
        ld exp = avg / dp[i].size();
        ans += exp;
    }
    cout << ans << endl;
}