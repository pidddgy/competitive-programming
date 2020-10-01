// https://codeforces.com/contest/1202/problem/B

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

string s;
int cost[15][15];

void clear() {
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++) {
            cost[i][j] = INT_MAX;
        }
    }
}

int solve(int r, int c) {
    cerr << "solving for " << r << " " << c << endl;
    for(int st = 0; st <= 9; st++) {
        for(int i = 0; i <= 10; i++) {
            for(int j = 0; j <= 10; j++) {
                if(i == 0 and j == 0) continue;
                int d = (st + (r*i) + (c*j))%10;
                cost[st][d] = min(cost[st][d], i+j);
            }
        }
    }

    int ans = 0LL;
    for(int i = 0; i < s.size()-1; i++) {
        int a = s[i]-'0', b = s[i+1]-'0';

        if(cost[a][b] == INT_MAX) return -1;
        ans += cost[a][b]-1;
    }

    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    for(int i = 0; i <= 9; i++) {
        for(int j = 0; j <= 9; j++) {
            clear();
            cout << solve(i, j) << " ";
        }
        cout << endl;
    }
}
