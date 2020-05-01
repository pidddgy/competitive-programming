// https://codeforces.com/contest/1027/problem/C

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    #define endl '\n'
    #define int long long
    #define ld long double

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        unordered_map<int, int> cnt;
        unordered_map<int, bool> seen;    
        vector<int> unums;

        for(int i = 1; i <= N; i++) {
            int a;
            cin >> a;

            cnt[a]++;

            if(cnt[a] == 2) {
                unums.emplace_back(a);
            }
        }

        sort(unums.begin(), unums.end());

        ld best = INT_MAX;
        int l1;
        int l2;
        for(int i = 0; i < unums.size(); i++) {
            if(i+1 < unums.size())
            if(cnt[unums[i]] >= 2 and cnt[unums[i+1]] >= 2) {
                ld p = pow((unums[i]*2) + (unums[i+1]*2), 2.0);
                ld S = unums[i] * unums[i+1];
                if(p/S < best) {
                    l1 = unums[i];
                    l2 = unums[i+1];
                    best = p/S;
                }
            }

            if(cnt[unums[i]] >= 4) {
                int p = unums[i]*4;
                int S = unums[i]*2;

                if(p/S < best) {
                    l1 = unums[i];
                    l2 = unums[i];
                    best = p/S;
                }
            }
        }

        cout << l1 << " " << l1 << " " << l2 << " " << l2 << endl;
    }
}