// https://ecoo.mcpt.ca/problem/ecoo20p3

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int N;
        cin >> N;

        int H, W;
        cin >> H >> W;

        char a[H+1][W+1];

        for(int i = 1; i <= H; i++) {
            for(int j = 1; j <= W; j++) {
                a[i][j] = '?';
            }
        }

        for(int i = 1; i <= H; i++) {
            string s;
            for(int j = 0; j < s.size(); j++) {
                a[i][j+1] = s[j];
            }
        }

        vector<int> nums;
        for(int i = 1; i <= W; i++) {
            bool valid = false;
            int cnt = 0;
            for(int j = 1; j <= H; j++) {
                if(a[i-1][j+1] == '*' or a[i-1][j-1] == '*') {
                    valid = true;
                }
                cnt += a[i][j]=='*';
            }

            if(valid) nums.emplace_back(cnt);
        }

        sort(nums.begin(), nums.end(), greater<int>());

        if(nums[0] == )

        
    }
}